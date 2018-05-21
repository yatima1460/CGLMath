#include <math.h>
#include "math/cglmath.h"

float float_min(float a, float b)
{
    if (a < b)
        return a;
    return b;
}

float float_max(float a, float b)
{
    if (a > b)
        return a;
    return b;
}

float float_clamp(float value, float value_min, float value_max)
{
    return float_min(float_max(value,value_min),value_max);
}

//TODO: rename to degrees_to_radians?
float float_rad(float degree)
{
    return degree * (float)M_PI / 180.0f;
}


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

struct vector3f quaternion_right(struct quaternion q)
{
    return vector3f_rotate(VECTOR3F_RIGHT,q);
}


struct matrix4f matrix4f_identity()
{
    return (struct matrix4f){1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
}

struct vector4f vector4f_one()
{
    return (struct vector4f){1,1,1,1};
}


/*struct matrix4f matrix4f_scale(struct matrix4f m,struct vector3f v)
{

}

struct matrix4f matrix4f_translate_make(struct vector3f v)
{

}
 */

struct matrix4f matrix4f_mul(struct matrix4f m1,struct matrix4f m2)
{
  struct matrix4f dest;
  dest.m00 = m1.m00 * m2.m00 + m1.m10 * m2.m01 + m1.m20 * m2.m02 + m1.m30 * m2.m03;
  dest.m01 = m1.m01 * m2.m00 + m1.m11 * m2.m01 + m1.m21 * m2.m02 + m1.m31 * m2.m03;
  dest.m02 = m1.m02 * m2.m00 + m1.m12 * m2.m01 + m1.m22 * m2.m02 + m1.m32 * m2.m03;
  dest.m03 = m1.m03 * m2.m00 + m1.m13 * m2.m01 + m1.m23 * m2.m02 + m1.m33 * m2.m03;
  dest.m10 = m1.m00 * m2.m10 + m1.m10 * m2.m11 + m1.m20 * m2.m12 + m1.m30 * m2.m13;
  dest.m11 = m1.m01 * m2.m10 + m1.m11 * m2.m11 + m1.m21 * m2.m12 + m1.m31 * m2.m13;
  dest.m12 = m1.m02 * m2.m10 + m1.m12 * m2.m11 + m1.m22 * m2.m12 + m1.m32 * m2.m13;
  dest.m13 = m1.m03 * m2.m10 + m1.m13 * m2.m11 + m1.m23 * m2.m12 + m1.m33 * m2.m13;
  dest.m20 = m1.m00 * m2.m20 + m1.m10 * m2.m21 + m1.m20 * m2.m22 + m1.m30 * m2.m23;
  dest.m21 = m1.m01 * m2.m20 + m1.m11 * m2.m21 + m1.m21 * m2.m22 + m1.m31 * m2.m23;
  dest.m22 = m1.m02 * m2.m20 + m1.m12 * m2.m21 + m1.m22 * m2.m22 + m1.m32 * m2.m23;
  dest.m23 = m1.m03 * m2.m20 + m1.m13 * m2.m21 + m1.m23 * m2.m22 + m1.m33 * m2.m23;
  dest.m30 = m1.m00 * m2.m30 + m1.m10 * m2.m31 + m1.m20 * m2.m32 + m1.m30 * m2.m33;
  dest.m31 = m1.m01 * m2.m30 + m1.m11 * m2.m31 + m1.m21 * m2.m32 + m1.m31 * m2.m33;
  dest.m32 = m1.m02 * m2.m30 + m1.m12 * m2.m31 + m1.m22 * m2.m32 + m1.m32 * m2.m33;
  dest.m33 = m1.m03 * m2.m30 + m1.m13 * m2.m31 + m1.m23 * m2.m32 + m1.m33 * m2.m33;
  return dest;
}

struct vector3f vector3f_div_scalar(struct vector3f v, float s)
{
    return vector3f_mul_scalar(v, 1.0f/s);
}

struct matrix4f transform_to_matrix(struct transform transform)
{
    struct matrix4f scale_matrix = matrix4f_scale(matrix4f_identity(), transform.scale);
    struct matrix4f rotate_matrix = quaternion_to_matrix4f(transform.rotation);
    struct matrix4f translate_matrix = matrix4f_translate_make(transform.position);

