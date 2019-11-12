#include <ros/ros.h>
#include <sstream>
#include <std_msgs/String.h>

void messageCallBack(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("I HEARD : [%s]",msg->data.c_str());
}

int main(int argc,  char  **argv)
{
    ros::init (argc,argv,"example1_b") ;
    ros::NodeHandle n;
    ros::Subscriber chatter_sub = n.subscribe("message",1000,messageCallBack);
    ros::spin();
    return 0;
}