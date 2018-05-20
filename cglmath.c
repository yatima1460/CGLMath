#include <math.h>
#include "math/cglmath.h"

struct vector3f vector3f_add(struct vector3f a,struct vector3f b)
{
    return (struct vector3f){.x = a.x+b.x,.y=a.y+b.y,.z=a.z+b.z};
}

struct vector3f vector3f_sub(struct vector3f a,struct vector3f b)
{
    return (struct vector3f){.x = a.x-b.x,.y=a.y-b.y,.z=a.z-b.z};
}

struct vector3f vector3f_mul(struct vector3f a,struct vector3f b)
{
    return (struct vector3f){.x = a.x*b.x,.y=a.y*b.y,.z=a.z*b.z};
}



struct vector3f vector3f_scale(struct vector3f v, float f)
{
    return (struct vector3f){v.x*f,v.y*f,v.z*f};
}


float vector3f_dot(struct vector3f v1, struct vector3f v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

struct vector3f vector3f_cross(struct vector3f v1, struct vector3f v2)
{
    return (struct vector3f){ v1.y * v2.z - v1.z * v2.y,v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
}




/**
 * Identity
 * @return the identity quaternion
 */
struct quaternion quaternion_identity()
{
    return QUATERNION_IDENTITY;
}

/**
 * Normalizes the quaternion
 * @param q
 * @return
 */
struct quaternion quaternion_normalize(struct quaternion q)
{
    float dot;
    dot = q.a*q.a+q.b*q.b+q.c*q.c+q.d*q.d;
    if (dot <= 0.0f)
        return quaternion_identity();
    float tmp =1.0f / sqrtf(dot);
    return (struct quaternion){q.a*tmp,q.b*tmp,q.c*tmp,q.d*tmp};
}



struct vector3f quaternion_imaginary(struct quaternion q)
{
    return (struct vector3f){q.a,q.b,q.c};
}

/**
 * Returns the real part of the quaternion
 * @param q
 * @return
 */
float quaternion_real(struct quaternion q)
{
    return q.d;
}

/**
 * Rotates a vector using a quaternion
 * @param vA the vector to rotate
 * @param qA the quaternion as rotation
 * @return the vector rotated
 */
struct vector3f vector3f_rotate(struct vector3f v, struct quaternion q)
{

    struct quaternion p = quaternion_normalize(q);
    struct vector3f u = quaternion_imaginary(q);
    float s = quaternion_real(q);

    struct vector3f v1 = vector3f_scale(u, 2.0f * vector3f_dot(u, v));
    struct vector3f v2 = vector3f_scale(v,  s * s - vector3f_dot(u, u));

    v1 = vector3f_add(v1,v2);
    v2 = vector3f_cross(u,v);
    v2 = vector3f_scale(v2,2.0f*s);

    return vector3f_add(v1,v2);
}

/**
 * Gets the forward vector of the quaternion
 * @param q
 * @return
 */
struct vector3f quaternion_forward(struct quaternion q)
{
    return vector3f_rotate(VECTOR3F_FORWARD,q);
}
