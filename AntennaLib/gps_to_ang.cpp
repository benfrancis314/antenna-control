//
//  map_gps_to_ang.cpp
//  Antenna_Control
//
//  Created by Ben Francis on 5/9/20.
//  Copyright © 2020 Ben Francis. All rights reserved.
//

#include <iostream>
#include <stdio.h>
// #include "map_gps_to_ang.hpp"
#include <math.h>       /* atan, sqrt, fmod */

// double main(int argc, char* argv[]) {
//     int rov_long
//     int ant_lat
//     int ant_long
//     dou
// }

double gps_to_ang(int rov_lat, int rov_long, int ant_lat, int ant_long, int start_ang) {
    rov_long = rov_long/1e7; // convert to normal lat/long units
    rov_lat = rov_lat/1e7;
    ant_long = ant_long/1e7;
    ant_long = ant_long/1e7;
    start_ang = start_ang / 1e4; // convert to normal angle units
    
    // Calculate distance in meters, desired angle
    double conv_fact = 111226.2; // meters per degree at ~45 deg lat
    double diff_lat = (rov_long - ant_long) * conv_fact; // Find diff btwn lat & longs
    double diff_long = (rov_lat - ant_lat) * conv_fact;
    double ang_want;
    if (diff_long == 0) {
        ang_want = 0; // just to give it a value, prevent divison by 0
    } else {
        ang_want = atan(diff_lat/diff_long); // The angle we want; requires orientation.
    }
    double dist = sqrt(diff_lat*diff_lat + diff_long*diff_long); // use later, for determining how often to run program, if antenna should be updated
    
    if (diff_lat >= 0 && diff_lat <= 0) { // orient the angle as an azimuth (relative North, clockwise)
        ang_want = fmod((270 - ang_want), 360.0);
    }
    else if (diff_lat >= 0 && diff_lat >= 0) {
        ang_want = fmod((90 - ang_want), 360.0);
    } else if (diff_lat <= 0 && diff_lat <= 0) {
        ang_want = fmod((90 + ang_want), 360.0);
    } else if (diff_lat <= 0 && diff_lat >= 0) {
        ang_want = fmod((270 - ang_want), 360.0);
    } // in theory, that should cover all cases.
    
    double ang_change = ang_want - start_ang;
    
    return ang_change;
}

// int rov_lat = (47.60621 + 90) * 1e6; // Seattle, for testing
// int rov_long = -122.33207 + 180;
// int ant_lat = 47.25288 + 90; // Tacoma
// int ant_long = -122.44429 + 180;
// int start_ang = 457800; // Orig: 45.78 deg

// double ang = gps_to_ang(int rov_lat, int rov_long, int ant_lat, int ant_long, int start_ang);

// printf(ang);


