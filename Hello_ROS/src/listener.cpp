#include"ros/ros.h"
#include"std_msgs/String.h"
//接受到订阅的消息，进入回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
//将接收到的消息打印出来
ROS_INFO("I heard:[%s]",msg->data.c_str());
}

int main(int argc,char **argv)
{
//初始化ROS节点
ros::init(argc,argv,"listener");
//创建节点句柄
ros::NodeHandle n;
//创建一个Subscriber ,订阅名为demo的话题，注册回调函数chatterCallback
ros::Subscriber sub = n.subscribe("demo",1000,chatterCallback);
//循环等待回调函数
ros::spin();
return 0;
}
