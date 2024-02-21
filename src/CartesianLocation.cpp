#include "../include/CartesianLocation.hpp"
#include <cmath>

// Implementation of the constructor
CartesianLocation::CartesianLocation(double xVal, double yVal) : x(xVal), y(yVal) {}

// Implementation of the distanceTo function
double CartesianLocation::distanceTo(const CartesianLocation& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}