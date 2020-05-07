// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/calibration/calibration.proto)

#include <iomanip>

#include "calibration_impl.h"
#include "plugins/calibration/calibration.h"

namespace mavsdk {

using ProgressData = Calibration::ProgressData;

Calibration::Calibration(System& system) : PluginBase(), _impl{new CalibrationImpl(system)} {}

Calibration::~Calibration() {}

void Calibration::calibrate_gyro_async(CalibrateGyroCallback callback)
{
    _impl->calibrate_gyro_async(callback);
}

void Calibration::calibrate_accelerometer_async(CalibrateAccelerometerCallback callback)
{
    _impl->calibrate_accelerometer_async(callback);
}

void Calibration::calibrate_magnetometer_async(CalibrateMagnetometerCallback callback)
{
    _impl->calibrate_magnetometer_async(callback);
}

void Calibration::calibrate_gimbal_accelerometer_async(
    CalibrateGimbalAccelerometerCallback callback)
{
    _impl->calibrate_gimbal_accelerometer_async(callback);
}

void Calibration::cancel() const
{
    _impl->cancel();
}

const char* Calibration::result_str(Calibration::Result result)
{
    switch (result) {
        case Calibration::Result::Unknown:
            return "Unknown result";
        case Calibration::Result::Success:
            return "The calibration succeeded";
        case Calibration::Result::Next:
            return "Intermediate message showing progress or instructions on the next steps";
        case Calibration::Result::Failed:
            return "Calibration failed";
        case Calibration::Result::NoSystem:
            return "No system is connected";
        case Calibration::Result::ConnectionError:
            return "Connection error";
        case Calibration::Result::Busy:
            return "Vehicle is busy";
        case Calibration::Result::CommandDenied:
            return "Command refused by vehicle";
        case Calibration::Result::Timeout:
            return "Command timed out";
        case Calibration::Result::Cancelled:
            return "Calibration process was cancelled";
        default:
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Calibration::Result const& result)
{
    switch (result) {
        case Calibration::Result::Unknown:
            return str << "Unknown";
        case Calibration::Result::Success:
            return str << "Success";
        case Calibration::Result::Next:
            return str << "Next";
        case Calibration::Result::Failed:
            return str << "Failed";
        case Calibration::Result::NoSystem:
            return str << "No System";
        case Calibration::Result::ConnectionError:
            return str << "Connection Error";
        case Calibration::Result::Busy:
            return str << "Busy";
        case Calibration::Result::CommandDenied:
            return str << "Command Denied";
        case Calibration::Result::Timeout:
            return str << "Timeout";
        case Calibration::Result::Cancelled:
            return str << "Cancelled";
        default:
            return str << "Unknown";
    }
}

bool operator==(const Calibration::ProgressData& lhs, const Calibration::ProgressData& rhs)
{
    return (rhs.has_progress == lhs.has_progress) &&
           ((std::isnan(rhs.progress) && std::isnan(lhs.progress)) ||
            rhs.progress == lhs.progress) &&
           (rhs.has_status_text == lhs.has_status_text) && (rhs.status_text == lhs.status_text);
}

std::ostream& operator<<(std::ostream& str, Calibration::ProgressData const& progress_data)
{
    str << std::setprecision(15);
    str << "progress_data:" << '\n' << "{\n";
    str << "    has_progress: " << progress_data.has_progress << '\n';
    str << "    progress: " << progress_data.progress << '\n';
    str << "    has_status_text: " << progress_data.has_status_text << '\n';
    str << "    status_text: " << progress_data.status_text << '\n';
    str << '}';
    return str;
}

} // namespace mavsdk