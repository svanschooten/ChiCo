#include <std_msgs/Bool.h>
#include <ros/ros.h>

using namespace std;

void shutdown(const std_msgs::Bool::ConstPtr&);

int main(int argc, char **argv)
{
  ros::init(argc, argv, "interaction_controller"); 
  ros::NodeHandle n; 
  ros::Subscriber shutdown = n.subscribe("shutdown", 1, shutdown);

  ros::spin();

  return 0;
} 

/*! \brief Controll method to shutdown this ROS node when the command is given.

This method will shutdown this node when the command is given by the console.
\param b The message containing the command. Nothing is done with the command since we know what it will be when this message is received.
*/
void shutdown(const std_msgs::Bool::ConstPtr& b){
  ros::shutdown();
}