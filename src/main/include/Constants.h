#pragma once
//std
#include <string>
#include <memory>

//FRC
//#include <frc/AddressableLED.h>

//local
#include "DertLib/include/SparkMaxMotor.h"
#include "DertLib/include/TalonFXMotor.h"
#include "DertLib/include/CANBus.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "Odometry_ert_rtw/Odometry.h"
#include "LimelightHelpers.h"

using namespace dlib;

namespace Constants
{
    namespace CANBuses
    {
        static std::shared_ptr<ctre::phoenix6::CANBus> CANivoreBus = std::make_shared<ctre::phoenix6::CANBus>("uno");
        static std::shared_ptr<ctre::phoenix6::CANBus> RioBus = std::make_shared<ctre::phoenix6::CANBus>("rio");
    };
    
    namespace SwerveInfo
    {
    // Define the CAN bus network into which the Swerve CANcoders are connected
        static std::shared_ptr<ctre::phoenix6::CANBus> CANcoder_CANBus = Constants::CANBuses::CANivoreBus;

    // Define the Swerve Steer Encoder CAN IDs
        static constexpr int k_FrontLeft_Steer_Encoder_ID = 1;
        static constexpr int k_FrontRight_Steer_Encoder_ID = 2;
        static constexpr int k_BackLeft_Steer_Encoder_ID = 3;
        static constexpr int k_BackRight_Steer_Encoder_ID = 4;
    
    // Wheel Offset Keys
        static constexpr std::string_view k_FrontLeft_Wheel_Offset_Key = "FrontLeftWheelOffset";
        static constexpr std::string_view k_FrontRight_Wheel_Offset_Key = "FrontRightWheelOffset";
        static constexpr std::string_view k_BackLeft_Wheel_Offset_Key = "BackLeftWheelOffset";
        static constexpr std::string_view k_BackRight_Wheel_Offset_Key = "BackRightWheelOffset";
    };

    namespace SwerveMotorsCreateInfo
    {
        namespace Drive
        {
            static TalonFXMotorCreateInfo defaultDriveCreateInfo = TalonFXMotorCreateInfo::getDefaultCreateInfo()
                .SetCanbus(*Constants::CANBuses::CANivoreBus)
                .SetIsReversed(true)
                .SetSupplyCurrentLimit(80)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFXMotorType::KrakenX60);

            static const TalonFXMotorCreateInfo frontLeft = defaultDriveCreateInfo
                .SetCanID(1)
                .SetDutyCycleCallback(&Robot_Control_Y.FrontLeft_Drive_DutyCycle)
                .SetVelocityCallback(&Odometry_U.FrontLeft_Drive_Motor_Speed)
                .SetPositionCallback(&Odometry_U.FrontLeft_Drive_Motor_Rev)
                .SetDisplayName("Front Left Drive Motor");
            
            static const TalonFXMotorCreateInfo frontRight = defaultDriveCreateInfo
                .SetCanID(2)
                .SetDutyCycleCallback(&Robot_Control_Y.FrontRight_Drive_DutyCycle)
                .SetVelocityCallback(&Odometry_U.FrontRight_Drive_Motor_Speed)
                .SetPositionCallback(&Odometry_U.FrontRight_Drive_Motor_Rev)
                .SetDisplayName("Front Right Drive Motor");

            static const TalonFXMotorCreateInfo backLeft = defaultDriveCreateInfo
                .SetCanID(3)
                .SetDutyCycleCallback(&Robot_Control_Y.BackLeft_Drive_DutyCycle)
                .SetVelocityCallback(&Odometry_U.BackLeft_Drive_Motor_Speed)
                .SetPositionCallback(&Odometry_U.BackLeft_Drive_Motor_Rev)
                .SetDisplayName("Back Left Drive Motor");

            static const TalonFXMotorCreateInfo backRight = defaultDriveCreateInfo
                .SetCanID(4)
                .SetDutyCycleCallback(&Robot_Control_Y.BackRight_Drive_DutyCycle)
                .SetVelocityCallback(&Odometry_U.BackRight_Drive_Motor_Speed)
                .SetPositionCallback(&Odometry_U.BackRight_Drive_Motor_Rev)  
                .SetDisplayName("Back Right Drive Motor");

        };
        
        namespace Steer
        {
            static TalonFXMotorCreateInfo defaultSteerCreateInfo = TalonFXMotorCreateInfo::getDefaultCreateInfo()
                .SetCanbus(*Constants::CANBuses::CANivoreBus)
                .SetIsReversed(false)
                .SetSupplyCurrentLimit(60)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFXMotorType::KrakenX44);

            static const TalonFXMotorCreateInfo frontLeft = defaultSteerCreateInfo
                .SetCanID(5)
                .SetDutyCycleCallback(&Robot_Control_Y.FrontLeft_Steer_DutyCycle)
                .SetDisplayName("Front Left Steer Motor");
            
            static const TalonFXMotorCreateInfo frontRight = defaultSteerCreateInfo
                .SetCanID(6)
                .SetDutyCycleCallback(&Robot_Control_Y.FrontRight_Steer_DutyCycle) 
                .SetDisplayName("Front Right Steer Motor");

