//
//  main.cpp
//  Antenna_Control
//
//  Created by Ben Francis on 5/9/20.
//  Copyright © 2020 Ben Francis. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "map_gps_to_ang.cpp"
#include <math.h>       /* atan, sqrt, fmod */
using namespace std;

int main(int argc, const char * argv[]) {
    
    // insert code here...
    
//    // TESTING
    int rov_lat = (47.60621 + 90) * 1e6; // Seattle, for testing
    int rov_long = -122.33207 + 180;
    int ant_lat = 47.25288 + 90; // Tacoma
    int ant_long = -122.44429 + 180;
    int start_ang = 457800; // Orig: 45.78 deg

    // Initialize angle
    double ang;
//
    ang = gps_to_ang(rov_lat, rov_long, ant_lat, ant_long, start_ang);

    printf("ang = %f", ang);

    return 0;
}




