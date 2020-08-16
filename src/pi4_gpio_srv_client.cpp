#include "ros/ros.h"
#include "pi4_gpio/DigitalWrite.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pi4_gpio_srv_client");
  if(argc != 3)
  {
    ROS_INFO("Usage: pi4_gpio_srv_client pin state");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<pi4_gpio::DigitalWrite>("digital_write");

  pi4_gpio::DigitalWrite srv;
  srv.request.pin = atoll(argv[1]);
  srv.request.state = atoll(argv[2]);
  if(client.call(srv))
  {
    ROS_INFO("Request Success...");
  }
  else
  {
    ROS_ERROR("Failed to call service digital_write");
    return 1;
  }

  return 0;
}
