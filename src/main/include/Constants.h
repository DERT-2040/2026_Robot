#pragma once
//std
#include <string>
#include <memory>

//FRC
//#include <frc/AddressableLED.h>

//local
#include "DertLib/include/SparkMaxMotor.h"
#include "DertLib/include/TalonFX/TalonFXMotorGroup.h"
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
            static TalonFX::MotorCreateInfo defaultDriveCreateInfo = TalonFX::GetNewDutyCycleCreateInfo()
                .SetCanbus(*Constants::CANBuses::CANivoreBus)
                .SetIsReversed(true)
                .SetSupplyCurrentLimit(80)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFX::MotorType::KrakenX60);

            static const TalonFX::MotorCreateInfo frontLeft = defaultDriveCreateInfo.Clone()
                .SetCanID(1)
                .SetDutyCycleCallback(&Robot_Control_Y.FrontLeft_Drive_DutyCycle)
                .SetVelocityCallback(&Odometry_U.FrontLeft_Drive_Motor_Speed)
                .SetPositionCallback(&Odometry_U.FrontLeft_Drive_Motor_Rev)
                .SetDisplayName("Front Left Drive Motor");
            
            static const TalonFX::MotorCreateInfo frontRight = defaultDriveCreateInfo.Clone()
                .SetCanID(2)
                .SetDutyCycleCallback(&Robot_Control_Y.FrontRight_Drive_DutyCycle)
                .SetVelocityCallback(&Odometry_U.FrontRight_Drive_Motor_Speed)
                .SetPositionCallback(&Odometry_U.FrontRight_Drive_Motor_Rev)
                .SetDisplayName("Front Right Drive Motor");

            static const TalonFX::MotorCreateInfo backLeft = defaultDriveCreateInfo.Clone()
                .SetCanID(3)
                .SetDutyCycleCallback(&Robot_Control_Y.BackLeft_Drive_DutyCycle)
                .SetVelocityCallback(&Odometry_U.BackLeft_Drive_Motor_Speed)
                .SetPositionCallback(&Odometry_U.BackLeft_Drive_Motor_Rev)
                .SetDisplayName("Back Left Drive Motor");

            static const TalonFX::MotorCreateInfo backRight = defaultDriveCreateInfo.Clone()
                .SetCanID(4)
                .SetDutyCycleCallback(&Robot_Control_Y.BackRight_Drive_DutyCycle)
                .SetVelocityCallback(&Odometry_U.BackRight_Drive_Motor_Speed)
                .SetPositionCallback(&Odometry_U.BackRight_Drive_Motor_Rev)  
                .SetDisplayName("Back Right Drive Motor");

        };
        
        namespace Steer
        {
            static TalonFX::MotorCreateInfo defaultSteerCreateInfo = TalonFX::GetNewDutyCycleCreateInfo()
                .SetCanbus(*Constants::CANBuses::CANivoreBus)
                .SetIsReversed(false)
                .SetSupplyCurrentLimit(60)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFX::MotorType::KrakenX44);

            static const TalonFX::MotorCreateInfo frontLeft = defaultSteerCreateInfo.Clone()
                .SetCanID(5)
                .SetDutyCycleCallback(&Robot_Control_Y.FrontLeft_Steer_DutyCycle)
                .SetDisplayName("Front Left Steer Motor");
            
            static const TalonFX::MotorCreateInfo frontRight = defaultSteerCreateInfo.Clone()
                .SetCanID(6)
                .SetDutyCycleCallback(&Robot_Control_Y.FrontRight_Steer_DutyCycle) 
                .SetDisplayName("Front Right Steer Motor");

            static const TalonFX::MotorCreateInfo backLeft = defaultSteerCreateInfo.Clone()
                .SetCanID(7)
                .SetDutyCycleCallback(&Robot_Control_Y.BackLeft_Steer_DutyCycle)
                .SetDisplayName("Back Left Steer Motor");

            static const TalonFX::MotorCreateInfo backRight = defaultSteerCreateInfo.Clone()
                .SetCanID(8)
                .SetDutyCycleCallback(&Robot_Control_Y.BackRight_Steer_DutyCycle)
                .SetDisplayName("Back Right Steer Motor");
        };
    };
    
    namespace HID
    {
        static constexpr int k_Gamepad_Port = 0;
        static constexpr int k_DriverXbox_Port = 1;
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
            "limelight-one", // Limelight Name - REAR FACING
            -0.230,   // X+ (Forward): Towards the front of the robot (in meters).
            0.273, // Y+ (Right): Towards the right side of the robot (in meters).
            0.441,  // Z+ (Up): Towards the top of the robot (in meters).
            0,             // Roll (degrees)
            28,              // Pitch (degrees)
            180              // Yaw (degrees)
        };
        static const LimeLightCameraCreateInfo CameraTwoCreateInfo
        {
            "limelight-two", // Limelight Name - FRONT FACING
            -0.103,   // X+ (Forward): Towards the front of the robot (in meters).
            0.273,   // Y+ (Right): Towards the right side of the robot (in meters).
            0.503,   // Z+ (Up): Towards the top of the robot (in meters).
            90,             // Roll (degrees)
            41,             // Pitch (degrees)
            0              // Yaw (degrees)
        };
    };
