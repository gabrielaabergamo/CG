#include "mat3.h"
#include "gtest/gtest.h"

TEST(Mat3Test, DefaultConstructor) {
    mat3 m;
    EXPECT_EQ(m.x0(), 0);
    EXPECT_EQ(m.y0(), 0);
    EXPECT_EQ(m.z0(), 0);
    EXPECT_EQ(m.x1(), 0);
    EXPECT_EQ(m.y1(), 0);
    EXPECT_EQ(m.z1(), 0);
    EXPECT_EQ(m.x2(), 0);
    EXPECT_EQ(m.y2(), 0);
    EXPECT_EQ(m.z2(), 0);
}

TEST(Mat3Test, ParameterizedConstructor) {
    mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
    EXPECT_EQ(m.x0(), 1);
    EXPECT_EQ(m.y0(), 2);
    EXPECT_EQ(m.z0(), 3);
    EXPECT_EQ(m.x1(), 4);
    EXPECT_EQ(m.y1(), 5);
    EXPECT_EQ(m.z1(), 6);
    EXPECT_EQ(m.x2(), 7);
    EXPECT_EQ(m.y2(), 8);
    EXPECT_EQ(m.z2(), 9);
}

TEST(Mat3Test, Transpose) {
    mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 t = transpose(m);
    EXPECT_EQ(t.x0(), 1);
    EXPECT_EQ(t.y0(), 4);
    EXPECT_EQ(t.z0(), 7);
    EXPECT_EQ(t.x1(), 2);
    EXPECT_EQ(t.y1(), 5);
    EXPECT_EQ(t.z1(), 8);
    EXPECT_EQ(t.x2(), 3);
    EXPECT_EQ(t.y2(), 6);
    EXPECT_EQ(t.z2(), 9);
}

TEST(Mat3Test, Determinant) {
    mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
    double det = determinant(m);
    EXPECT_EQ(det, 0);
}

TEST(Mat3Test, Inverse) {
    mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 10);
    mat3 inv = inverse(m);
}