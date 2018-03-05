//#include "ros/ros.h"
#include "rclcpp/rclcpp.hpp"
//#include "geometry_msgs/Twist.h"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/string.hpp"

//#include "unistd.h"
//#include <iostream>
//#include <string>
//using namespace std;


int main(int argc,char **argv )
{
	//ros::init(argc,argv,"message_sender");
	//ros::NodeHandle n;
	rclcpp::init(argc, argv);
	auto node = rclcpp::Node::make_shared("message_sender");
	//ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
	auto twist_pub = node -> create_publisher<geometry_msgs::msg::Twist>("/cmd_vel",rmw_qos_profile_default);
	//ros::Rate loop_rate(1);
	rclcpp::Rate loop_rate(10);	
	//geometry_msgs::Twist twist;
	auto twist = std::make_shared<geometry_msgs::msg::Twist>();
	
	twist->linear.x=0.0;
 	twist->linear.y=0.0;
  	twist->linear.z=0.0;
	twist->angular.x=0.0;
  	twist->angular.y=0.0;
  	twist->angular.z=0.0;
	//while(ros::ok())
	while(rclcpp::ok())	
	{
		twist->linear.x = 0.2;
		//pub.publish (twist);
		twist_pub->publish(twist);			
		//ros::spinOnce();
		rclcpp::spin_some(node);
		loop_rate.sleep();

	}
	rclcpp::shutdown();
	return 0;
}
