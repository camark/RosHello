//
// Created by gm on 11/29/18.
//

#include "ros/ros.h"
#include "chapter2/chapter2_msg1.h"

int main(int argc,char* argv[])
{
    ros::init(argc,argv,"example_msg_a");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<chapter2::chapter2_msg1>("message",1000);

    ros::Rate loop_rate(10);

    while(ros::ok()){

        chapter2::chapter2_msg1 msg;
        msg.A=100;
        msg.B=300;
        msg.C=500;

        chatter_pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

