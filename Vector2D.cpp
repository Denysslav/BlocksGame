/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<math.h>
#include "header/Vector2D.h"

Vector2D::Vector2D(float x, float y) : x(x), y(y){}

float Vector2D::getX()
{
    return x;
}

float Vector2D::getY()
{
    return y;
}

void Vector2D::setX(float xAxis)
{
    x = xAxis;
}

void Vector2D::setY(float yAxis)
{
    y = yAxis;
}

float Vector2D::length()
{
    return sqrt(x * x + y * y);
}

void Vector2D::normalize()
{
    float l = length();
    if ( l > 0)
    {
        (*this) *= 1 / l;
    }
}