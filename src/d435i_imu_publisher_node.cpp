#include "d435i_imu_publisher.hpp"

int main(int argc,char *argv[]){
    ros::init(argc, argv, "d435i_imu_publisher_node");
    d435i_imu_publisher d_imu;
    ros::spin();
}