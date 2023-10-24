#ifndef MAT2_H
#define MAT2_H

#include <iostream>
#include <cmath>

class mat2
{
public:
    double e[2][2];

    mat2() : e{0, 0, 0, 0} {};
    mat2(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {};

    double x0() const { return e[0][0]; }
    double y0() const { return e[0][1]; }
    double x1() const { return e[1][0]; }
    double y1() const { return e[1][1]; }
};

inline mat2 const transpose(const mat2 &m)
{
    return mat2(
        m.e[0][0], m.e[1][0], m.e[0][1], m.e[1][1]);
}

inline double const determinant(const mat2 &m)
{
    return (m.e[0][0] * m.e[1][1] - m.e[1][0] * m.e[0][1]);
}

inline mat2 const inverse(const mat2 &m)
{
    const double invdet = 1 / (m.e[0][0] * m.e[1][1] - m.e[1][0] * m.e[0][1]);
    return mat2(
        m.e[1][1] * invdet, m.e[0][1] * invdet, m.e[1][0] * invdet, m.e[1][1] * invdet);
}

inline std::ostream &operator<<(std::ostream &out, const mat2 &m)
{
    return out << m.e[0][0] << ' ' << m.e[0][1] << '\n'
               << m.e[1][0] << ' ' << m.e[1][1];
}

inline mat2 operator+(const mat2 &m, const mat2 &n)
{
    return mat2(m.e[0][0] + n.e[0][0], m.e[0][1] + n.e[0][1], m.e[1][0] + n.e[1][0], m.e[1][1] + n.e[1][1]);
}

inline mat2 operator-(const mat2 &m, const mat2 &n)
{
    return mat2(m.e[0][0] - n.e[0][0], m.e[0][1] - n.e[0][1], m.e[1][0] - n.e[1][0], m.e[1][1] - n.e[1][1]);
}

inline mat2 operator*(const mat2 &m, const mat2 &n)
{
    return mat2(
        m.e[0][0] * n.e[0][0] + m.e[1][0] * n.e[0][1],
        m.e[0][1] * n.e[0][0] + m.e[1][1] * n.e[0][1],
        m.e[0][0] * n.e[1][0] + m.e[1][0] * n.e[1][1],
        m.e[0][1] * n.e[1][0] + m.e[1][1] * n.e[1][1]);
}

inline mat2 operator/(const mat2 &m, const mat2 &n)
{
    return mat2(m * inverse(n));
}

#endif