    //TRS rule
    return matrix4f_mul(translate_matrix, matrix4f_mul(rotate_matrix,scale_matrix));
}

float quaternion_magnitude(struct quaternion q)
{
    return sqrtf(q.a*q.a+q.b*q.b+q.c*q.c+q.d*q.d);
}

struct matrix4f quaternion_to_matrix4f(struct quaternion q)
{
    struct matrix4f result;



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

struct vector3f vector3f_zero()
{
    return (struct vector3f){0,0,0};
}

struct vector3f vector3f_one()
{
    return (struct vector3f){1,1,1};
}

struct transform transform_identity()
{
    struct transform result;
    result.position = vector3f_zero();
    result.rotation = quaternion_identity();
    result.scale = vector3f_one();
    return result;
}

struct vector3f vector3f_mul_scalar(struct vector3f v, float s)
{
    return (struct vector3f){v.x*s,v.y*s,v.z*s};
}

struct matrix4f matrix4f_scale(struct matrix4f m, struct vector3f v)
{
    m.m00 *= v.x;
    m.m01 *= v.x;
    m.m02 *= v.x;
    m.m03 *= v.x;
    m.m10 *= v.y;
    m.m11 *= v.y;
    m.m12 *= v.y;
    m.m13 *= v.y;
    m.m20 *= v.z;
    m.m21 *= v.z;
    m.m22 *= v.z;
    m.m33 *= v.z;
    return m;
}


struct matrix4f matrix4f_mul_scalar(struct matrix4f m, float scalar)
{
    m.m00 *= scalar;
    m.m01 *= scalar;
    m.m02 *= scalar;
    m.m03 *= scalar;
    m.m10 *= scalar;
    m.m11 *= scalar;
    m.m12 *= scalar;
    m.m13 *= scalar;
    m.m20 *= scalar;
    m.m21 *= scalar;
    m.m22 *= scalar;
    m.m33 *= scalar;
    return m;
}



struct quaternion quaternion_make(float angle, struct vector3f axis)
{
    struct quaternion result;
    struct vector3f  k;
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

struct quaternion quaternion_mul(struct quaternion q1, struct quaternion q2)
{
    struct quaternion result;
    result.a = q1.d * q2.a + q1.a * q2.d + q1.b * q2.c - q1.c * q2.b;
    result.b = q1.d * q2.b - q1.a * q2.c + q1.b * q2.d + q1.c * q2.a;
    result.c = q1.d * q2.c + q1.a * q2.b - q1.b * q2.a + q1.c * q2.d;
    result.d = q1.d * q2.d - q1.a * q2.a - q1.b * q2.b - q1.c * q2.c;
    return result;
}

struct matrix4f matrix4f_ortho(float left, float right, float bottom, float top, float near, float far)
{
    struct matrix4f result = {0};
    float rl, tb, fn;
    rl = 1.0f / (right  - left);
    tb = 1.0f / (top    - bottom);
    fn =-1.0f / (far - near);
    result.m00 = 2.0f * rl;
    result.m11 = 2.0f * tb;
    result.m22 = 2.0f * fn;
    result.m30 =-(right  + left)    * rl;
    result.m31 =-(top    + bottom)  * tb;
    result.m32 = (far + near) * fn;
    result.m33 = 1.0f;
    return result;
}



struct vector3f vector3f_normalize(struct vector3f v)
{
    struct vector3f result;
    float norm;

    norm = vector3f_magnitude(v);

    if (norm == 0.0f)
    {
        return vector3f_zero();
    }

    result = vector3f_scale(v, 1.0f / norm);

    return result;
}

float vector3f_magnitude(struct vector3f v)
{
    return sqrtf(v.x*v.x+v.y*v.y+v.z*v.z);
}


struct matrix4f matrix4f_perspective(float fov, float ratio, float near, float far)
{
    struct matrix4f result = {0};
    float f, fn;

    f  = 1.0f / tanf(fov * 0.5f);
    fn = 1.0f / (near - far);

