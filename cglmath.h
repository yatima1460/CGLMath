#pragma once

struct vector3f
{
    float x;
    float y;
    float z;
};

struct quaternion
{
    float a;
    float b;
    float c;
    float d;
};

#define QUATERNION_IDENTITY_INIT            {0,0,0,1}
#define QUATERNION_IDENTITY                 ((struct quaternion)QUATERNION_IDENTITY_INIT)
#define VECTOR3F_UP_INIT                    {0,1,0}
#define VECTOR3F_UP                         ((struct vector3f)VECTOR3F_UP_INIT)
#define VECTOR3F_FORWARD_INIT               {0,0,-1};
#define VECTOR3F_FORWARD                    ((struct vector3f){0,0,-1})
#define VECTOR3F_RIGHT_INIT                 {1,0,0}
#define VECTOR3F_RIGHT                      ((struct vector3f)VECTOR3F_RIGHT_INIT)

struct vector3f vector3f_add(struct vector3f a,struct vector3f b);
struct vector3f vector3f_sub(struct vector3f a,struct vector3f b);
struct vector3f vector3f_mul(struct vector3f a,struct vector3f b);
struct vector3f vector3f_scale(struct vector3f v, float f);
float vector3f_dot(struct vector3f v1, struct vector3f v2);
struct vector3f vector3f_cross(struct vector3f v1, struct vector3f v2);
struct vector3f vector3f_rotate(struct vector3f v, struct quaternion q);

struct quaternion quaternion_identity();
struct quaternion quaternion_normalize(struct quaternion q);
struct vector3f quaternion_imaginary(struct quaternion q);
float quaternion_real(struct quaternion q);
struct vector3f quaternion_forward(struct quaternion q);
