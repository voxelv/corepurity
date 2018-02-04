#ifndef COREPURITY_MATH_VEC4_H
#define COREPURITY_MATH_VEC4_H

#include <iostream>

namespace corepurity_core { namespace math {

    struct vec4
    {
        float x;
        float y;
        float z;
        float w;

        vec4();
        vec4(const float& x, const float& y, const float& z, const float& w);

        vec4& add(const vec4& other);
        vec4& subtract(const vec4& other);
        vec4& multiply(const vec4& other);
        vec4& divide(const vec4& other);

        friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
        friend vec4 operator+(vec4 left, const vec4& right);
        friend vec4 operator-(vec4 left, const vec4& right);
        friend vec4 operator*(vec4 left, const vec4& right);
        friend vec4 operator/(vec4 left, const vec4& right);

        vec4& operator+=(const vec4& other);
        vec4& operator-=(const vec4& other);
        vec4& operator*=(const vec4& other);
        vec4& operator/=(const vec4& other);

        bool operator==(const vec4& other);
        bool operator!=(const vec4& other);
    };



} }


#endif//COREPURITY_MATH_VEC4_H

