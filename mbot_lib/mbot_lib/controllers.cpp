/**
 * File: controllers.cpp
 *
 * Sources for feedback controllers.
 */

#include <mbot_lib/controllers.h>
#include <iostream>

float bangBangControl(float current, float setpoint, float scaling, float tolerance)
{
    // *** Task: Implement this function according to the header file *** //
    float error = setpoint - current;
    //std::cout << current << "\n";
    if(error < tolerance){
        std::cout << "driving to wall\n";
        return 0.2;
    }

    else if(error > tolerance){
        std::cout << "driving away from wall\n";
        return -0.2;
    }

    else{
        //std::cout << "staying still\n";
        return 0;
    }

    // *** End student code *** //
}

float pControl(float current, float setpoint, float kp)
{
    // *** Task: Implement this function according to the header file *** //

    return -0.1;

    // *** End student code *** //
}