#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>
#include <std_msgs/Float64.h>

namespace gazebo
{
class WorldPluginTutorial : public WorldPlugin
{
public:
  WorldPluginTutorial() : WorldPlugin()
  {

    // Make sure the ROS node for Gazebo has already been initialized
    if (!ros::isInitialized())
    {
      ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
        << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
      return;
    }

    ROS_INFO("Hello World!");
    ros::NodeHandle n;
    ros::Publisher pub;
    pub = n.advertise<std_msgs::Float64>("/rrbot/joint1_position_controller/command",1);
  }

  void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
  {
  }

};
GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)
}
