/**
 * File: utils.cpp
 * 
 * Sources for functions for handling common tasks like working with geometry and interpreting lidar data.
 */

#include <mbot_lib/utils.h>
#include <cmath>

//Converts the distance and angle into x and y cartisean coords.
std::vector<float> rayConversionCartisean(float dist, float angle) 
{
    // *** Task: Implement this function according to the header file *** //
    float vx = dist * std::cos(angle);
    float vy = dist * std::sin(angle);
    return std::vector<float>{vx, vy};

    // *** End student code *** //
}
//Converts angle to object into vector to object.
std::vector<float> rayConversionVector(float angle) 
{
    // *** Task: Implement this function according to the header file *** //
    float vx = 1 * std::cos(angle);
    float vy = 1 * std::sin(angle);

    return std::vector<float>{vx, vy, 0};


    // *** End student code *** //
}
//Finds the index of the minimum distance in the given vector of Lidar ranges.
int findMinDist(const std::vector<float>& ranges)
{   
    
    float lowestvalue = 99999;
    float currentvalue;
    for (int i = 0; i < ranges.size(); i++){ //finding the number of the lowest value through the entire vector
        currentvalue = ranges[i];
        if (currentvalue < lowestvalue){
            lowestvalue = currentvalue;}
    } 
    
    for (int i = 0; i < ranges.size(); i++){ //finding the index value
        currentvalue = ranges[i];
        if(currentvalue == lowestvalue){

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

    std::vector<float> resultvector(v1.size());

    for(int i=0; i< v1.size(); ++i){

        resultvector[i] = v1[i] + v2[i];

    }

    return resultvector;

    // *** End student code *** //
}

std::vector<float> crossProduct(const std::vector<float>& v1, const std::vector<float>& v2) 
{

    float productx = v1[1]*v2[2] - v1[2]*v2[1];
    float producty = v1[2]*v2[0] - v1[0]*v2[2];
    float productz = v1[0]*v2[1] - v1[1]*v2[0];

    return std::vector<float>{productx, producty, productz};

    // *** End student code *** //
}

void transformVector2D(std::vector<float>& xy, float theta) 
{
    // *** Task: Implement this function according to the header file *** //

    // *** End student code *** //
}