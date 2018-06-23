//
// Created by john on 18.06.18.
//

#include "Vector2D.h"

Vector2D Vector2D::operator+(const Vector2D &v) {
    return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator-(const Vector2D &v) {
    return Vector2D(x - v.x, y - v.y);
}

double Vector2D::len() const {
    return sqrt((x * x) + (y * y));
}

Vector2D Vector2D::operator*(const Vector2D &v) {
    return Vector2D(x * v.x, y * v.y);
}

double Vector2D::scalar_vect_multiply(const Vector2D &v) const {
    return (x * v.x) + (y * v.y);
}

Vector2D Vector2D::multiply_by_scalar(const double scalar) {
    return Vector2D(x * scalar, y * scalar);
}

std::ostream& operator<<(std::ostream &stream, const Vector2D &v) {
    stream << "Vector2D[" << v.x << "," << v.y << "]";
    return stream;
}

Vector2D &Vector2D::operator+=(const Vector2D &v) {
    this->x += v.x;
    this->y += v.y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &v) {
    this->x -= v.x;
    this->y -= v.y;
    return *this;
}

Vector2D &Vector2D::operator*=(const Vector2D &v) {
    this->x *= v.x;
    this->y *= v.y;
    return *this;
}

Vector2D &Vector2D::normalize() {
    double length = len();
    if(length){
        x /= length;
        y /= length;
    }
    return *this;
}

