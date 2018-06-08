#include <math.h>
#include "cglmath/vector3f.h"
#include "cglmath/quaternion.h"

/**
 * Identity
 * @return the identity quaternion
 */
Quaternion quaternion_identity()
{
    return QUATERNION_IDENTITY;
}

/**
 * Normalizes the quaternion
 * @param q
 * @return
 */
Quaternion quaternion_normalize(Quaternion q)
{
    float dot;
    dot = q.a*q.a+q.b*q.b+q.c*q.c+q.d*q.d;
    if (dot <= 0.0f)
        return quaternion_identity();
    float tmp =1.0f / sqrtf(dot);
    return (Quaternion){q.a*tmp,q.b*tmp,q.c*tmp,q.d*tmp};
}

Matrix4f quaternion_to_matrix4f(Quaternion q)
{
    Matrix4f result;



    float norm = quaternion_magnitude(q);
    float s    = norm > 0.0f ? 2.0f / norm : 0.0f;

    float x = q.a;
    float y = q.b;
    float z = q.c;
    float w = q.d;

    float xx = s * x * x;   float xy = s * x * y;   float wx = s * w * x;
    float yy = s * y * y;   float yz = s * y * z;   float wy = s * w * y;
    float zz = s * z * z;   float xz = s * x * z;   float wz = s * w * z;

    result.m00 = 1.0f - yy - zz;
    result.m11 = 1.0f - xx - zz;
    result.m22 = 1.0f - xx - yy;

    result.m01 = xy + wz;
    result.m12 = yz + wx;
    result.m20 = xz + wy;

    result.m10 = xy - wz;
    result.m21 = yz - wx;
    result.m02 = xz - wy;

    result.m03 = 0.0f;
    result.m13 = 0.0f;
    result.m23 = 0.0f;

    result.m30 = 0.0f;
    result.m31 = 0.0f;
    result.m32 = 0.0f;
    result.m33 = 1.0f;

    return result;
}


Vector3f quaternion_imaginary(Quaternion q)
{
    return (Vector3f){q.a,q.b,q.c};
}

/**
 * Returns the real part of the quaternion
 * @param q
 * @return
 */
float quaternion_real(Quaternion q)
{
    return q.d;
}


Quaternion quaternion_mul(Quaternion q1, Quaternion q2)
{
    Quaternion result;
    result.a = q1.d * q2.a + q1.a * q2.d + q1.b * q2.c - q1.c * q2.b;
    result.b = q1.d * q2.b - q1.a * q2.c + q1.b * q2.d + q1.c * q2.a;
    result.c = q1.d * q2.c + q1.a * q2.b - q1.b * q2.a + q1.c * q2.d;
    result.d = q1.d * q2.d - q1.a * q2.a - q1.b * q2.b - q1.c * q2.c;
    return result;
}

Quaternion quaternion_make(float angle, Vector3f axis)
{
    Quaternion result;
    Vector3f  k;
    float a, c, s;

    a = angle * 0.5f;
    c = cosf(a);
    s = sinf(a);

    k = vector3f_normalize(axis);

    result.a = s * k.x;
    result.b = s * k.y;
    result.c = s * k.z;
    result.d = c;
    return result;
}



/**
 * Gets the forward vector of the quaternion
 * @param q
 * @return
 */
Vector3f quaternion_forward(Quaternion q)
{
    return vector3f_rotate(VECTOR3F_FORWARD,q);
}

Vector3f quaternion_right(Quaternion q)
{
    return vector3f_rotate(VECTOR3F_RIGHT,q);
}


float quaternion_magnitude(Quaternion q)
{
    return sqrtf(q.a*q.a+q.b*q.b+q.c*q.c+q.d*q.d);
}



