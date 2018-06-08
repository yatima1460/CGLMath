

#include <math.h>
#include "cglmath/vector3f.h"


Vector3f vector3f_add(Vector3f a, Vector3f b)
{
    return (Vector3f){a.x+b.x,a.y+b.y,a.z+b.z};
}

Vector3f vector3f_sub(Vector3f a,Vector3f b)
{
    return (Vector3f){a.x-b.x,a.y-b.y,a.z-b.z};
}

Vector3f vector3f_mul(Vector3f a,Vector3f b)
{
    return (Vector3f){a.x*b.x,a.y*b.y,a.z*b.z};
}

Vector3f vector3f_make(float x, float y, float z)
{
    return (Vector3f){x,y,z};
}


Vector3f vector3f_scale(Vector3f v, float f)
{
    return (Vector3f){v.x*f,v.y*f,v.z*f};
}


float vector3f_dot(Vector3f v1, Vector3f v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

Vector3f vector3f_cross(Vector3f v1, Vector3f v2)
{
    return (Vector3f){ v1.y * v2.z - v1.z * v2.y,v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
}

Vector3f vector3f_div_scalar(Vector3f v, float s)
{
    return vector3f_mul_scalar(v, 1.0f/s);
}



Vector3f vector3f_normalize(Vector3f v)
{
    Vector3f result;
    float norm;

    norm = vector3f_magnitude(v);

    if (norm == 0.0f)
    {
        return vector3f_zero();
    }

    result = vector3f_scale(v, 1.0f / norm);

    return result;
}

float vector3f_magnitude(Vector3f v)
{
    return sqrtf(v.x*v.x+v.y*v.y+v.z*v.z);
}


Vector3f vector3f_negate(Vector3f v)
{
    return (Vector3f) {v.x * -1, v.y * -1, v.z * -1};
}



Vector3f vector3f_zero()
{
    return (Vector3f){0,0,0};
}

Vector3f vector3f_one()
{
    return (Vector3f){1,1,1};
}



Vector3f vector3f_mul_scalar(Vector3f v, float s)
{
    return (Vector3f){v.x*s,v.y*s,v.z*s};
}


/**
 * Rotates a vector using a quaternion
 * @param vA the vector to rotate
 * @param qA the quaternion as rotation
 * @return the vector rotated
 */
Vector3f vector3f_rotate(Vector3f v, Quaternion q)
{

    Quaternion p = quaternion_normalize(q);
    Vector3f u = quaternion_imaginary(q);
    float s = quaternion_real(q);

    Vector3f v1 = vector3f_scale(u, 2.0f * vector3f_dot(u, v));
    Vector3f v2 = vector3f_scale(v,  s * s - vector3f_dot(u, u));

    v1 = vector3f_add(v1,v2);
    v2 = vector3f_cross(u,v);
    v2 = vector3f_scale(v2,2.0f*s);

    return vector3f_add(v1,v2);
}

