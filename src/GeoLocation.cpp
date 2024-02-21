#include "../include/GeoLocation.hpp"
#include <iostream>

const double earthRadius = 6371.0;

// Implementation of the constructor
GeoLocation::GeoLocation(double lat, double lon) : latitude(lat), longitude(lon) {}

// Implementation of the printLocation function
void GeoLocation::printLocation() const {
    std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
}

void GeoLocation::toCartesian(double& x, double& y) const {
    double latRad = latitude * M_PI / 180.0;
    double lonRad = longitude * M_PI / 180.0;

    x = earthRadius * std::cos(latRad) * std::cos(lonRad);
    y = earthRadius * std::cos(latRad) * std::sin(lonRad);
}