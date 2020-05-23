// #include 

#include <iostream>
#include "gps_to_ang.cpp"
#include <math.h>       /* atan, sqrt, fmod */

int main(int argc, const char * argv[]) {
    
    // insert code here...
    
//    // TESTING
    int rov_lat = (47.60621 + 90) * 1e6; // Seattle, for testing
    int rov_long = -122.33207 + 180;
    int ant_lat = 47.25288 + 90; // Tacoma
    int ant_long = -122.44429 + 180;
    int start_ang = 457800; // Orig: 45.78 deg
//
    gps_to_ang(rov_lat, rov_long, ant_lat, ant_long, start_ang);
//
    std::cout << "test";
    
//    std::cout << ans;
    return 0;
}