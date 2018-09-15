//
// Created by john on 18.06.18.
//

#include "vect.h"

vect vect::operator+(const vect &v) {
    return vect(x + v.x, y + v.y);
}

vect vect::operator-(const vect &v) {
    return vect(x - v.x, y - v.y);
}

double vect::len() const {
    return sqrt((x * x) + (y * y));
}

vect vect::operator*(const vect &v) {
    return vect(x * v.x, y * v.y);
}

double vect::scalar_vect_multiply(const vect &v) const {
    return (x * v.x) + (y * v.y);
}

vect vect::multiply_by_scalar(const double scalar) {
    return vect(x * scalar, y * scalar);
}

std::ostream& operator<<(std::ostream &stream, const vect &v) {
    stream << "vect(" << v.x << "," << v.y << ")";
    return stream;
}

vect &vect::operator+=(const vect &v) {
    this->x += v.x;
    this->y += v.y;
    return *this;
}

vect &vect::operator-=(const vect &v) {
    this->x -= v.x;
    this->y -= v.y;
    return *this;
}

vect &vect::operator*=(const vect &v) {
    this->x *= v.x;
    this->y *= v.y;
    return *this;
}

vect vect::normalize() {
    double length = len();
    double _x = x, _y = y;
    if(length){
        _x /= length;
        _y /= length;
    }
    return vect(_x, _y);
}

vect::vect(const vect &v) {
    x = v.x;
    y = v.y;
}

