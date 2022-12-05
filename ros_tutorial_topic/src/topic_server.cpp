#include <ros/ros.h>
#include "ros_tutorial_topic/AddTwoInts.h"




bool add( ros_tutorial_topic::AddTwoInts::Request& req,
			ros_tutorial_topic::AddTwoInts::Response& res )
{
	ros::Rate loop_rate( 1 );
	loop_rate.sleep();
	res.sum = req.a + req.b;
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: [%ld]", (long int)res.sum);
	return false;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "add_two_ints_server");
	ros::NodeHandle n;

	ros::ServiceServer service = n.advertiseService("add_two_ints", add);
	ROS_INFO("Ready to add two ints.");
	ros::spin();

	return 0;
}