#include <ros/ros.h>
#include <std_msgs/String.h>

void sub_callback( const std_msgs::String::ConstPtr& msg )
{
	ROS_INFO( "I heard :: [%s]", msg->data.c_str() );
}

int main( int argc, char** argv )
{
	ros::init( argc, argv, "topic_subscriber" );
	ros::NodeHandle nh;
	ros::Subscriber ros_tutorial_sub = nh.subscribe( "chatter", 1000, sub_callback );

	ros::spin();

	return 0;
}

