#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector() = default;
    Vector(int init_x, int init_y)
        : x{ init_x}
        , y{ init_y}
    {}

// Public Member functions here
    Vector& operator+=(const Vector& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vector& operator+=(int i )
    {
        x += i;
        y += i;
        return *this;
    }

    Vector& operator-=(const Vector& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    Vector& operator*=(int i)
    {
        x *= i;
        y *= i;
        return *this;
    }
    value& operator[](size_t i)
    {
        if (i == 0)
        {
            return x;
        }
        else
        {
            return y;
        }
    }
    value getX() const
    {
        return x;
    }
    value getY() const
    {
        return y;
    }
// Private Member functions here (if necessary)

// Member variables are ALWAYS private, and they go here
private:
    value x = 0;
    value y = 0;
};

std::ostream& operator<<(std::ostream& os, const Vector& vect)
{
    return os << '{' << vect.getX() << ',' << vect.getY() << '}';
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    return Vector(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    return Vector(lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY());
}

Vector operator*(const Vector& lhs, int scalar)
{
    return Vector(lhs.getX() * scalar, lhs.getY() * scalar);
}

Vector operator*(int scalar, const Vector& rhs)
{
    return Vector(rhs.getX() * scalar, rhs.getY() * scalar);
}

int operator*(const Vector& lhs, const Vector& rhs)
{
    return lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY();
}
