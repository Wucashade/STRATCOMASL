#ifndef CARTESIANLOCATION_H
#define CARTESIANLOCATION_H

// Declaration of the CartesianCoordinates struct
struct CartesianLocation {
    double x;
    double y;

    // Constructor
    CartesianLocation(double xVal, double yVal);

    // Function to calculate distance between two points
    double distanceTo(const CartesianLocation& other) const;
};

#endif