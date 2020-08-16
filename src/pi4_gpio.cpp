#include "pi4_gpio/pi4_gpio.h"

std::string node_name = ros::this_node::getName();

bool write(pi4_gpio::DigitalWrite::Request &req, pi4_gpio::DigitalWrite::Response &res)
{
  ROS_INFO("Service Request: pin=%ld, state=%ld", (int)req.pin, (int)req.state);
  pinMode((int)req.pin, OUTPUT);
  digitalWrite((int)req.pin, (int)req.state);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pi4_gpio");

  node_name = ros::this_node::getName();
  ROS_INFO_STREAM(node_name << " : node started...");

  ros::NodeHandle nh;

  ros::ServiceServer service = nh.advertiseService("digital_write", write);
  ros::Rate loop_rate(FREQUENCY);

  wiringPiSetupGpio();

  for(uint8_t i = 0; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }

  while(ros::ok())
  {
    ros::spinOnce();

    loop_rate.sleep();
  }
}
