#ifndef D435I_IMU_PUBLISHER_HPP
#define D435I_IMU_PUBLISHER_HPP
#include "ros/ros.h"
#include "sensor_msgs/Imu.h"

class d435i_imu_publisher{
    private:

        void gyro_cb_(const sensor_msgs::Imu);
        void accel_cb_(const sensor_msgs::Imu);
        ros::NodeHandle nh_;
        sensor_msgs::Imu gyro_buffer_;
        ros::Subscriber gyro_sub_;
        ros::Subscriber accel_sub_;
        ros::Publisher fusion_imu_pub_;

    public:
        d435i_imu_publisher();

};
#endif //D435I_IMU_PUBLISHER_HPP