// Desired_Shooter_FF_DC
    namespace ShooterCreateInfo
    {
        static double d = 0;
        static TalonFX::MotorCreateInfo defaultShooterCreateInfo = TalonFX::GetNewVelocityCreateInfo()
                .SetCanbus(*Constants::CANBuses::CANivoreBus)
                .SetIsReversed(false)
                .SetSupplyCurrentLimit(80)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFX::MotorType::KrakenX60)
                .SetAcceleration(1000)
                .EditPIDSlot(0)
                    .SetPGain(&Robot_Control_Y.Shooter_Motor_Gain_Kp)
                    .SetIGain(&Robot_Control_Y.Shooter_Motor_Gain_Ki)
                    .SetDGain(&d)
                    .SetupdatePID(&Robot_Control_Y.Shooter_Motor_Gain_Change)
                .ExitPidConfig()
                .SetSelectedSlot(0)
                .SetFF(&Robot_Control_Y.Desired_Shooter_FF_DC)
                .SetUseTimeSync(false)
                .SetTargetVelocity(&Robot_Control_Y.Desired_Shooter_Speed)
                .SetUpdateFrequency(1000);
                // .velocityCallback();
        static const TalonFX::MotorCreateInfo Left = defaultShooterCreateInfo.Clone()
                .SetCanID(10)
                .SetIsReversed(true)                
                .SetVelocityCallback(&Robot_Control_U.Measured_Shooter_Speed_Left)
                .SetDisplayName("Left Shooter Motor");
                // .SetDutyCycleCallback(&Robot_Control_Y.Shooter_Motor_DC_Left)
        static const TalonFX::MotorCreateInfo Center = defaultShooterCreateInfo.Clone()
                .SetCanID(11)
                .SetIsReversed(true)                
                .SetVelocityCallback(&Robot_Control_U.Measured_Shooter_Speed_Center)
                .SetDisplayName("Center Shooter Motor");
                // .SetDutyCycleCallback(&Robot_Control_Y.Shooter_Motor_DC_Center)
        static const TalonFX::MotorCreateInfo Right = defaultShooterCreateInfo.Clone()
                .SetCanID(12)
                .SetIsReversed(false)                
                .SetVelocityCallback(&Robot_Control_U.Measured_Shooter_Speed_Right)
                .SetDisplayName("Right Shooter Motor");
                // .SetDutyCycleCallback(&Robot_Control_Y.Shooter_Motor_DC_Right)
    }

    namespace FeederCreateInfo
    {
        static TalonFX::MotorCreateInfo defaultFeederCreateInfo = TalonFX::GetNewDutyCycleCreateInfo()
                .SetCanbus(*Constants::CANBuses::CANivoreBus)
                .SetIsReversed(false)
                .SetSupplyCurrentLimit(80)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFX::MotorType::KrakenX60);
        static const TalonFX::MotorCreateInfo Feeder = defaultFeederCreateInfo.Clone()
                .SetCanID(13)
                .SetDutyCycleCallback(&Robot_Control_Y.Feeder_Motor_DC)
                .SetVelocityCallback(&Robot_Control_U.Measured_Feeder_Speed)
                .SetDisplayName("Feeder Motor");
    }
     
    namespace TransferCreateInfo
    {
        static TalonFX::MotorCreateInfo defaultTransferCreateInfo = TalonFX::GetNewDutyCycleCreateInfo()
                .SetCanbus(*Constants::CANBuses::CANivoreBus)
                .SetIsReversed(false)
                .SetSupplyCurrentLimit(60)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true)
                .SetMotorType(TalonFX::MotorType::KrakenX44);
        static const TalonFX::MotorCreateInfo Transfer = defaultTransferCreateInfo.Clone()
                .SetCanID(14)
                .SetDutyCycleCallback(&Robot_Control_Y.Transfer_Motor_DC)
                .SetVelocityCallback(&Robot_Control_U.Measured_Transfer_Speed)
                .SetDisplayName("Transfer Motor");
    }

    namespace HoodServo
    {
        static constexpr int Hood_Servo_PWM_Left_ID = 0;
        static constexpr int Hood_Servo_PWM_Right_ID = 1;
    }
    
    namespace IntakeCreateInfo{
        static TalonFX::MotorCreateInfo defaultIntakeCreateInfo = TalonFX::GetNewDutyCycleCreateInfo()
                .SetCanbus(*Constants::CANBuses::CANivoreBus)
                .SetOpenLoopRampPeriod(0)
                .SetEnableFOC(true);
        static const TalonFX::MotorCreateInfo Intake_Arm = defaultIntakeCreateInfo.Clone() 
                .SetCanID(15)
                .SetIsReversed(true)
                .SetSupplyCurrentLimit(60)                
                .SetDutyCycleCallback(&Robot_Control_Y.Intake_Arm_Motor_DC)
                .SetDisplayName("Intake Arm")
                .SetMotorType(TalonFX::MotorType::KrakenX44);                
        static const TalonFX::MotorCreateInfo Intake_Roller = defaultIntakeCreateInfo.Clone()
                .SetCanID(16)
                .SetIsReversed(false)            
                .SetSupplyCurrentLimit(80)                    
                .SetDutyCycleCallback(&Robot_Control_Y.Intake_Roller_Motor_DC)
                .SetVelocityCallback(&Robot_Control_U.Measured_Intake_Roller_Speed)
                .SetDisplayName("Intake Roller")
                .SetMotorType(TalonFX::MotorType::KrakenX60);                
    }

    namespace IntakeArmAngle{
        //Arm Angle 
        static constexpr int armThroughBoreEncoderID = 0;
        static constexpr int armThroughBoreEncoderOffset = 255.9; // degrees
    }

};