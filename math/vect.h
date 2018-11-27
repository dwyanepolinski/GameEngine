//
// Created by john on 18.06.18.
//

#ifndef GAMEENGINE_VECTOR2D_H
#define GAMEENGINE_VECTOR2D_H

#include <cmath>
#include <iostream>
#include <ostream>

class vect {

public:

    double x = 0;
    double y = 0;

    vect() {};
    vect(double _x, double _y) : x(_x), y(_y){};
    vect(const vect &v);

    double len() const;
    vect normalize();
    double scalar_vect_multiply(const vect &v) const;
    vect multiply_by_scalar(const double scalar);
    void zero();

    vect operator+(const vect &v);
    vect operator-(const vect &v);
    vect operator*(const vect &v);
    vect &operator+=(const vect &v);
    vect &operator-=(const vect &v);
    vect &operator*=(const vect &v);

    friend std::ostream& operator<<(std::ostream &stream, const vect &v);

};


#endif //GAMEENGINE_VECTOR2D_H
