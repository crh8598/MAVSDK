//
// Simple example to demonstrate how to use the MAVSDK.
//
// Author: Julian Oes <julian@oes.ch>

#include <chrono>
#include <cstdint>
#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <mavsdk/plugins/mission/mission.h>
#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include <math.h>

using namespace mavsdk;

#define ERROR_CONSOLE_TEXT "\033[31m" // Turn text on console red
#define TELEMETRY_CONSOLE_TEXT "\033[34m" // Turn text on console blue
#define NORMAL_CONSOLE_TEXT "\033[0m" // Restore normal console colour
// #define M_PI 3.14159265359

void usage(std::string bin_name)
{
    std::cout << NORMAL_CONSOLE_TEXT << "Usage : " << bin_name << " <connection_url>" << std::endl
              << "Connection URL format should be :" << std::endl
              << " For TCP : tcp://[server_host][:server_port]" << std::endl
              << " For UDP : udp://[bind_host][:bind_port]" << std::endl
              << " For Serial : serial:///path/to/serial/dev[:baudrate]" << std::endl
              << "For example, to connect to the simulator use URL: udp://:14540" << std::endl;
}

void component_discovered(ComponentType component_type)
{
    std::cout << NORMAL_CONSOLE_TEXT << "Discovered a component with type "
              << unsigned(component_type) << std::endl;
}

// mission을 생성하는 함수 선언
static Mission::MissionItem make_mission_item(
    double latitude_deg, double longitude_deg,float relative_altitude_m,float speed_m_s, 
    bool is_fly_through, float gimbal_pitch_deg,float gimbal_yaw_deg, Mission::MissionItem::CameraAction camera_action);
inline void handle_action_err_exit(Action::Result result, const std::string& message);
inline void handle_mission_err_exit(Mission::Result result, const std::string& message);
inline void handle_connection_err_exit(ConnectionResult result, const std::string& message);
void half_circle(std::vector<Mission::MissionItem> &mission_items,int mis_num,double deg, double radius,double longitude, double latitude);
void make_mission_point(std::vector<Mission::MissionItem> &mission_items, double x, double y);


