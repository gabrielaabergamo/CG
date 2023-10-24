#ifndef MAT3_H
#define MAT3_H

#include <iostream>
#include <cmath>

class mat3
{
public:
    double e[3][3];

    mat3() : e{0, 0, 0, 0, 0, 0, 0, 0, 0} {};
    mat3(double e0, double e1, double e2,
         double e3, double e4, double e5,
         double e6, double e7, double e8) : e{e0, e1, e2, e3, e4, e5, e6, e7, e8} {};

    double x0() const { return e[0][0]; }
    double y0() const { return e[0][1]; }
    double z0() const { return e[0][2]; }

    double x1() const { return e[1][0]; }
    double y1() const { return e[1][1]; }
    double z1() const { return e[1][2]; }

    double x2() const { return e[2][0]; }
    double y2() const { return e[2][1]; }
    double z2() const { return e[2][2]; }
};

inline mat3 const transpose(const mat3 &m)
{
    return mat3(
        m.e[0][0], m.e[1][0], m.e[2][0],
        m.e[0][1], m.e[1][1], m.e[2][1],
        m.e[0][2], m.e[1][2], m.e[2][2]);
}

inline double const determinant(const mat3 &m)
{
    return (
        +m.e[0][0] * (m.e[1][1] * m.e[2][2] - m.e[2][1] * m.e[1][2]) - m.e[1][0] * (m.e[0][1] * m.e[2][2] - m.e[2][1] * m.e[0][2]) + m.e[2][0] * (m.e[0][1] * m.e[1][2] - m.e[1][1] * m.e[0][2]));
}

inline mat3 const inverse(const mat3 &m)
{
    const double invdet = 1 / (+m.e[0][0] * (m.e[1][1] * m.e[2][2] - m.e[2][1] * m.e[1][2]) - m.e[1][0] * (m.e[0][1] * m.e[2][2] - m.e[2][1] * m.e[0][2]) + m.e[2][0] * (m.e[0][1] * m.e[1][2] - m.e[1][1] * m.e[0][2]));
    return mat3(
        +(m.e[1][1] * m.e[2][2] - m.e[2][1] * m.e[1][2]) * invdet,
        -(m.e[0][1] * m.e[2][2] - m.e[2][1] * m.e[0][2]) * invdet,
        +(m.e[0][1] * m.e[1][2] - m.e[1][1] * m.e[0][2]) * invdet,
        -(m.e[1][0] * m.e[2][2] - m.e[2][0] * m.e[1][2]) * invdet,
        +(m.e[0][0] * m.e[2][2] - m.e[2][0] * m.e[0][2]) * invdet,
        -(m.e[0][0] * m.e[1][2] - m.e[1][0] * m.e[0][2]) * invdet,
        +(m.e[1][0] * m.e[2][1] - m.e[2][0] * m.e[1][1]) * invdet,
        -(m.e[0][0] * m.e[2][1] - m.e[2][0] * m.e[0][1]) * invdet,
        +(m.e[0][0] * m.e[1][1] - m.e[1][0] * m.e[0][1]) * invdet);
}

inline std::ostream &operator<<(std::ostream &out, const mat3 &m)
{
    return out << m.e[0][0] << ' ' << m.e[0][1] << ' ' << m.e[0][2] << '\n'
               << m.e[1][0] << ' ' << m.e[1][1] << ' ' << m.e[1][2] << '\n'
               << m.e[2][0] << ' ' << m.e[2][1] << ' ' << m.e[2][2] << '\n';
}

inline mat3 operator+(const mat3 &m, const mat3 &n)
{
    return mat3(m.e[0][0] + n.e[0][0], m.e[0][1] + n.e[0][1], m.e[0][2] + n.e[0][2],
                m.e[1][0] + n.e[1][0], m.e[1][1] + n.e[1][1], m.e[1][2] + n.e[1][2],
                m.e[2][0] + n.e[2][0], m.e[2][1] + n.e[2][1], m.e[2][2] + n.e[2][2]);
}

inline mat3 operator-(const mat3 &m, const mat3 &n)
{
    return mat3(m.e[0][0] - n.e[0][0], m.e[0][1] - n.e[0][1], m.e[0][2] - n.e[0][2],
                m.e[1][0] - n.e[1][0], m.e[1][1] - n.e[1][1], m.e[1][2] - n.e[1][2],
                m.e[2][0] - n.e[2][0], m.e[2][1] - n.e[2][1], m.e[2][2] - n.e[2][2]);
}

inline mat3 operator*(const mat3 &m, const mat3 &n)
{
    return mat3(
        m.e[0][0] * n.e[0][0] + m.e[1][0] * n.e[0][1] + m.e[2][0] * n.e[0][2],
        m.e[0][1] * n.e[0][0] + m.e[1][1] * n.e[0][1] + m.e[2][1] * n.e[0][2],
        m.e[0][2] * n.e[0][0] + m.e[1][2] * n.e[0][1] + m.e[2][2] * n.e[0][2],
        m.e[0][0] * n.e[1][0] + m.e[1][0] * n.e[1][1] + m.e[2][0] * n.e[1][2],
        m.e[0][1] * n.e[1][0] + m.e[1][1] * n.e[1][1] + m.e[2][1] * n.e[1][2],
        m.e[0][2] * n.e[1][0] + m.e[1][2] * n.e[1][1] + m.e[2][2] * n.e[1][2],
        m.e[0][0] * n.e[2][0] + m.e[1][0] * n.e[2][1] + m.e[2][0] * n.e[2][2],
        m.e[0][1] * n.e[2][0] + m.e[1][1] * n.e[2][1] + m.e[2][1] * n.e[2][2],
        m.e[0][2] * n.e[2][0] + m.e[1][2] * n.e[2][1] + m.e[2][2] * n.e[2][2]);
}

inline mat3 operator/(const mat3 &m, const mat3 &n)
{
    return mat3(m * inverse(n));
}

#endif