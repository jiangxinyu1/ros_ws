#include <ros/ros.h>
#include <sstream>
#include "std_msgs/String.h"

int main(int argc, char  **argv)
{
    // 初始化ros节点"example1_a"
    ros::init(argc, argv, "example1_a");
    // 实例化节点，创建发布者，设置1000的缓存区
    // 将发布的主题和类型的名称告诉节点管理器
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("message", 1000);
    // 设置发送数据的频率为10HZ
    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        // 创建一个消息变量msg
        std_msgs::String msg;
        // 给msg变量赋值
        std::stringstream ss;
        ss << "I am the example a node.";
        msg.data = ss.str();
        // 发布消息
        chatter_pub.publish(msg);
        // 处理ros的内部函数
        ros::spinOnce();
        // 10HZ挂起
        loop_rate.sleep();
    }

    return 0;
}