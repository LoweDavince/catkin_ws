#include "ros/ros.h"
#include "std_msgs/String.h"
#include "turtlesim/Pose.h"
#include <std_msgs/Float64.h>
#include <sstream>

#include <tf/transform_listener.h>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "template");

  ros::NodeHandle n;

  ros::Publisher pub;
  pub = n.advertise<std_msgs::Float64>("/rrbot/joint1_position_controller/command",100);
  ros::Rate loop_rate(1);


  std_msgs::Float64 cmd;
  turtlesim::Pose pose;

  cmd.data = 1.1;


  tf::TransformListener listener;


  while (ros::ok())
  {

   tf::StampedTransform transform;
    try{
      listener.lookupTransform("/link1", "/link3",
                               ros::Time(0), transform);
    }
    catch (tf::TransformException &ex) {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }
    std::cout<<transform.getOrigin().x()<<" "<<transform.getOrigin().y()<<" "<<transform.getOrigin().z()<<std::endl;








    cmd.data= cmd.data + 0.1;
    pub.publish(cmd);
    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}
