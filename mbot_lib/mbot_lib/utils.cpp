/**
 * File: utils.cpp
 * 
 * Sources for functions for handling common tasks like working with geometry and interpreting lidar data.
 */

#include <mbot_lib/utils.h>

//Converts the distance and angle into x and y cartisean coords.
std::vector<float> rayConversionCartisean(float dist, float angle) 
{
    // *** Task: Implement this function according to the header file *** //

    return std::vector<float>();

    // *** End student code *** //
}
//Converts angle to object into vector to object.
std::vector<float> rayConversionVector(float angle) 
{
    // *** Task: Implement this function according to the header file *** //

    float vx = 1 * std::cos(angle);
    float vy = 1 * std::sin(angle);

    return std::vector<float>{vx, vy};


    // *** End student code *** //
}
//Finds the index of the minimum distance in the given vector of Lidar ranges.
int findMinDist(const std::vector<float>& ranges)
{   float lowestvalue = ranges[0];
    float currentvalue = ranges[0];
    int lowestvalueindex = 0;
    for (int i = 0; i < ranges.size(); i++){ //finding the number of the lowest value through the entire vector
        currentvalue = ranges[i];
        if (currentvalue < lowestvalue){

            lowestvalue = currentvalue;
        }
    }
    
    for (int i = 0; i < ranges.size(); i++){ //finding the index value
        currentvalue = ranges[i];
        if(currentvalue == lowestvalueindex){

        return i;
        }
    }

    return -1;


    }


//Finds the index of the minimum distance in the given vector of Lidar ranges,
//skipping values of zero, which indicate bad readings.
int findMinNonzeroDist(const std::vector<float>& ranges)
{
    float lowestvalue = 99999;
    float currentvalue;
    for (int i = 0; i < ranges.size(); i++){ //finding the number of the lowest value through the entire vector
        currentvalue = ranges[i];
        if (currentvalue != 0){
        if (currentvalue < lowestvalue){
            lowestvalue = currentvalue;}
        }
    } 
    
    for (int i = 0; i < ranges.size(); i++){ //finding the index value
        currentvalue = ranges[i];
        if(currentvalue == lowestvalue){

        return i;
        }
    }

    return -1;
}

std::vector<float> vectorAdd(const std::vector<float>& v1, const std::vector<float>& v2) 
{
    // *** Task: Implement this function according to the header file *** //
    //* Performs a cross product between two 3D vectors.
    return std::vector<float>();

    // *** End student code *** //
}

std::vector<float> crossProduct(const std::vector<float>& v1, const std::vector<float>& v2) 
{
    // *** Task: Implement this function according to the header file *** //
     //* Transforms a 2D vector into new coordinate frame that is rotated theta degrees 
     //* counter clockwise from the coordinate frame in which it is currently represented.
    return std::vector<float>();

    // *** End student code *** //
}

void transformVector2D(std::vector<float>& xy, float theta) 
{
    // *** Task: Implement this function according to the header file *** //

    // *** End student code *** //
}
