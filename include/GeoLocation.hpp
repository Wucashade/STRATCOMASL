#ifndef GEOLOCATION_H
#define GEOLOCATION_H

// Declaration of the GeoLocation struct
struct GeoLocation {
    double latitude;
    double longitude;

    // Constructor
    GeoLocation(double lat, double lon);
    
    // Function to print the location
    void printLocation() const;
    void toCartesian(double& x, double& y) const;
};

#endif // GEOLOCATION_H