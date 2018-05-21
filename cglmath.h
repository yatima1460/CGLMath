#pragma once

struct vector3f
{
    float x;
    float y;
    float z;
};

struct vector4f
{
    float x;
    float y;
    float z;
    float w;
};

struct quaternion
{
    float a;
    float b;
    float c;
    float d;
};

struct transform
{
    struct vector3f position;
    struct quaternion rotation;
    struct vector3f scale;
};

struct matrix4f
{
    float m00,m01,m02,m03;
    float m10,m11,m12,m13;
    float m20,m21,m22,m23;
    float m30,m31,m32,m33;
};

struct vector2f
{
    float x;
    float y;
};

struct vector2i
{
    int x;
    int y;
};

struct vector3i
{
    int x;
    int y;
    int z;
};

#define QUATERNION_IDENTITY_INIT            {0,0,0,1}
#define QUATERNION_IDENTITY                 ((struct quaternion)QUATERNION_IDENTITY_INIT)

#define VECTOR3F_UP_INIT                    { 0, 1, 0}
#define VECTOR3F_RIGHT_INIT                 { 1, 0, 0}
#define VECTOR3F_DOWN_INIT                  { 0,-1, 0}
#define VECTOR3F_LEFT_INIT                  {-1, 0, 0}
#define VECTOR3F_FORWARD_INIT               { 0, 0,-1}
#define VECTOR3F_BACKWARD_INIT              { 0, 0, 1}

#define VECTOR3F_UP                         ((struct vector3f)VECTOR3F_UP_INIT)
#define VECTOR3F_RIGHT                      ((struct vector3f)VECTOR3F_RIGHT_INIT)
#define VECTOR3F_DOWN                       ((struct vector3f)VECTOR3F_DOWN_INIT)
#define VECTOR3F_LEFT                       ((struct vector3f)VECTOR3F_LEFT_INIT)
#define VECTOR3F_FORWARD                    ((struct vector3f)VECTOR3F_FORWARD_INIT)
#define VECTOR3F_BACKWARD                   ((struct vector3f)VECTOR3F_BACKWARD_INIT)


/* ============================
 *          FLOAT
 * ========================= */

float float_min(float a, float b);
float float_max(float a, float b);
float float_clamp(float value, float value_min, float value_max);
float float_rad(float degree);


/* ============================
 *          VECTOR4F
 * ========================= */

struct vector4f vector4f_one();


/* ============================
 *          VECTOR3F
 * ========================= */

struct vector3f vector3f_zero();
struct vector3f vector3f_one();
struct vector3f vector3f_add(struct vector3f a,struct vector3f b);
struct vector3f vector3f_sub(struct vector3f a,struct vector3f b);
struct vector3f vector3f_mul(struct vector3f a,struct vector3f b);
struct vector3f vector3f_scale(struct vector3f v, float f);
struct vector3f vector3f_cross(struct vector3f v1, struct vector3f v2);
struct vector3f vector3f_rotate(struct vector3f v, struct quaternion q);
struct vector3f vector3f_mul_scalar(struct vector3f v, float s);
struct vector3f vector3f_div_scalar(struct vector3f v, float s);
struct vector3f vector3f_normalize(struct vector3f v);
struct vector3f vector3f_negate(struct vector3f v);
float vector3f_magnitude(struct vector3f f);
float vector3f_dot(struct vector3f v1, struct vector3f v2);


/* ============================
 *          QUATERNION
 * ========================= */

struct quaternion quaternion_identity();
struct quaternion quaternion_make(float angle, struct vector3f axis);
struct quaternion quaternion_mul(struct quaternion q1, struct quaternion q2);
struct quaternion quaternion_normalize(struct quaternion q);
struct vector3f quaternion_imaginary(struct quaternion q);
float quaternion_real(struct quaternion q);
struct vector3f quaternion_forward(struct quaternion q);
struct vector3f quaternion_right(struct quaternion q);
float quaternion_magnitude(struct quaternion q);
struct matrix4f quaternion_to_matrix4f(struct quaternion q);


/* ============================
 *          TRANSFORM
 * ========================= */

struct transform transform_identity();
struct matrix4f transform_to_matrix(struct transform transform);


/* ============================
 *          MATRIX
 * ========================= */

struct matrix4f matrix4f_identity();
struct matrix4f matrix4f_mul(struct matrix4f left, struct matrix4f right);
struct matrix4f matrix4f_mul_rot(struct matrix4f f, struct matrix4f matrix4f);
struct matrix4f matrix4f_translate(struct matrix4f m, struct vector3f v);
struct matrix4f matrix4f_rotate(struct matrix4f m, float angle, struct vector3f axis);
struct matrix4f matrix4f_scale(struct matrix4f m, struct vector3f v);
struct matrix4f matrix4f_mul_scalar(struct matrix4f m, float scalar);
struct matrix4f matrix4f_translate_make(struct vector3f position);
struct matrix4f matrix4f_rotate_make(float angle, struct vector3f f);
//struct matrix4f matrix4f_rotate_make(float angle, struct vector3f axis);
//struct matrix4f matrix4f_scale_make(struct matrix4f m, struct vector3f v);
struct matrix4f matrix4f_inv(struct matrix4f m);
struct matrix4f matrix4f_lookat(struct vector3f eye, struct vector3f target, struct vector3f axis);
struct matrix4f matrix4f_ortho(float left, float right, float bottom, float top, float near, float far);
struct matrix4f matrix4f_perspective(float fov, float ratio, float near, float far);