int main(int argc, char** argv)
{
    Mavsdk mavsdk;
    std::string connection_url;
    ConnectionResult connection_result;

    //함수 실행시 인자의 유무를 검사하는 항목
    bool discovered_system = false;
    if (argc == 2) {
        connection_url =
            argv[1]; // 프로그램 실행시 넣어주는 첫번째 인자를 의미.0번째는 프로그램이름이다.
        connection_result = mavsdk.add_any_connection(connection_url);
    } else {
        usage(argv[0]);
        return 1;
    }
    // 위에서 받은 입력인자의 값이 올바른지 검사.
    if (connection_result != ConnectionResult::Success) {
        std::cout << ERROR_CONSOLE_TEXT << "Connection failed: " << connection_result
                  << NORMAL_CONSOLE_TEXT << std::endl;
        return 1;
    }

    std::cout << "Waiting to discover system..." << std::endl;
    // 함수를 실행하기전에 콜백하수 안에 있는 내용을 먼저 실행후에 쓰레드를 생성. [&mavsdk,
    // &discovered_system] 배열로 주는 리턴값을 의미한다. c++ 와서 함수도 배열로 리턴을 하여 다수의
    // 출력을 낼 수 있도록 하였다.
    mavsdk.subscribe_on_new_system([&mavsdk, &discovered_system]() {
        const auto system = mavsdk.systems().at(0);
        if (system->is_connected()) {
            std::cout << "Discovered system" << std::endl;
            discovered_system = true;
        }
    });

    // We usually receive heartbeats at 1Hz, therefore we should find a system after around 2
    // seconds. mavlink의 하트비트 대기시간을 1초를 준것.
    std::this_thread::sleep_for(std::chrono::seconds(2));

    //만약 등록된 주소에대한 응답이 없다면 종료.
    if (!discovered_system) {
        std::cout << ERROR_CONSOLE_TEXT << "No system found, exiting." << NORMAL_CONSOLE_TEXT
                  << std::endl;
        return 1;
    }

    const auto system = mavsdk.systems().at(0);
    //현재 기체에 등록된 외부 장치를 검사하는 함수이다. 콜백함수로 구성 되어있으며 출력없이
    system->register_component_discovered_callback(
        [](mavsdk::ComponentType component_type) -> void {
            std::cout << (unsigned)component_type;
        } // component_type에 unsigned를 꼭 붙혀야됨.
    );
    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto telemetry = std::make_shared<Telemetry>(system);

    while (!telemetry->health_all_ok()) {
        std::cout << "Waiting for system to be ready" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    //--------------------------------------------------------
    //mission---------------------------------------------------------------------------

    auto mission = std::make_shared<Mission>(system);
    std::vector<Mission::MissionItem> mission_items;
    //make mission

    {
        double radius = 0.00005;
        std::vector<Mission::MissionItem> mission_circle;
        double x0 = telemetry->position().longitude_deg, y0 =  telemetry->position().latitude_deg;
        double x[3] = {x0+0.0003,x0+0.00015,x0}, y[3] =  {y0,y0+0.00018,y0};         
        double x_avoid = x[2] + 0.5*(x[2] - x[1]), y_avoid = y[2] + 0.5*(y[1]- y[2]);
        double deg = double(atan2(float(y[2]-y_avoid),float(x[2]- x_avoid)));

        for(int i=0;i<3;i++)
        {
            if(i==1){
                mission_items.push_back(make_mission_item(y[0]+y_avoid,x[0]+x_avoid,10.0f,5.0f,true,0.0f,0.0f,Mission::MissionItem::CameraAction::None)
                //nt mis_num,double deg, double radius,double longitude, double latitude)
                half_circle(mission_items,15,deg,radius,x_avoid,y_avoid);
                mission_items.push_back(make_mission_item(y[i],x[i],10.0f,5.0f,true,0.0f,0.0f,Mission::MissionItem::CameraAction::None)
            }
            else{
                mission_items.push_back(make_mission_item(y[i],x[i], 20.0f,
                5.0f,
                true,
                20.0f,
                60.0f,
                Mission::MissionItem::CameraAction::None));
            }
        }
        
    
    }
    //미션 업로드
    {
        std::cout << "Waiting to discover system..." << std::endl;
        auto prom = std::make_shared<std::promise<Mission::Result>>();
        auto future_result = prom->get_future();
        Mission::MissionPlan mission_plan{};
        mission_plan.mission_items = mission_items;

        // mission 업로딩
        mission->upload_mission_async(
            mission_plan, [prom](Mission::Result result) { prom->set_value(result); });
        std::this_thread::sleep_for(std::chrono::seconds(2));
        const Mission::Result start_result = future_result.get();
        if (start_result != Mission::Result::Success) {
            std::cout << "Mission upload failed (" << start_result << "), exiting." << std::endl;
            return 1;
        }
        std::cout << "Mission uploaded." << std::endl;
    }

    // 미션 시작을 위한 변수선언.
    auto action = std::make_shared<Action>(system);
    std::cout << "Arming..." << std::endl;
    const Action::Result arm_result = action->arm();
    handle_action_err_exit(arm_result, "Arm failed: ");
    std::cout << "Armed." << std::endl;

    std::atomic<bool> want_to_pause{false};
    // Before starting the mission, we want to be sure to subscribe to the mission progress.
    mission->subscribe_mission_progress(
        [&want_to_pause](Mission::MissionProgress mission_progress) {
            std::cout << "Mission status update: " << mission_progress.current << " / "
                      << mission_progress.total << std::endl;

            if (mission_progress.current >= 2) {
                // We can only set a flag here. If we do more request inside the callback,
                // we risk blocking the system.
                want_to_pause = true;
            }
        });

    // Starting mission
    {
        std::cout << "Starting mission." << std::endl;
        auto prom = std::make_shared<std::promise<Mission::Result>>();
        auto future_result = prom->get_future();
        mission->start_mission_async([prom](Mission::Result result) {
            prom->set_value(result);
            std::cout << "Started mission." << std::endl;
        });

        const Mission::Result result = future_result.get();
        handle_mission_err_exit(result, "Mission start failed: ");
    }

    while (!mission->is_mission_finished().second) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    {
        // We are done, and can do RTL to go home.
        std::cout << "Commanding RTL..." << std::endl;
        const Action::Result result = action->return_to_launch();
        if (result != Action::Result::Success) {
            std::cout << "Failed to command RTL (" << result << ")" << std::endl;
        } else {
            std::cout << "Commanded RTL." << std::endl;
        }
    }

    // We need to wait a bit, otherwise the armed state might not be correct yet.
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (telemetry->armed()) {
        // Wait until we're done.
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Disarmed, exiting." << std::endl;
    return 0;
}

Mission::MissionItem make_mission_item(
    double latitude_deg,double longitude_deg, float relative_altitude_m,float speed_m_s,
    bool is_fly_through,float gimbal_pitch_deg,float gimbal_yaw_deg, Mission::MissionItem::CameraAction camera_action)
{
    Mission::MissionItem new_item{};
    new_item.latitude_deg = latitude_deg;
    new_item.longitude_deg = longitude_deg;
    new_item.relative_altitude_m = relative_altitude_m;
    new_item.speed_m_s = speed_m_s;
    new_item.is_fly_through = is_fly_through;
    new_item.gimbal_pitch_deg = gimbal_pitch_deg;
    new_item.gimbal_yaw_deg = gimbal_yaw_deg;
    new_item.camera_action = camera_action;
    return new_item;
}

inline void handle_action_err_exit(Action::Result result, const std::string& message)
{
    if (result != Action::Result::Success) {
        std::cerr << ERROR_CONSOLE_TEXT << message << result << NORMAL_CONSOLE_TEXT << std::endl;
        exit(EXIT_FAILURE);
    }
}

inline void handle_mission_err_exit(Mission::Result result, const std::string& message)
{
    if (result != Mission::Result::Success) {
        std::cerr << ERROR_CONSOLE_TEXT << message << result << NORMAL_CONSOLE_TEXT << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Handles connection result
inline void handle_connection_err_exit(ConnectionResult result, const std::string& message)
{
    if (result != ConnectionResult::Success) {
        std::cerr << ERROR_CONSOLE_TEXT << message << result << NORMAL_CONSOLE_TEXT << std::endl;
        exit(EXIT_FAILURE);
    }
}

/** half cycle generate mission that rotate around the center point .    
mis_num : number of mission for 1 circle. recommend value is 6.
cycle : rotate number, alt : start altitude.

return set of (misnum x cycle) mission.
**/
void half_circle(std::vector<Mission::MissionItem> &mission_items,int mis_num,double deg, double radius,double longitude, double latitude)
{
    
    double tmp_x, tmp_y;  // 원의 임시 포인트와 반지름(물체 중심점과 유지하는 거리)

    for(int i=0; i<mis_num+1; i++){
        tmp_x = latitude + radius*sin(deg + i*M_PI/mis_num ); // 한바퀴면 (360*i/max) * PI / 180
        tmp_y = longitude + radius*cos(deg + i*M_PI/mis_num ); // 하지만 반바퀴이므로 (180*i/max) * PI / 180
        make_mission_point(mission_items, tmp_x, tmp_y);
    }
}

void make_mission_point(std::vector<Mission::MissionItem> &mission_items, double x, double y){
    Mission::MissionItem mission_item;
    mission_item.latitude_deg = x;    // 범위: -90 to +90
    mission_item.longitude_deg = y;    // 범위: -180 to +180
    mission_item.relative_altitude_m = 20.0f;    // takeoff altitude
    mission_item.speed_m_s = 10; //단위 m/s, 시속 100km/s
    mission_item.is_fly_through = true;   
    mission_items.push_back(mission_item);
}