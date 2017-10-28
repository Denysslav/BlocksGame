/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector2D.h
 * Author: denislav
 *
 * Created on October 25, 2017, 8:48 AM
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
    public:
        Vector2D()
        {
            x = 0.;
            y = 0.;
        };
        Vector2D(float x, float y);
        float getX();
        float getY();

        void setX(float xAxis);
        void setY(float yAxis);

        float length();

        void normalize();

        Vector2D operator+(Vector2D& v2)
        {
            return Vector2D(x + v2.getX(), y + v2.getY());
        }

        friend Vector2D operator+=(Vector2D& v1, Vector2D& v2)
        {
            v1.setX(v1.getX() + v2.getX());
            v1.setY(v1.getY() + v2.getY());

            return v1;
        }

        Vector2D operator*(float scalar)
        {
            return Vector2D(x * scalar, y * scalar);
        }

        Vector2D& operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;

            return *this;
        }

        Vector2D operator-(Vector2D& v2)
        {
            return Vector2D(x - v2.x, y - v2.y);
        }

        friend Vector2D& operator-=(Vector2D& v1, Vector2D& v2)
        {
            v1.x -= v2.x;
            v1.y -= v2.y;

            return v1;
        }

        Vector2D operator/(float scalar)
        {
            return Vector2D(x / scalar, y / scalar);
        }

        Vector2D& operator/=(float scalar)
        {
            x /= scalar;
            y /= scalar;

            return *this;
        }
    private:
        float x;
        float y;
};

#endif /* VECTOR2D_H */

