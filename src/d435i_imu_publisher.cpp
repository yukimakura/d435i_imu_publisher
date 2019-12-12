#include "d435i_imu_publisher.hpp"

d435i_imu_publisher::d435i_imu_publisher(){
    gyro_sub_ = nh_.subscribe("/camera/gyro/sample", 10, &d435i_imu_publisher::gyro_cb_,this);
    accel_sub_ = nh_.subscribe("/camera/accel/sample", 10, &d435i_imu_publisher::accel_cb_,this);
    fusion_imu_pub_ = nh_.advertise<sensor_msgs::Imu>("/imu/data_raw", 10);
}

void d435i_imu_publisher::gyro_cb_(const sensor_msgs::Imu data){
    gyro_buffer_ = data;
};
void d435i_imu_publisher::accel_cb_(const sensor_msgs::Imu dara){
    gyro_buffer_.header = dara.header;
    gyro_buffer_.linear_acceleration.x = dara.linear_acceleration.x;
    gyro_buffer_.linear_acceleration.y = dara.linear_acceleration.y;
    gyro_buffer_.linear_acceleration.z = dara.linear_acceleration.z;
    
    fusion_imu_pub_.publish(gyro_buffer_);
};