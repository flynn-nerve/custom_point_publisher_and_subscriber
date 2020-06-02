// Publish random x, y, z values (geometry_msgs/Point) on topic /obstacles_detected

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"

int main(int argc, char **argv)
{
  // init node, create nodehandle and start async spinner
  ros::init(argc, argv, "point_pub");
  ros::NodeHandle n;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  // create and initialize publisher for randomized x, y, z values
  ros::Publisher point_pub=n.advertise<geometry_msgs::Point>("obstacles_detected", 1);
  // set rate to 0.5Hz
  ros::Rate rate(0.5);

  while (ros::ok())
  {
    // create a point "point" with random x, y, and z values (between 0 and 29) then publish
    geometry_msgs::Point point;
    point.x = rand() % 30;
    point.y = rand() % 30;
    point.z = rand() % 30;

    point_pub.publish(point);
    rate.sleep();
  }

  ros::waitForShutdown();
  return 0;
}
