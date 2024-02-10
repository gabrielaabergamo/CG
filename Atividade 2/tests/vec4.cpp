#include "vec4.h"
#include "gtest/gtest.h"

TEST(Vec4Test, DefaultConstructor) {
    vec4 v;
    EXPECT_EQ(v.x(), 0);
    EXPECT_EQ(v.y(), 0);
    EXPECT_EQ(v.z(), 0);
    EXPECT_EQ(v.w(), 0);
}

TEST(Vec4Test, ParameterizedConstructor) {
    vec4 v(1, 2, 3, 4);
    EXPECT_EQ(v.x(), 1);
    EXPECT_EQ(v.y(), 2);
    EXPECT_EQ(v.z(), 3);
    EXPECT_EQ(v.w(), 4);
}

TEST(Vec4Test, DotProduct) {
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);
    double dot = dot(v1, v2);
    EXPECT_EQ(dot, 70);
}

TEST(Vec4Test, Length) {
    vec4 v(1, 2, 2, 1);
    double length = length(v);
    EXPECT_EQ(length, 3);
}

TEST(Vec4Test, Normalize) {
    vec4 v(1, 2, 2, 1);
    vec4 norm = normalize(v);
    EXPECT_EQ(norm.x(), 1/3.0);
    EXPECT_EQ(norm.y(), 2/3.0);
    EXPECT_EQ(norm.z(), 2/3.0);
    EXPECT_EQ(norm.w(), 1/3.0);
}