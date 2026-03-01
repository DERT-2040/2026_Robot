#include "include/Limelight.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
Limelight::Limelight()
{
    LimelightHelpers::setCameraPose_RobotSpace(
        nsLimelight::CameraOneCreateInfo.LimelightName,
        nsLimelight::CameraOneCreateInfo.ForwardOffset,
        nsLimelight::CameraOneCreateInfo.SideOffset,
        nsLimelight::CameraOneCreateInfo.HeightOffset,
        nsLimelight::CameraOneCreateInfo.Roll,
        nsLimelight::CameraOneCreateInfo.Pitch,
        nsLimelight::CameraOneCreateInfo.Yaw
    );

    LimelightHelpers::setCameraPose_RobotSpace(
        nsLimelight::CameraTwoCreateInfo.LimelightName,
        nsLimelight::CameraTwoCreateInfo.ForwardOffset,
        nsLimelight::CameraTwoCreateInfo.SideOffset,
        nsLimelight::CameraTwoCreateInfo.HeightOffset,
        nsLimelight::CameraTwoCreateInfo.Roll,
        nsLimelight::CameraTwoCreateInfo.Pitch,
        nsLimelight::CameraTwoCreateInfo.Yaw
    ); 
}

void Limelight::PreStepCallback() {
    /////////////////////////////////
    // SET ALERT IF NOT CONNECTED
    /////////////////////////////////
    CameraOneDisconnectedAlert.Set(!nt::NetworkTableInstance::GetDefault().GetTable(nsLimelight::CameraOneCreateInfo.LimelightName)->ContainsKey("cl"));
    //CameraTwoDisconnectedAlert.Set(!nt::NetworkTableInstance::GetDefault().GetTable(LimelightNameSpace::CameraTwoCreateInfo.LimelightName)->ContainsKey("cl"));

    /////////////////////////////////
    // GET THE CURRENT PIPELINE AND SET THE PIPELINE IF NEEDED
    /////////////////////////////////
    // Get the current pipeline
    double Current_Pipeline = LimelightHelpers::getLimelightNTDouble(nsLimelight::CameraOneCreateInfo.LimelightName, "pipeline");

    // Check if current pipeline is different than desired pipeline
    if(Current_Pipeline != Robot_Control_Y.Vision_Desired_Pipeline)
    {
        // Set the pipeline if the current pipeline is different than desired pipeline
        LimelightHelpers::setPipelineIndex(nsLimelight::CameraOneCreateInfo.LimelightName, int(Robot_Control_Y.Vision_Desired_Pipeline));

        // Get the current pipeline (double check after setting it above)
        Current_Pipeline = LimelightHelpers::getLimelightNTDouble(nsLimelight::CameraOneCreateInfo.LimelightName, "pipeline");
    }

    // Set current pipeline to a Simulink input so control action is taken based on current pipeline (instead of desired pipeline)
    Robot_Control_U.Vision_Current_Pipeline = Current_Pipeline;

    /////////////////////////////////
    // APRIL TAG PIPELINE
    /////////////////////////////////
    if (Current_Pipeline == 0)
    {
        // Gyro angle that has been adjusted to the field coordinate system (convert from radians to degrees)
        auto adjustedGyro = Odometry_Y.Gyro_Angle_Field_rad*180/3.14159265358979323846;

        //Sets Robot Oriention (MT2 Requirement)
        LimelightHelpers::SetRobotOrientation(nsLimelight::CameraOneCreateInfo.LimelightName, adjustedGyro, 0.0, 0.0, 0.0, 0.0, 0.0);
        LimelightHelpers::SetRobotOrientation(nsLimelight::CameraTwoCreateInfo.LimelightName, adjustedGyro, 0.0, 0.0, 0.0, 0.0, 0.0);

        //Updates Pose
        CameraOneLLMeasurement = LimelightHelpers::getBotPoseEstimate_wpiBlue(nsLimelight::CameraOneCreateInfo.LimelightName);
        CameraTwoLLMeasurement = LimelightHelpers::getBotPoseEstimate_wpiBlue(nsLimelight::CameraTwoCreateInfo.LimelightName);

        // Limelight Values for Scoring & Selection
        double CameraOneLLAvgTagArea = CameraOneLLMeasurement.avgTagArea;
        double CameraOneLLAvgTagDist = CameraOneLLMeasurement.avgTagDist;
        double CameraOneLLTagCount   = CameraOneLLMeasurement.tagCount;

        double CameraTwoLLAvgTagArea = CameraTwoLLMeasurement.avgTagArea;
        double CameraTwoLLAvgTagDist = CameraTwoLLMeasurement.avgTagDist;
        double CameraTwoLLTagCount   = CameraTwoLLMeasurement.tagCount;

        // Limelight Tag Scores
        int CameraOneLLScore = 0;
        int CameraTwoLLScore = 0;

        // Pass Into Simulink
        Robot_Control_U.Vision_Num_Tags_Detected = CameraOneLLTagCount + CameraTwoLLTagCount;

        // Logic to evaluate which Limelight has "better" tags currently, based on amount of Tag on screen and tag distance
        // Sets input values based on that
        if (CameraOneLLAvgTagArea > CameraTwoLLAvgTagArea) {
            CameraOneLLScore++;
        } else if (CameraOneLLAvgTagArea < CameraTwoLLAvgTagArea) {
            CameraTwoLLScore++;
        }
        if (CameraOneLLAvgTagDist < CameraTwoLLAvgTagDist) {
            CameraOneLLScore++;
        } else if (CameraOneLLAvgTagDist > CameraTwoLLAvgTagDist) {
            CameraTwoLLScore++;
        }
        if (CameraOneLLTagCount == CameraTwoLLTagCount) {
            if (CameraOneLLScore > CameraTwoLLScore) {
                Robot_Control_U.Vision_RobotPoseFieldSpace_X = CameraOneLLMeasurement.pose.X().value();
                Robot_Control_U.Vision_RobotPoseFieldSpace_Y = CameraOneLLMeasurement.pose.Y().value();
            } else if (CameraTwoLLScore > CameraOneLLScore) {
                Robot_Control_U.Vision_RobotPoseFieldSpace_X = CameraTwoLLMeasurement.pose.X().value();
                Robot_Control_U.Vision_RobotPoseFieldSpace_Y = CameraTwoLLMeasurement.pose.Y().value();
            } else if (CameraTwoLLScore == CameraOneLLScore) {
                Robot_Control_U.Vision_RobotPoseFieldSpace_X = (CameraTwoLLMeasurement.pose.X().value() + CameraOneLLMeasurement.pose.X().value())/2;
                Robot_Control_U.Vision_RobotPoseFieldSpace_Y = (CameraTwoLLMeasurement.pose.Y().value() + CameraOneLLMeasurement.pose.Y().value())/2;
            }
        } else if (CameraOneLLTagCount > CameraTwoLLTagCount) {
                Robot_Control_U.Vision_RobotPoseFieldSpace_X = CameraOneLLMeasurement.pose.X().value();
                Robot_Control_U.Vision_RobotPoseFieldSpace_Y = CameraOneLLMeasurement.pose.Y().value();
        } else if (CameraOneLLTagCount < CameraTwoLLTagCount) {
                Robot_Control_U.Vision_RobotPoseFieldSpace_X = CameraTwoLLMeasurement.pose.X().value();
                Robot_Control_U.Vision_RobotPoseFieldSpace_Y = CameraTwoLLMeasurement.pose.Y().value();
        }

        Odometry_U.Vision_Gyro_Angle = CameraOneLLMeasurement.pose.Rotation().Degrees().value(); //Get the robot's orientation from the Limelight's pose estimation in degrees
        Odometry_U.Vision_Gyro_Angle_Status = !((CameraOneLLAvgTagArea > 0) && (CameraOneLLTagCount > 0));

        // Robot Pose Relative to Tag
        std::vector<double> c1TargetPoseRobotSpace = LimelightHelpers::getTargetPose_RobotSpace(nsLimelight::CameraOneCreateInfo.LimelightName);
        size_t c1VectorLength = c1TargetPoseRobotSpace.size();
        
        if (c1VectorLength > 1) {
            Robot_Control_U.Vision_c1_AprilTag_Valid   = 1;
            Robot_Control_U.Vision_c1_AprilTag_X_m     = c1TargetPoseRobotSpace.at(2);
            Robot_Control_U.Vision_c1_AprilTag_Y_m     = c1TargetPoseRobotSpace.at(0);
            Robot_Control_U.Vision_c1_AprilTag_Yaw_deg = c1TargetPoseRobotSpace.at(4);
        } else {
            Robot_Control_U.Vision_c1_AprilTag_Valid   = 0;
            Robot_Control_U.Vision_c1_AprilTag_X_m     = 0;
            Robot_Control_U.Vision_c1_AprilTag_Y_m     = 0;
            Robot_Control_U.Vision_c1_AprilTag_Yaw_deg = 0;
        }

        // Set object detection estimates to 0 since not detecting objects
        Robot_Control_U.Vision_c1_Object_Valid    = 0;
        Robot_Control_U.Vision_c1_Object_Area_pct = 0;
        Robot_Control_U.Vision_c1_Object_Hor_deg  = 0;
        Robot_Control_U.Vision_c1_Object_Ver_deg  = 0;

    /////////////////////////////////
    // OBJECT DETECTION PIPELINE
    /////////////////////////////////
    } else if (Current_Pipeline == 1)
    {
        // Set April tag data to 0
        Robot_Control_U.Vision_Num_Tags_Detected     = 0;
        Robot_Control_U.Vision_RobotPoseFieldSpace_X = 0;
        Robot_Control_U.Vision_RobotPoseFieldSpace_Y = 0;
        
        Robot_Control_U.Vision_c1_AprilTag_Valid   = 0;
        Robot_Control_U.Vision_c1_AprilTag_X_m     = 0;
        Robot_Control_U.Vision_c1_AprilTag_Y_m     = 0;
        Robot_Control_U.Vision_c1_AprilTag_Yaw_deg = 0;

        // Get object detection data
        bool hasTarget = LimelightHelpers::getTV(nsLimelight::CameraOneCreateInfo.LimelightName); // Returns true if a target is detected.
        if (hasTarget)
        {        
            Robot_Control_U.Vision_c1_Object_Valid    = 1;
            Robot_Control_U.Vision_c1_Object_Hor_deg  = LimelightHelpers::getTX(nsLimelight::CameraOneCreateInfo.LimelightName); // Horizontal offset from crosshair to target in degrees.
            Robot_Control_U.Vision_c1_Object_Ver_deg  = LimelightHelpers::getTY(nsLimelight::CameraOneCreateInfo.LimelightName); // Vertical offset from crosshair to target in degrees.
            Robot_Control_U.Vision_c1_Object_Area_pct = LimelightHelpers::getTA(nsLimelight::CameraOneCreateInfo.LimelightName); // Target area (0% to 100% of image).
        } else {
            Robot_Control_U.Vision_c1_Object_Valid    = 0;
            Robot_Control_U.Vision_c1_Object_Area_pct = 0;
            Robot_Control_U.Vision_c1_Object_Hor_deg  = 0;
            Robot_Control_U.Vision_c1_Object_Ver_deg  = 0;
        }

    /////////////////////////////////
    // UNEXPECTED PIPELINE
    /////////////////////////////////    
    } else {
        Robot_Control_U.Vision_Num_Tags_Detected = 0;        
        Robot_Control_U.Vision_RobotPoseFieldSpace_X = 0;
        Robot_Control_U.Vision_RobotPoseFieldSpace_Y = 0;

        Robot_Control_U.Vision_c1_AprilTag_Valid = 0;
        Robot_Control_U.Vision_c1_AprilTag_X_m = 0;
        Robot_Control_U.Vision_c1_AprilTag_Y_m = 0;
        Robot_Control_U.Vision_c1_AprilTag_Yaw_deg = 0;

        Robot_Control_U.Vision_c1_Object_Valid = 0;
        Robot_Control_U.Vision_c1_Object_Area_pct = 0;
        Robot_Control_U.Vision_c1_Object_Hor_deg = 0;
        Robot_Control_U.Vision_c1_Object_Ver_deg = 0;
    }
}

void Limelight::PostStepCallback() {}