    result.m00 = f / ratio;
    result.m11 = f;
    result.m22 = (near + far) * fn;
    result.m23 =-1.0f;
    result.m32 = 2.0f * near * far * fn;
    return result;
}


struct matrix4f matrix4f_lookat(struct vector3f eye, struct vector3f target, struct vector3f axis)
{
    struct matrix4f result;
    struct vector3f f = vector3f_normalize(vector3f_sub(target, eye));
    struct vector3f s = vector3f_normalize(vector3f_cross(f, axis));
    struct vector3f u = vector3f_cross(s, f);
    result.m00 = s.x;
    result.m01 = u.x;
    result.m02 = -f.x;
    result.m10 = s.y;
    result.m11 = u.y;
    result.m12 = -f.y;
    result.m20 = s.z;
    result.m21 = u.z;
    result.m22 = -f.z;
    result.m30 = -vector3f_dot(s, eye);
    result.m31 = -vector3f_dot(u, eye);
    result.m32 = vector3f_dot(f, eye);
    result.m03 = result.m13 = result.m23 = 0.0f;
    result.m33 = 1.0f;
    return result;
}

struct matrix4f matrix4f_translate(struct matrix4f m, struct vector3f v)
{
    struct vector4f v1, v2, v3;

    v1.x = m.m00 * v.x;
    v1.y = m.m01 * v.x;
    v1.z = m.m02 * v.x;
    v1.w = m.m03 * v.x;

    v2.x = m.m10 * v.y;
    v2.y = m.m11 * v.y;
    v2.z = m.m12 * v.y;
    v2.w = m.m13 * v.y;

    v3.x = m.m20 * v.z;
    v3.y = m.m21 * v.z;
    v3.z = m.m22 * v.z;
    v3.w = m.m23 * v.z;

    m.m30 += v1.x;
    m.m31 += v1.y;
    m.m32 += v1.z;
    m.m33 += v1.w;

    m.m30 += v2.x;
    m.m31 += v2.y;
    m.m32 += v2.z;
    m.m33 += v2.w;

    m.m30 += v3.x;
    m.m31 += v3.y;
    m.m32 += v3.z;
    m.m33 += v3.w;
    return m;
}

struct matrix4f matrix4f_translate_make(struct vector3f position)
{
    return matrix4f_translate(matrix4f_identity(),position);
}


struct matrix4f matrix4f_rotate(struct matrix4f m, float angle, struct vector3f axis)
{
    struct matrix4f rot = matrix4f_rotate_make(angle, axis);
    return matrix4f_mul_rot(m, rot);
}

/*
* for affine transformations
* m2 should be:
*   R  R  R  0
*   R  R  R  0
*   R  R  R  0
*   0  0  0  1
**/
struct matrix4f matrix4f_mul_rot(struct matrix4f m1, struct matrix4f m2)
{
    struct matrix4f result;

    result.m00 = m1.m00 * m2.m00 + m1.m10 * m2.m01 + m1.m20 * m2.m02;
    result.m01 = m1.m01 * m2.m00 + m1.m11 * m2.m01 + m1.m21 * m2.m02;
    result.m02 = m1.m02 * m2.m00 + m1.m12 * m2.m01 + m1.m22 * m2.m02;
    result.m03 = m1.m03 * m2.m00 + m1.m13 * m2.m01 + m1.m23 * m2.m02;

    result.m10 = m1.m00 * m2.m10 + m1.m10 * m2.m11 + m1.m20 * m2.m12;
    result.m11 = m1.m01 * m2.m10 + m1.m11 * m2.m11 + m1.m21 * m2.m12;
    result.m12 = m1.m02 * m2.m10 + m1.m12 * m2.m11 + m1.m22 * m2.m12;
    result.m13 = m1.m03 * m2.m10 + m1.m13 * m2.m11 + m1.m23 * m2.m12;

    result.m20 = m1.m00 * m2.m20 + m1.m10 * m2.m21 + m1.m20 * m2.m22;
    result.m21 = m1.m01 * m2.m20 + m1.m11 * m2.m21 + m1.m21 * m2.m22;
    result.m22 = m1.m02 * m2.m20 + m1.m12 * m2.m21 + m1.m22 * m2.m22;
    result.m23 = m1.m03 * m2.m20 + m1.m13 * m2.m21 + m1.m23 * m2.m22;

