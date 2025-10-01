/**
 * File: wall_follower.cpp
 *
 * Controls robot to follow a wall. 
 */

#include <iostream>
#include <cmath>

#include <signal.h>

#include <mbot_bridge/robot.h>

#include <mbot_lib/behaviors.h>
#include <mbot_lib/controllers.h>
#include <mbot_lib/utils.h>


std::vector<float> up = {0, 0, 1};
std::vector<float> drivedirectiontowall = {0, 0, 0};
std::vector<float> drivedirection = {0, 0, 0};

bool ctrl_c_pressed;
void ctrlc(int)
{
    ctrl_c_pressed = true;
}


int main(int argc, const char *argv[])
{
    signal(SIGINT, ctrlc);
    signal(SIGTERM, ctrlc);

    // Initialize the robot.
    mbot_bridge::MBot robot;
    // Create empty vectors to store the scan data.
    std::vector<float> ranges;
    std::vector<float> thetas;

    while (true) {

        robot.readLidarScan(ranges, thetas);

        // Get the distance to the wall.
        int min_idx = findMinNonzeroDist(ranges);
        float dist_to_wall = ranges[min_idx];
        float angle_to_wall = thetas[min_idx];
        drivedirection = rayConversionVector(angle_to_wall);
        drivedirectiontowall = drivedirection;
        drivedirection = crossProduct(drivedirection, up);
        std::cout << "distance to wall: " << dist_to_wall << "\n";
        float correctionconstant = pControl(dist_to_wall, 0.5, -6);

        drivedirection[0] = drivedirection[0] + drivedirectiontowall[0] * correctionconstant;
        drivedirection[1] = drivedirection[1] + drivedirectiontowall[1] * correctionconstant;

        robot.drive(drivedirection[0]/4, drivedirection[1]/4, 0);
        
        // *** Task: Implement wall following *** //

        // *** End student code *** //

        if (ctrl_c_pressed) break;
    }

    // Stop the robot.
    robot.stop();
    return 0;
}
