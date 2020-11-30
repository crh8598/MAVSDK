//
// Simple example to demonstrate how to use the MAVSDK.
//
// Author: Julian Oes <julian@oes.ch>

#include <chrono>
#include <cstdint>
#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <iostream>
#include <thread>

using namespace mavsdk;

#define ERROR_CONSOLE_TEXT "\033[31m" // Turn text on console red
#define TELEMETRY_CONSOLE_TEXT "\033[34m" // Turn text on console blue
#define NORMAL_CONSOLE_TEXT "\033[0m" // Restore normal console colour

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


int main(int argc, char** argv)
{
    Mavsdk mavsdk;
    std::string connection_url;
    ConnectionResult connection_result;

    //함수 실행시 인자의 유무를 검사하는 항목
    bool discovered_system = false;
    if (argc == 2) {
        connection_url = argv[1]; // 프로그램 실행시 넣어주는 첫번째 인자를 의미.0번째는 프로그램이름이다.
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
    // 함수를 실행하기전에 콜백하수 안에 있는 내용을 먼저 실행후에 쓰레드를 생성. [&mavsdk, &discovered_system] 배열로 주는 리턴값을 의미한다.
    // c++ 와서 함수도 배열로 리턴을 하여 다수의 출력을 낼 수 있도록 하였다.
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
        [](mavsdk::ComponentType component_type)->void{std::cout<<(unsigned)component_type;} //component_type에 unsigned를 꼭 붙혀야됨.
    );

/*-----------------------------------------------  텔레메트리 ----------------------------------------------------------------*/
    
    auto telemetry = std::make_shared<Telemetry>(system); // 텔레메트리의 값이 넘어올 떄 변수의 형이 지정
    //1초마다 드론의 고도를 얻기를 위한 작업
    const Telemetry::Result set_rate_result = telemetry->set_rate_position(1.0);
    if(set_rate_result!= Telemetry::Result::Success){std::cout<<"no response from telemetry!"<<std::endl; return 1;}
    telemetry->subscribe_position([](Telemetry::Position position){
        std::cout<<"Altitude : "<<position.relative_altitude_m<<" M"<<std::endl;
    });
    
    while(!telemetry->health_all_ok()){
        std::cout<<"wating for system to be ready"<<std::endl;
       std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    auto alt = telemetry->position();

    while(1){
        // 아래의 콜백함수를 통해 1초당 한번씩 고도정보를 출력이 가능
        // telemetry->subscribe_position([](Telemetry::Position position){
        // std::cout<<"Altitude : "<<position.relative_altitude_m<<" M"<<std::endl;
        // });
   
        alt= telemetry->position(); 
        std::cout<<"Altitude : "<<alt.relative_altitude_m<<std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(500));
        if(alt.relative_altitude_m<0.03) break;
    }

    

/*---------------------------- 기체 Arming ---------------------------------------------------------------------------------------*/
    auto action = std::make_shared<Action>(system);
    std::cout<<"Arming..."<<std::endl;
    const Action::Result disarm_result = action->disarm();

     if(disarm_result != Action::Result::Success)
    {
        std::cout<<"Arming failed : "<<disarm_result<<std::endl;
        return 1;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));

    const Action::Result arm_result = action->arm();
    if(arm_result != Action::Result::Success)
    {
        std::cout<<"Arming failed : "<<arm_result<<std::endl;
        return 1;
    }

    action->takeoff();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    while(1)
    {
       
        if(telemetry->position().relative_altitude_m >=2 )
        {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            action->land(); break;
        }
    }

    return 0;
}
