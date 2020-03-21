


#include <math.h>
#include <cglmath/transform.h>
#include <cglmath/vector4f_type.h>
#include "cglmath/matrix4f.h"
#include "cglmath/vector3f.h"
Matrix4f matrix4f_identity()
{
    return (Matrix4f){1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
}


Matrix4f matrix4f_mul(Matrix4f m1, Matrix4f m2)
{
    Matrix4f dest;
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

Matrix4f matrix4f_scale(Matrix4f m, Vector3f v)
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


Matrix4f matrix4f_mul_scalar(Matrix4f m, float scalar)
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


Matrix4f matrix4f_perspective(float fov, float ratio, float near, float far)
{
    Matrix4f result = {0};
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


Matrix4f matrix4f_lookat(Vector3f eye, Vector3f target, Vector3f axis)
{
    Matrix4f result;
    Vector3f f = vector3f_normalize(vector3f_sub(target, eye));
    Vector3f s = vector3f_normalize(vector3f_cross(f, axis));
    Vector3f u = vector3f_cross(s, f);
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

Matrix4f matrix4f_translate(Matrix4f m, Vector3f v)
{
    Vector4f v1, v2, v3;

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

Matrix4f matrix4f_translate_make(Vector3f position)
{
    return matrix4f_translate(matrix4f_identity(),position);
}


Matrix4f matrix4f_rotate(Matrix4f m, float angle, Vector3f axis)
{
    Matrix4f rot = matrix4f_rotate_make(angle, axis);
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
Matrix4f matrix4f_mul_rot(Matrix4f m1, Matrix4f m2)
{
    Matrix4f result;

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



Matrix4f matrix4f_rotate_make(float angle, Vector3f axis)
{
    Matrix4f m;
    Vector3f  axisn, v, vs;
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

    m.m00 += c;      m.m10 -= vs.z;   m.m20 += vs.y;
    m.m01 += vs.z;   m.m11 += c;      m.m21 -= vs.x;
    m.m02 -= vs.y;   m.m12 += vs.x;   m.m22 += c;

    m.m03 = m.m13 = m.m23 = m.m30 = m.m31 = m.m32 = 0.0f;
    m.m33 = 1.0f;
    return m;
}

Matrix4f matrix4f_inv(Matrix4f mat)
{
    Matrix4f result;

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



Matrix4f matrix4f_ortho(float left, float right, float bottom, float top, float near, float far)
{
    Matrix4f result = {0};
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

Quaternion matrix4f_to_quaternion(Matrix4f m)
{
    Quaternion q;
    q.d = sqrtf(1 + m.m00 + m.m11 + m.m22) / 2;
    q.a = (m.m21 - m.m12) / (4 * q.d);
    q.b = (m.m02 - m.m20) / (4 * q.d);
    q.c = (m.m10 - m.m01) / (4 * q.d);

    return q;
}

Transform matrix4f_to_transform(Matrix4f m)
{

    Transform t = transform_identity();
    t.position.x = m.m30;
    t.position.y = m.m31;
    t.position.z = m.m32;

    t.scale.x = vector3f_magnitude((Vector3f){m.m00, m.m01, m.m02});
    t.scale.y = vector3f_magnitude((Vector3f){m.m10, m.m11, m.m12});
    t.scale.z = vector3f_magnitude((Vector3f){m.m20, m.m21, m.m22});

    Matrix4f rotation_matrix = m;
    rotation_matrix.m00 /= t.scale.x;
    rotation_matrix.m01 /= t.scale.x;
    rotation_matrix.m02 /= t.scale.x;
    rotation_matrix.m03 = 0;

    rotation_matrix.m10 /= t.scale.y;
    rotation_matrix.m11 /= t.scale.y;
    rotation_matrix.m12 /= t.scale.y;
    rotation_matrix.m13 = 0;

    rotation_matrix.m20 /= t.scale.z;
    rotation_matrix.m21 /= t.scale.z;
    rotation_matrix.m22 /= t.scale.z;
    rotation_matrix.m23 = 0;

    // reset position
    rotation_matrix.m30 = 0;
    rotation_matrix.m31 = 0;
    rotation_matrix.m32 = 0;

    rotation_matrix.m33 = 1;
    
    t.rotation = matrix4f_to_quaternion(rotation_matrix);

    return t;
}