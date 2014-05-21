#ifndef __Vector__
#define __Vector__

#include <math.h>

class Vector2D
{
public:
    Vector2D(float init_x, float init_y): x(init_x), y(init_y) { }
    float getX() { return x; }
    float getY() { return y; }
    void setX(float n_x) { x = n_x; }
    void setY(float n_y) { y = n_y; }
    float length() { return sqrt(x*x + y*y); }
    Vector2D operator+(const Vector2D& v2) const {
        return Vector2D(x + v2.x, y + v2.y);
    }
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }
    Vector2D operator*(float scalar) {
        return Vector2D(x * scalar, y * scalar);
    }
    Vector2D& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    Vector2D operator-(const Vector2D& v2) const {
        return Vector2D(x - v2.x, y - v2.y);
    }
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }
    Vector2D operator/(float scalar) {
        return Vector2D(x / scalar, y / scalar);
    }
    Vector2D& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }
    void normalize() {
        float l = length();
        if (l > 0) (*this) *= 1 / l;
    }


private:
    float x;
    float y;
};

#endif
