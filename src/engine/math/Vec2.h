#pragma once

class Vec2 {
  public:
    Vec2();
    Vec2(float x, float y);
    float x, y;

    // Methods
    void transpose(float x, float y);
    void transpose(Vec2 vector);

    Vec2 add(Vec2 o);
    void mutAdd(Vec2 o);
    Vec2 sub(Vec2 o);
    void mutSub(Vec2 o);
    void scale(float s);
    float dot(Vec2 o);
    float mag();

    void norm();
    Vec2 toNorm();

    Vec2 operator+(const Vec2 o);
    Vec2 operator-(const Vec2 o);
    float operator*(const Vec2 o);
};
