//
// Created by john on 18.06.18.
//

#ifndef GAMEENGINE_VECTOR2D_H
#define GAMEENGINE_VECTOR2D_H

#include <cmath>
#include <iostream>
#include <ostream>

class Vector2D {

public:

    double x = 0;
    double y = 0;

    Vector2D(double _x, double _y) : x(_x), y(_y){};
    Vector2D(const Vector2D &v);

    double len() const;
    Vector2D normalize();
    double scalar_vect_multiply(const Vector2D &v) const;
    Vector2D multiply_by_scalar(const double scalar);

    Vector2D operator+(const Vector2D &v);
    Vector2D operator-(const Vector2D &v);
    Vector2D operator*(const Vector2D &v);
    Vector2D &operator+=(const Vector2D &v);
    Vector2D &operator-=(const Vector2D &v);
    Vector2D &operator*=(const Vector2D &v);

    friend std::ostream& operator<<(std::ostream &stream, const Vector2D &v);

};


#endif //GAMEENGINE_VECTOR2D_H
