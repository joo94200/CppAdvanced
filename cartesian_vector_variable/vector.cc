#include "vector.hh"

#include <cassert>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

Vector& Vector::operator=(const Vector& v) {
    len = v.size();
    for (auto i = 0; i < len; i++)
        coord[i] = v[i];
    return *this;
}

Vector::Vector(const Vector& v) {
    len = v.size();
    coord = make_unique<value[]>(len);
    for (auto i = 0; i < len; i++)
        coord[i] = v[i];
}

Vector::Vector(size_t N) {
    len = N;
    coord = make_unique<value[]>(N);
    for (auto i = 0; i < N; i++)
        coord[i] = 0;
}

Vector::Vector(initializer_list<value> l)
{
    len = l.size();
    coord = make_unique<value[]>(len);
    size_t index = 0;
    initializer_list<value>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        coord[index++] = *it;
}

size_t Vector::size() const {
    return len;
}

Vector& Vector::operator+=(const Vector &rhs)
{
    assert(rhs.size() == len);
    for (auto i = 0; i < rhs.size(); i++)
        coord[i] += rhs[i];
    return *this;
}

Vector& Vector::operator-=(const Vector &rhs)
{
    assert(rhs.size() == len);
    for (auto i = 0; i < rhs.size(); i++)
        coord[i] -= rhs[i];
    return *this;
}

Vector& Vector::operator+=(value lambda)
{
    for (auto i = 0; i < len; i++)
        coord[i] += lambda;

    return *this;
}

Vector& Vector::operator*=(value lambda)
{
    for (auto i = 0; i < len; i++)
        coord[i] *= lambda;

    return *this;
}

Vector Vector::operator+(const Vector &rhs) const
{
    assert(rhs.size() == len);
    auto u = Vector(len);
    for (auto i = 0; i < len; i++)
        u[i] = rhs[i] + (*this)[i];

    return u;
}

Vector Vector::operator+(value v) const
{
    auto u = Vector(len);
    for (auto i = 0; i < len; i++)
        u[i] = (*this)[i] + v;

    return u;
}

value Vector::operator*(const Vector &rhs) const
{
    assert(rhs.size() == len);
    value n = 0;
    for (auto i = 0; i < len; i++)
        n += rhs[i] * (*this)[i];
    return n;
}

Vector Vector::operator*(value v) const
{
    auto u = Vector(len);
    for (auto i = 0; i < len; i++)
        u[i] = (*this)[i] * v;
    return u;
}

value Vector::operator[](size_t index) const
{
    assert(len > index);
    return coord[index];
}

value &Vector::operator[](size_t index)
{
    assert(len > index);
    return coord[index];
}

ostream& operator<<(ostream &os, const Vector &rhs)
{
    os << "{";
    for (auto i = 0; i < rhs.size(); i++)
        os << rhs[i] << (i < rhs.size() - 1 ? "," : "");
    os << "}";
    return os;
}

Vector operator*(const value& s, const Vector& v) {
    auto u = Vector(v.size());
    for (auto i = 0; i < v.size(); i++)
        u[i] = v[i] * s;

    return u;
}

Vector operator+(const value& s, const Vector& v) {
    auto u = Vector(v.size());
    for (auto i = 0; i < v.size(); i++)
        u[i] = v[i] + s;
    return u;
}