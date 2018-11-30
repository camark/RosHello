//
// Created by gm on 11/29/18.
//

#include "ros/ros.h"
#include "chapter2/chapter2_srv1.h"

bool add(chapter2::chapter2_srv1::Request &req,
         chapter2::chapter2_srv1::Response &resp)
{
    resp.sum=req.A+req.B+req.C;

    ROS_INFO("Request A=%d,B=%d,C=%d",(int)req.A,(int)req.B,(int)req.C);

    ROS_INFO("Send result:sum=%d",(int)resp.sum);

    return true;
}

int main(int argc,char* argv[]){
    ros::init(argc,argv,"ros_add_3_numbs_service");
    ros::NodeHandle n;

    ros::ServiceServer serviceServer=n.advertiseService("add_three",add);
    ROS_INFO("Ready to add 3 nums:");
    ros::spin();

    return 0;
}

