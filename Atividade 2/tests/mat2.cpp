#include "mat2.h"
#include "gtest/gtest.h"

TEST(Mat2Test, DefaultConstructor) {
    mat2 m;
    EXPECT_EQ(m.x0(), 0);
    EXPECT_EQ(m.y0(), 0);
    EXPECT_EQ(m.x1(), 0);
    EXPECT_EQ(m.y1(), 0);
}

TEST(Mat2Test, ParameterizedConstructor) {
    mat2 m(1, 2, 3, 4);
    EXPECT_EQ(m.x0(), 1);
    EXPECT_EQ(m.y0(), 2);
    EXPECT_EQ(m.x1(), 3);
    EXPECT_EQ(m.y1(), 4);
}

TEST(Mat2Test, Transpose) {
    mat2 m(1, 2, 3, 4);
    mat2 t = transpose(m);
    EXPECT_EQ(t.x0(), 1);
    EXPECT_EQ(t.y0(), 3);
    EXPECT_EQ(t.x1(), 2);
    EXPECT_EQ(t.y1(), 4);
}

TEST(Mat2Test, Determinant) {
    mat2 m(1, 2, 3, 4);
    double det = determinant(m);
    EXPECT_EQ(det, -2);
}

TEST(Mat2Test, Inverse) {
    mat2 m(1, 2, 3, 4);
    mat2 inv = inverse(m);
    EXPECT_EQ(inv.x0(), -2);
    EXPECT_EQ(inv.y0(), 1);
    EXPECT_EQ(inv.x1(), 1.5);
    EXPECT_EQ(inv.y1(), -0.5);
}