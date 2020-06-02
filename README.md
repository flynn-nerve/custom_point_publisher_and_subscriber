Brian Flynn
A package (C++) for learninghow to write a custom message, publisher node, subscriber node, publisher and subscriber node, wrapped up with a launch file that will launch all of the nodes and show the functional example

3 separate nodes:
	Node 1 - point\_pub.cpp
	Node 2 - sub\_pub_id.cpp
	Node 3 - sub\_info_log.cpp

1 launch file:
	detect\_obstacles.launch

# To Run the Example:
roslaunch custom\_point\_publisher_\and\_subscriber detect\_obstacles.launch


## Random Number (Point) Generator and Publisher - (point\_pub.cpp)
    Publish random x, y, z values [geometry_msgs/Point] on topic "/obstacles_detected"


## Subscriber and Publisher - (sub\_pub\_id.cpp)
    Subscribe to "/obstacles\_detected" and publish x, y and z values as [geometry_msg/Point] within custom message (id_point.msg) on topic "/registered_obstacles"


## Subscriber and Info (Point) Logger - (sub\_info\_log.cpp)
    Subscribe to "/registered_obstacles" and log custom message info as human readable info output on command line ("Detected obstacle <id> at position <x>, <y>, <z>.")


