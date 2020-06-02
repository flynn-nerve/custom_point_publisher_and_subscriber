// Subscribe to /obstacles_detected and publish x, y, z values as geometry_msg/Point within custom message (id_point.msg) on topic /registered_obstacles

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"
#include "custom_point_publisher_and_subscriber/id_point.h"

// create global variable i for id counting
int i;

// create publisher and subscriber
ros::Publisher point_with_id;
ros::Subscriber obstacle_point;

// obstacle point subscriber callback function
// take point (msg) x, y and z values, store in id_point message type and assign an id
// publish custom message on previously defined topic 
// then increment id by 1 (sequential ids)
void point_sub_callback(const geometry_msgs::Point msg)
{
   custom_point_publisher_and_subscriber::id_point info;
   
   info.point.x = msg.x;
   info.point.y = msg.y;
   info.point.z = msg.z;

   info.id = std::to_string(i);

   point_with_id.publish(info);

   i+=1;
}

int main(int argc, char **argv)
{
  // init node, create nodehandle and start async spinner
  ros::init(argc, argv, "sub_pub_id");
  ros::NodeHandle n;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  // initialize publisher and subscriber
  obstacle_point=n.subscribe("/obstacles_detected", 1, point_sub_callback);
  point_with_id=n.advertise<custom_point_publisher_and_subscriber::id_point>("/registered_obstacles", 1);

  // initialize id counter value
  i = 0;

  while (ros::ok())
  {
    // do nothing
  }

  ros::waitForShutdown();
  return 0;
}
