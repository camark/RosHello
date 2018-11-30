//
// Created by gm on 11/29/18.
//

#include "ros/ros.h"
#include "chapter2/chapter2_srv1.h"

int main(int argc,char** argv){
    ros::init(argc,argv,"example_add_3_num_client");

    if(argc<4){
        ROS_INFO("usage:exampleadd_client_a A B C");
        return 1;
    }


    ros::NodeHandle n;
    ros::ServiceClient serviceClient=n.serviceClient<chapter2::chapter2_srv1>("add_three");
    //ros::Subscriber sub = n.subscribe("message",1000,chatterCallback);

    chapter2::chapter2_srv1 svr;
    svr.request.A=atoll(argv[1]);
    svr.request.B=atoll(argv[2]);
    svr.request.C=atoll(argv[3]);

    if(serviceClient.call(svr)){
        ROS_INFO("get service result:%d",svr.response.sum);
        return 0;
    } else{
        ROS_ERROR("call service error");
        return 1;
    }


}

