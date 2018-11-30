//
// Created by gm on 11/29/18.
//

#include "ros/ros.h"
#include "chapter2/chapter2_msg1.h"

void chatterCallback(const chapter2::chapter2_msg1::ConstPtr& msg)
{
    ROS_INFO("I heard:[%d] [%d] [%d]",msg->A,msg->B,msg->C);
}

int main(int argc,char* argv[]){
    ros::init(argc,argv,"example_b");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("message",1000,chatterCallback);
    ros::spin();

    return 0;
}