    result.m30 = m1.m30;
    result.m31 = m1.m31;
    result.m32 = m1.m32;
    result.m33 = m1.m33;
    return result;
}

struct vector3f vector3f_negate(struct vector3f v)
{
    return (struct vector3f) {v.x * -1, v.y * -1, v.z * -1};
}




struct matrix4f matrix4f_rotate_make(float angle, struct vector3f axis)
{
    struct matrix4f m;
    struct vector3f  axisn, v, vs;
    float c;

    c = cosf(angle);

    axisn = vector3f_normalize(axis);
    v = vector3f_scale(axisn, 1.0f - c);
    vs = vector3f_scale(axisn, sinf(angle));

    m.m00 = axisn.x * v.x;
    m.m01 = axisn.y * v.x;
    m.m02 = axisn.z * v.x;

    m.m10 = axisn.x * v.y;
    m.m11 = axisn.y * v.y;
    m.m12 = axisn.z * v.y;

    m.m20 = axisn.x * v.z;
    m.m21 = axisn.y * v.z;
    m.m22 = axisn.z * v.z;

    m.m00 += c;       m.m10 -= vs.z;   m.m20 += vs.y;
    m.m01 += vs.z;   m.m11 += c;       m.m21 -= vs.x;
    m.m02 -= vs.y;   m.m12 += vs.x;   m.m22 += c;

    m.m03 = m.m13 = m.m23 = m.m30 = m.m31 = m.m32 = 0.0f;
    m.m33 = 1.0f;
    return m;
}

struct matrix4f matrix4f_inv(struct matrix4f mat)
{
    struct matrix4f result;

    float t[6];
    float det;
    float a = mat.m00, b = mat.m01, c = mat.m02, d = mat.m03,
            e = mat.m10, f = mat.m11, g = mat.m12, h = mat.m13,
            i = mat.m20, j = mat.m21, k = mat.m22, l = mat.m23,
            m = mat.m30, n = mat.m31, o = mat.m32, p = mat.m33;

    t[0] = k * p - o * l; t[1] = j * p - n * l; t[2] = j * o - n * k;
    t[3] = i * p - m * l; t[4] = i * o - m * k; t[5] = i * n - m * j;

    result.m00 =  f * t[0] - g * t[1] + h * t[2];
    result.m10 =-(e * t[0] - g * t[3] + h * t[4]);
    result.m20 =  e * t[1] - f * t[3] + h * t[5];
    result.m30 =-(e * t[2] - f * t[4] + g * t[5]);

    result.m01 =-(b * t[0] - c * t[1] + d * t[2]);
    result.m11 =  a * t[0] - c * t[3] + d * t[4];
    result.m21 =-(a * t[1] - b * t[3] + d * t[5]);
    result.m31 =  a * t[2] - b * t[4] + c * t[5];

    t[0] = g * p - o * h; t[1] = f * p - n * h; t[2] = f * o - n * g;
    t[3] = e * p - m * h; t[4] = e * o - m * g; t[5] = e * n - m * f;

    result.m02 =  b * t[0] - c * t[1] + d * t[2];
    result.m12 =-(a * t[0] - c * t[3] + d * t[4]);
    result.m22 =  a * t[1] - b * t[3] + d * t[5];
    result.m32 =-(a * t[2] - b * t[4] + c * t[5]);

    t[0] = g * l - k * h; t[1] = f * l - j * h; t[2] = f * k - j * g;
    t[3] = e * l - i * h; t[4] = e * k - i * g; t[5] = e * j - i * f;

    result.m03 =-(b * t[0] - c * t[1] + d * t[2]);
    result.m13 =  a * t[0] - c * t[3] + d * t[4];
    result.m23 =-(a * t[1] - b * t[3] + d * t[5]);
    result.m33 =  a * t[2] - b * t[4] + c * t[5];

    det = 1.0f / (a * result.m00 + b * result.m10
                  + c * result.m20 + d * result.m30);



    return matrix4f_mul_scalar(result, det);
}
