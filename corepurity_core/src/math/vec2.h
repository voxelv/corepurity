#ifndef COREPURITY_MATH_VEC2_H
#define COREPURITY_MATH_VEC2_H

#include <iostream>

namespace corepurity_core { namespace math {

    struct vec2
    {
        float x;
        float y;

        vec2();
        vec2(const float& x, const float& y);

        vec2& add(const vec2& other);
        vec2& subtract(const vec2& other);
        vec2& multiply(const vec2& other);
        vec2& divide(const vec2& other);

        friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
        friend vec2 operator+(vec2 left, const vec2& right);
        friend vec2 operator-(vec2 left, const vec2& right);
        friend vec2 operator*(vec2 left, const vec2& right);
        friend vec2 operator/(vec2 left, const vec2& right);

        vec2& operator+=(const vec2& other);
        vec2& operator-=(const vec2& other);
        vec2& operator*=(const vec2& other);
        vec2& operator/=(const vec2& other);

        bool operator==(const vec2& other);
        bool operator!=(const vec2& other);
    };



} }


#endif//COREPURITY_MATH_VEC2_H

