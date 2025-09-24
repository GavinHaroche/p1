/**
 * File: drive_star.cpp
 *
 * Code to drive in a five-pointed star shape without turning. 
 */

#include <iostream>
#include <cmath>

#include <signal.h>

#include <mbot_bridge/robot.h>

#include <mbot_lib/utils.h>


bool ctrl_c_pressed;
void ctrlc(int)
{
    ctrl_c_pressed = true;
}

std::vector<int> angles = {0, -144, 72, -72, 144};
std::vector<float> drivedirection = {0, 0};

int main(int argc, const char *argv[])
{
    signal(SIGINT, ctrlc);
    signal(SIGTERM, ctrlc);

    // Initialize the robot.
    mbot_bridge::MBot robot;

    // *** Task: Drive in a five pointed star *** //
    drivedirection = rayConversionVector((angles[0])*(M_PI/180));
    robot.drive(drivedirection[0], drivedirection[1], 0);
    sleepFor(2);
    drivedirection = rayConversionVector((angles[1])*(M_PI/180));
    robot.drive(drivedirection[0], drivedirection[1], 0);
    sleepFor(2);
    drivedirection = rayConversionVector((angles[2])*(M_PI/180));
    robot.drive(drivedirection[0], drivedirection[1], 0);
    sleepFor(2);
    drivedirection = rayConversionVector((angles[3])*(M_PI/180));
    robot.drive(drivedirection[0], drivedirection[1], 0);
    sleepFor(2);
    drivedirection = rayConversionVector((angles[4])*(M_PI/180));
    robot.drive(drivedirection[0], drivedirection[1], 0);
    sleepFor(2);
    // *** End student code *** //

    // Stop the robot.
    robot.stop();
}
