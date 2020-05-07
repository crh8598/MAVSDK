// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/camera/camera.proto)

#include <iomanip>

#include "camera_impl.h"
#include "plugins/camera/camera.h"

namespace mavsdk {

using Position = Camera::Position;
using Quaternion = Camera::Quaternion;
using EulerAngle = Camera::EulerAngle;
using CaptureInfo = Camera::CaptureInfo;
using VideoStreamSettings = Camera::VideoStreamSettings;
using VideoStreamInfo = Camera::VideoStreamInfo;
using Status = Camera::Status;
using Option = Camera::Option;
using Setting = Camera::Setting;
using SettingOptions = Camera::SettingOptions;
using Information = Camera::Information;

Camera::Camera(System& system) : PluginBase(), _impl{new CameraImpl(system)} {}

Camera::~Camera() {}

void Camera::take_photo_async(const ResultCallback callback)
{
    _impl->take_photo_async(callback);
}

Camera::Result Camera::take_photo() const
{
    return _impl->take_photo();
}

void Camera::start_photo_interval_async(float interval_s, const ResultCallback callback)
{
    _impl->start_photo_interval_async(interval_s, callback);
}

Camera::Result Camera::start_photo_interval(float interval_s) const
{
    return _impl->start_photo_interval(interval_s);
}

void Camera::stop_photo_interval_async(const ResultCallback callback)
{
    _impl->stop_photo_interval_async(callback);
}

Camera::Result Camera::stop_photo_interval() const
{
    return _impl->stop_photo_interval();
}

void Camera::start_video_async(const ResultCallback callback)
{
    _impl->start_video_async(callback);
}

Camera::Result Camera::start_video() const
{
    return _impl->start_video();
}

void Camera::stop_video_async(const ResultCallback callback)
{
    _impl->stop_video_async(callback);
}

Camera::Result Camera::stop_video() const
{
    return _impl->stop_video();
}

Camera::Result Camera::start_video_streaming() const
{
    return _impl->start_video_streaming();
}

Camera::Result Camera::stop_video_streaming() const
{
    return _impl->stop_video_streaming();
}

void Camera::set_mode_async(Mode mode, const ResultCallback callback)
{
    _impl->set_mode_async(mode, callback);
}

Camera::Result Camera::set_mode(Mode mode) const
{
    return _impl->set_mode(mode);
}

void Camera::subscribe_mode(ModeCallback callback)
{
    _impl->mode_async(callback);
}

Camera::Mode Camera::mode() const
{
    return _impl->mode();
}

void Camera::subscribe_information(InformationCallback callback)
{
    _impl->information_async(callback);
}

Camera::Information Camera::information() const
{
    return _impl->information();
}

void Camera::subscribe_video_stream_info(VideoStreamInfoCallback callback)
{
    _impl->video_stream_info_async(callback);
}

Camera::VideoStreamInfo Camera::video_stream_info() const
{
    return _impl->video_stream_info();
}

void Camera::subscribe_capture_info(CaptureInfoCallback callback)
{
    _impl->capture_info_async(callback);
}

void Camera::subscribe_status(StatusCallback callback)
{
    _impl->status_async(callback);
}

Camera::Status Camera::status() const
{
    return _impl->status();
}

void Camera::subscribe_current_settings(CurrentSettingsCallback callback)
{
    _impl->current_settings_async(callback);
}

void Camera::subscribe_possible_setting_options(PossibleSettingOptionsCallback callback)
{
    _impl->possible_setting_options_async(callback);
}

std::vector<Camera::SettingOptions> Camera::possible_setting_options() const
{
    return _impl->possible_setting_options();
}

void Camera::set_setting_async(Setting setting, const ResultCallback callback)
{
    _impl->set_setting_async(setting, callback);
}

Camera::Result Camera::set_setting(Setting setting) const
{
    return _impl->set_setting(setting);
}

void Camera::get_setting_async(Setting setting, const GetSettingCallback callback)
{
    _impl->get_setting_async(setting, callback);
}

std::pair<Camera::Result, Camera::Setting> Camera::get_setting(Setting setting) const
{
    return _impl->get_setting(setting);
}

void Camera::format_storage_async(const ResultCallback callback)
{
    _impl->format_storage_async(callback);
}

Camera::Result Camera::format_storage() const
{
    return _impl->format_storage();
}

const char* Camera::result_str(Camera::Result result)
{
    switch (result) {
        case Camera::Result::Unknown:
            return "Unknown result";
        case Camera::Result::Success:
            return "Command executed successfully";
        case Camera::Result::InProgress:
            return "Command in progress";
        case Camera::Result::Busy:
            return "Camera is busy and rejected command";
        case Camera::Result::Denied:
            return "Camera denied the command";
        case Camera::Result::Error:
            return "An error has occured while executing the command";
        case Camera::Result::Timeout:
            return "Command timed out";
        case Camera::Result::WrongArgument:
            return "Command has wrong argument(s)";
        default:
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Camera::Result const& result)
{
    switch (result) {
        case Camera::Result::Unknown:
            return str << "Unknown";
        case Camera::Result::Success:
            return str << "Success";
        case Camera::Result::InProgress:
            return str << "In Progress";
        case Camera::Result::Busy:
            return str << "Busy";
        case Camera::Result::Denied:
            return str << "Denied";
        case Camera::Result::Error:
            return str << "Error";
        case Camera::Result::Timeout:
            return str << "Timeout";
        case Camera::Result::WrongArgument:
            return str << "Wrong Argument";
        default:
            return str << "Unknown";
    }
}

bool operator==(const Camera::Position& lhs, const Camera::Position& rhs)
{
    return ((std::isnan(rhs.latitude_deg) && std::isnan(lhs.latitude_deg)) ||
            rhs.latitude_deg == lhs.latitude_deg) &&
           ((std::isnan(rhs.longitude_deg) && std::isnan(lhs.longitude_deg)) ||
            rhs.longitude_deg == lhs.longitude_deg) &&
           ((std::isnan(rhs.absolute_altitude_m) && std::isnan(lhs.absolute_altitude_m)) ||
            rhs.absolute_altitude_m == lhs.absolute_altitude_m) &&
           ((std::isnan(rhs.relative_altitude_m) && std::isnan(lhs.relative_altitude_m)) ||
            rhs.relative_altitude_m == lhs.relative_altitude_m);
}

std::ostream& operator<<(std::ostream& str, Camera::Position const& position)
{
    str << std::setprecision(15);
    str << "position:" << '\n' << "{\n";
    str << "    latitude_deg: " << position.latitude_deg << '\n';
    str << "    longitude_deg: " << position.longitude_deg << '\n';
    str << "    absolute_altitude_m: " << position.absolute_altitude_m << '\n';
    str << "    relative_altitude_m: " << position.relative_altitude_m << '\n';
    str << '}';
    return str;
}

bool operator==(const Camera::Quaternion& lhs, const Camera::Quaternion& rhs)
{
    return ((std::isnan(rhs.w) && std::isnan(lhs.w)) || rhs.w == lhs.w) &&
           ((std::isnan(rhs.x) && std::isnan(lhs.x)) || rhs.x == lhs.x) &&
           ((std::isnan(rhs.y) && std::isnan(lhs.y)) || rhs.y == lhs.y) &&
           ((std::isnan(rhs.z) && std::isnan(lhs.z)) || rhs.z == lhs.z);
}

std::ostream& operator<<(std::ostream& str, Camera::Quaternion const& quaternion)
{
    str << std::setprecision(15);
    str << "quaternion:" << '\n' << "{\n";
    str << "    w: " << quaternion.w << '\n';
    str << "    x: " << quaternion.x << '\n';
    str << "    y: " << quaternion.y << '\n';
    str << "    z: " << quaternion.z << '\n';
    str << '}';
    return str;
}

bool operator==(const Camera::EulerAngle& lhs, const Camera::EulerAngle& rhs)
{
    return ((std::isnan(rhs.roll_deg) && std::isnan(lhs.roll_deg)) ||
            rhs.roll_deg == lhs.roll_deg) &&
           ((std::isnan(rhs.pitch_deg) && std::isnan(lhs.pitch_deg)) ||
            rhs.pitch_deg == lhs.pitch_deg) &&
           ((std::isnan(rhs.yaw_deg) && std::isnan(lhs.yaw_deg)) || rhs.yaw_deg == lhs.yaw_deg);
}

std::ostream& operator<<(std::ostream& str, Camera::EulerAngle const& euler_angle)
{
    str << std::setprecision(15);
    str << "euler_angle:" << '\n' << "{\n";
    str << "    roll_deg: " << euler_angle.roll_deg << '\n';
    str << "    pitch_deg: " << euler_angle.pitch_deg << '\n';
    str << "    yaw_deg: " << euler_angle.yaw_deg << '\n';
    str << '}';
    return str;
}

bool operator==(const Camera::CaptureInfo& lhs, const Camera::CaptureInfo& rhs)
{
    return (rhs.position == lhs.position) && (rhs.attitude_quaternion == lhs.attitude_quaternion) &&
           (rhs.attitude_euler_angle == lhs.attitude_euler_angle) &&
           (rhs.time_utc_us == lhs.time_utc_us) && (rhs.is_success == lhs.is_success) &&
           (rhs.index == lhs.index) && (rhs.file_url == lhs.file_url);
}

std::ostream& operator<<(std::ostream& str, Camera::CaptureInfo const& capture_info)
{
    str << std::setprecision(15);
    str << "capture_info:" << '\n' << "{\n";
    str << "    position: " << capture_info.position << '\n';
    str << "    attitude_quaternion: " << capture_info.attitude_quaternion << '\n';
    str << "    attitude_euler_angle: " << capture_info.attitude_euler_angle << '\n';
    str << "    time_utc_us: " << capture_info.time_utc_us << '\n';
    str << "    is_success: " << capture_info.is_success << '\n';
    str << "    index: " << capture_info.index << '\n';
    str << "    file_url: " << capture_info.file_url << '\n';
    str << '}';
    return str;
}

bool operator==(const Camera::VideoStreamSettings& lhs, const Camera::VideoStreamSettings& rhs)
{
    return ((std::isnan(rhs.frame_rate_hz) && std::isnan(lhs.frame_rate_hz)) ||
            rhs.frame_rate_hz == lhs.frame_rate_hz) &&
           (rhs.horizontal_resolution_pix == lhs.horizontal_resolution_pix) &&
           (rhs.vertical_resolution_pix == lhs.vertical_resolution_pix) &&
           (rhs.bit_rate_b_s == lhs.bit_rate_b_s) && (rhs.rotation_deg == lhs.rotation_deg) &&
           (rhs.uri == lhs.uri);
}

std::ostream&
operator<<(std::ostream& str, Camera::VideoStreamSettings const& video_stream_settings)
{
    str << std::setprecision(15);
    str << "video_stream_settings:" << '\n' << "{\n";
    str << "    frame_rate_hz: " << video_stream_settings.frame_rate_hz << '\n';
    str << "    horizontal_resolution_pix: " << video_stream_settings.horizontal_resolution_pix
        << '\n';
    str << "    vertical_resolution_pix: " << video_stream_settings.vertical_resolution_pix << '\n';
    str << "    bit_rate_b_s: " << video_stream_settings.bit_rate_b_s << '\n';
    str << "    rotation_deg: " << video_stream_settings.rotation_deg << '\n';
    str << "    uri: " << video_stream_settings.uri << '\n';
    str << '}';
    return str;
}

std::ostream& operator<<(std::ostream& str, Camera::VideoStreamInfo::Status const& status)
{
    switch (status) {
        case Camera::VideoStreamInfo::Status::NotRunning:
            return str << "Not Running";
        case Camera::VideoStreamInfo::Status::InProgress:
            return str << "In Progress";
        default:
            return str << "Unknown";
    }
}
bool operator==(const Camera::VideoStreamInfo& lhs, const Camera::VideoStreamInfo& rhs)
{
    return (rhs.settings == lhs.settings) && (rhs.status == lhs.status);
}

std::ostream& operator<<(std::ostream& str, Camera::VideoStreamInfo const& video_stream_info)
{
    str << std::setprecision(15);
    str << "video_stream_info:" << '\n' << "{\n";
    str << "    settings: " << video_stream_info.settings << '\n';
    str << "    status: " << video_stream_info.status << '\n';
    str << '}';
    return str;
}

std::ostream& operator<<(std::ostream& str, Camera::Status::StorageStatus const& storage_status)
{
    switch (storage_status) {
        case Camera::Status::StorageStatus::NotAvailable:
            return str << "Not Available";
        case Camera::Status::StorageStatus::Unformatted:
            return str << "Unformatted";
        case Camera::Status::StorageStatus::Formatted:
            return str << "Formatted";
        default:
            return str << "Unknown";
    }
}
bool operator==(const Camera::Status& lhs, const Camera::Status& rhs)
{
    return (rhs.video_on == lhs.video_on) && (rhs.photo_interval_on == lhs.photo_interval_on) &&
           ((std::isnan(rhs.used_storage_mib) && std::isnan(lhs.used_storage_mib)) ||
            rhs.used_storage_mib == lhs.used_storage_mib) &&
           ((std::isnan(rhs.available_storage_mib) && std::isnan(lhs.available_storage_mib)) ||
            rhs.available_storage_mib == lhs.available_storage_mib) &&
           ((std::isnan(rhs.total_storage_mib) && std::isnan(lhs.total_storage_mib)) ||
            rhs.total_storage_mib == lhs.total_storage_mib) &&
           ((std::isnan(rhs.recording_time_s) && std::isnan(lhs.recording_time_s)) ||
            rhs.recording_time_s == lhs.recording_time_s) &&
           (rhs.media_folder_name == lhs.media_folder_name) &&
           (rhs.storage_status == lhs.storage_status);
}

std::ostream& operator<<(std::ostream& str, Camera::Status const& status)
{
    str << std::setprecision(15);
    str << "status:" << '\n' << "{\n";
    str << "    video_on: " << status.video_on << '\n';
    str << "    photo_interval_on: " << status.photo_interval_on << '\n';
    str << "    used_storage_mib: " << status.used_storage_mib << '\n';
    str << "    available_storage_mib: " << status.available_storage_mib << '\n';
    str << "    total_storage_mib: " << status.total_storage_mib << '\n';
    str << "    recording_time_s: " << status.recording_time_s << '\n';
    str << "    media_folder_name: " << status.media_folder_name << '\n';
    str << "    storage_status: " << status.storage_status << '\n';
    str << '}';
    return str;
}

bool operator==(const Camera::Option& lhs, const Camera::Option& rhs)
{
    return (rhs.option_id == lhs.option_id) && (rhs.option_description == lhs.option_description);
}

std::ostream& operator<<(std::ostream& str, Camera::Option const& option)
{
    str << std::setprecision(15);
    str << "option:" << '\n' << "{\n";
    str << "    option_id: " << option.option_id << '\n';
    str << "    option_description: " << option.option_description << '\n';
    str << '}';
    return str;
}

bool operator==(const Camera::Setting& lhs, const Camera::Setting& rhs)
{
    return (rhs.setting_id == lhs.setting_id) &&
           (rhs.setting_description == lhs.setting_description) && (rhs.option == lhs.option) &&
           (rhs.is_range == lhs.is_range);
}

std::ostream& operator<<(std::ostream& str, Camera::Setting const& setting)
{
    str << std::setprecision(15);
    str << "setting:" << '\n' << "{\n";
    str << "    setting_id: " << setting.setting_id << '\n';
    str << "    setting_description: " << setting.setting_description << '\n';
    str << "    option: " << setting.option << '\n';
    str << "    is_range: " << setting.is_range << '\n';
    str << '}';
    return str;
}

bool operator==(const Camera::SettingOptions& lhs, const Camera::SettingOptions& rhs)
{
    return (rhs.setting_id == lhs.setting_id) &&
           (rhs.setting_description == lhs.setting_description) && (rhs.options == lhs.options) &&
           (rhs.is_range == lhs.is_range);
}

std::ostream& operator<<(std::ostream& str, Camera::SettingOptions const& setting_options)
{
    str << std::setprecision(15);
    str << "setting_options:" << '\n' << "{\n";
    str << "    setting_id: " << setting_options.setting_id << '\n';
    str << "    setting_description: " << setting_options.setting_description << '\n';
    str << "    options: [";
    for (auto it = setting_options.options.begin(); it != setting_options.options.end(); ++it) {
        str << *it;
        str << (it + 1 != setting_options.options.end() ? ", " : "]\n");
    }
    str << "    is_range: " << setting_options.is_range << '\n';
    str << '}';
    return str;
}

bool operator==(const Camera::Information& lhs, const Camera::Information& rhs)
{
    return (rhs.vendor_name == lhs.vendor_name) && (rhs.model_name == lhs.model_name);
}

std::ostream& operator<<(std::ostream& str, Camera::Information const& information)
{
    str << std::setprecision(15);
    str << "information:" << '\n' << "{\n";
    str << "    vendor_name: " << information.vendor_name << '\n';
    str << "    model_name: " << information.model_name << '\n';
    str << '}';
    return str;
}

std::ostream& operator<<(std::ostream& str, Camera::Mode const& mode)
{
    switch (mode) {
        case Camera::Mode::Unknown:
            return str << "Unknown";
        case Camera::Mode::Photo:
            return str << "Photo";
        case Camera::Mode::Video:
            return str << "Video";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk