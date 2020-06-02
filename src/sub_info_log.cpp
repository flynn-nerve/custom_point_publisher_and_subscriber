// Subscribe to /registered_obstacles and log custom message info as human readable info output on command line ("Detected obstacle <id> at position <x>, <y>, <z>.")

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"
#include "custom_point_publisher_and_subscriber/id_point.h"

// callback function for registered obstacle subscriber
// take obstacle (msg) id and point.x/y/z, and display in human readable info output in console
void reg_obs_callback(const custom_point_publisher_and_subscriber::id_point msg)
{
  // log obstacle id, x, y, and z position in console (ROS_INFO) when received on /registered_obstacle topic
  ROS_INFO("Detected obstacle %s at position %.0f, %.0f, %.0f.", msg.id.c_str(), msg.point.x, msg.point.y, msg.point.z);
}

int main(int argc, char **argv)
{
  // init node, create nodehandle and start async spinner
  ros::init(argc, argv, "sub_info_log");
  ros::NodeHandle n;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  // create and initialize subscriber to listen for messages on /registerd_obstacles topic
  ros::Subscriber registered_obstacle_sub=n.subscribe("/registered_obstacles", 1, reg_obs_callback);

  while (ros::ok())
  {
    // do nothing
  }

  ros::waitForShutdown();
  return 0;
}
