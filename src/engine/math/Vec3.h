#pragma once

class Vec3 {
  public:
    float x, y, z;

    // Constructors
    Vec3();
    Vec3(float x, float y, float z);

    // Methods
    void transpose(float x, float y, float z);
    void transpose(Vec3 vector);

    Vec3 add(Vec3 o);
    Vec3 sub(Vec3 o);
    Vec3 cross(Vec3 o);
    float dot(Vec3 o);
    float mag();

    void norm();
    Vec3 toNorm();

    Vec3 operator+(const Vec3 o);
    Vec3 operator-(const Vec3 o);
    float operator*(const Vec3 o);
    Vec3 operator^(const Vec3 o);
};