            static const TalonFXMotorCreateInfo backLeft = defaultSteerCreateInfo
                .SetCanID(7)
                .SetDutyCycleCallback(&Robot_Control_Y.BackLeft_Steer_DutyCycle)
                .SetDisplayName("Back Left Steer Motor");

            static const TalonFXMotorCreateInfo backRight = defaultSteerCreateInfo
                .SetCanID(8)
                .SetDutyCycleCallback(&Robot_Control_Y.BackRight_Steer_DutyCycle)
                .SetDisplayName("Back Right Steer Motor");
        };
    };
    
    namespace HID
    {
        static constexpr int k_Gamepad_Port = 0;
        static constexpr int k_Left_Joystick_Port = 1;
        static constexpr int k_Right_Joystick_Port = 2;
    };

    namespace IMU
    {
    // Define the CAN bus network into which the IMU is connected
        static std::shared_ptr<ctre::phoenix6::CANBus> IMU_CANBus = Constants::CANBuses::CANivoreBus;

    // Define the IMU CAN ID
        static constexpr int k_Pigeon2_Device_ID = 5;
    };


    namespace Limelight
    {
        static const LimeLightCameraCreateInfo CameraOneCreateInfo
        {
            "limelight-one", // Limelight Name
            10.0/39.37008,   // Forward offset (meters)
            0.0/39.37008,    // Side offset (meters)
            10.0/39.37008,   // Height offset (meters)
            0.0,             // Roll (degrees)
            0.0,             // Pitch (degrees)
            0.0              // Yaw (degrees)
        };
        static const LimeLightCameraCreateInfo CameraTwoCreateInfo
        {
            "limelight-two", // Limelight Name
            0.5,             // Forward offset (meters)
            0.0,             // Side offset (meters)
            0.5,             // Height offset (meters)
            0.0,             // Roll (degrees)
            30.0,            // Pitch (degrees)
            0.0              // Yaw (degrees)
        };
    };

    namespace ShooterCreateInfo
    {
        static TalonFXMotorCreateInfo defaultShooterCreateInfo = TalonFXMotorCreateInfo::getDefaultCreateInfo()
                .SetCanbus(*Constants::CANBuses::RioBus)
                .SetIsReversed(false)
                .SetSupplyCurrentLimit(60)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFXMotorType::KrakenX60);
        static const TalonFXMotorCreateInfo Left = defaultShooterCreateInfo
                .SetCanID(10)
                .SetDutyCycleCallback(&Robot_Control_Y.Left_Shooter_DutyCycle)
                .SetVelocityCallback(&Robot_Control_U.Left_Shooter_Motor_Speed)
                .SetDisplayName("Left Shooter Motor");
        static const TalonFXMotorCreateInfo Center = defaultShooterCreateInfo
                .SetCanID(11)
                .SetDutyCycleCallback(&Robot_Control_Y.Center_Shooter_DutyCycle)
                .SetVelocityCallback(&Robot_Control_U.Center_Shooter_Motor_Speed)
                .SetDisplayName("Center Shooter Motor");
        static const TalonFXMotorCreateInfo Right = defaultShooterCreateInfo
                .SetCanID(12)
                .SetDutyCycleCallback(&Robot_Control_Y.Right_Shooter_DutyCycle)
                .SetVelocityCallback(&Robot_Control_U.Right_Shooter_Motor_Speed)
                .SetDisplayName("Right Shooter Motor");
    }

    namespace FeederCreateInfo
    {
        static TalonFXMotorCreateInfo defaultFeederCreateInfo = TalonFXMotorCreateInfo::getDefaultCreateInfo()
                .SetCanbus(*Constants::CANBuses::RioBus)
                .SetIsReversed(false)
                .SetSupplyCurrentLimit(60)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFXMotorType::KrakenX44);
        static const TalonFXMotorCreateInfo Feeder = defaultFeederCreateInfo
                .SetCanID(13)
                .SetDutyCycleCallback(&Robot_Control_Y.Feeder_DutyCycle)
                .SetVelocityCallback(&Robot_Control_U.Feeder_Motor_Speed)
                .SetDisplayName("Feeder Motor");
    }
     
    namespace TransferCreateInfo
    {
        static TalonFXMotorCreateInfo defaultTransferCreateInfo = TalonFXMotorCreateInfo::getDefaultCreateInfo()
                .SetCanbus(*Constants::CANBuses::RioBus)
                .SetIsReversed(false)
                .SetSupplyCurrentLimit(60)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFXMotorType::KrakenX44);
        static const TalonFXMotorCreateInfo Transfer = defaultTransferCreateInfo
                .SetCanID(14)
                .SetDutyCycleCallback(&Robot_Control_Y.Transfer_DutyCycle)
                .SetVelocityCallback(&Robot_Control_U.Transfer_Motor_Speed)
                .SetDisplayName("Transfer Motor");
    }

    namespace HoodServo
    {
        static constexpr int Hood_Servo_PWM_Left_ID = 0;
        static constexpr int Hood_Servo_PWM_Right_ID = 1;
    }
    

};