#pragma once



struct Vector3 {
    float x, y, z;

    Vector3(float x, float y, float z)
        : x((2.0f / 16.0f) * x), y((2.0f / 9.0f) * y), z(0 * z)
    {}

    Vector3& operator+=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }
    
};

struct Vector2 {
    float x, y;

    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(float x_, float y_) : x(x_), y(y_) {}
};

struct Vector5 {
    float x, y, z, u, v;

    Vector5(float x_, float y_, float z_, float u_, float v_)
        : x(x_), y(y_), z(z_), u(u_), v(v_) {}
};