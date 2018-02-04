#ifndef COREPURITY_MATH_VEC2_H
#define COREPURITY_MATH_VEC2_H

#include <iostream>

namespace corepurity_core { namespace math {

    struct vec3
    {
        float x;
        float y;
        float z;

        vec3();
        vec3(const float& x, const float& y, const float& z);

        vec3& add(const vec3& other);
        vec3& subtract(const vec3& other);
        vec3& multiply(const vec3& other);
        vec3& divide(const vec3& other);

        friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
        friend vec3 operator+(vec3 left, const vec3& right);
        friend vec3 operator-(vec3 left, const vec3& right);
        friend vec3 operator*(vec3 left, const vec3& right);
        friend vec3 operator/(vec3 left, const vec3& right);

        vec3& operator+=(const vec3& other);
        vec3& operator-=(const vec3& other);
        vec3& operator*=(const vec3& other);
        vec3& operator/=(const vec3& other);

        bool operator==(const vec3& other);
        bool operator!=(const vec3& other);
    };



} }


#endif//COREPURITY_MATH_VEC2_H

