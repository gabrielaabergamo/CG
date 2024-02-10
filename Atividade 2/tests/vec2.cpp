#include "vec2.h"
#include "gtest/gtest.h"

TEST(Vec2Test, DefaultConstructor) {
    vec2 v;
    EXPECT_EQ(v.x(), 0);
    EXPECT_EQ(v.y(), 0);
}

TEST(Vec2Test, ParameterizedConstructor) {
    vec2 v(1, 2);
    EXPECT_EQ(v.x(), 1);
    EXPECT_EQ(v.y(), 2);
}

TEST(Vec2Test, DotProduct) {
    vec2 v1(1, 2);
    vec2 v2(3, 4);
    double dot = dot(v1, v2);
    EXPECT_EQ(dot, 11);
}

TEST(Vec2Test, CrossProduct) {
    vec2 v1(1, 2);
    vec2 v2(3, 4);
    double cross = cross(v1, v2);
    EXPECT_EQ(cross, -2);
}

TEST(Vec2Test, Length) {
    vec2 v(3, 4);
    double length = length(v);
    EXPECT_EQ(length, 5);
}

TEST(Vec2Test, Normalize) {
    vec2 v(3, 4);
    vec2 norm = normalize(v);
    EXPECT_EQ(norm.x(), 0.6);
    EXPECT_EQ(norm.y(), 0.8);
}