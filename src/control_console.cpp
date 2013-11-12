#include <stdio.h>
#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <ros/ros.h>

using namespace std;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "control_console"); 
  ros::NodeHandle n; 
  ros::Publisher shutdown = n.advertise<std_msgs::Bool>("shutdown", 1);

  bool exit_cmd = false;

  while(!exit_cmd){
    string cmd;
    printf(">> "); 
    cin >> cmd;
    if(cmd.compare("exit") == 0){
      exit_cmd = true;
      std_msgs::Bool msg;
      msg.data = true;
      shutdown.publish(msg);
    }else{
      printf("Please use the commands exit'.\n");
    }
  }
  
  ros::shutdown();
  
  return 0;
} 
