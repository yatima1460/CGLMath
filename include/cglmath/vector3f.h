#pragma once
#include "quaternion.h"

/* ============================
 *          VECTOR3F
 * ========================= */


#define VECTOR3F_UP_INIT                    { 0, 1, 0}
#define VECTOR3F_RIGHT_INIT                 { 1, 0, 0}
#define VECTOR3F_DOWN_INIT                  { 0,-1, 0}
#define VECTOR3F_LEFT_INIT                  {-1, 0, 0}
#define VECTOR3F_FORWARD_INIT               { 0, 0,-1}
#define VECTOR3F_BACKWARD_INIT              { 0, 0, 1}

#define VECTOR3F_UP                         ((Vector3f)VECTOR3F_UP_INIT)
#define VECTOR3F_RIGHT                      ((Vector3f)VECTOR3F_RIGHT_INIT)
#define VECTOR3F_DOWN                       ((Vector3f)VECTOR3F_DOWN_INIT)
#define VECTOR3F_LEFT                       ((Vector3f)VECTOR3F_LEFT_INIT)
#define VECTOR3F_FORWARD                    ((Vector3f)VECTOR3F_FORWARD_INIT)
#define VECTOR3F_BACKWARD                   ((Vector3f)VECTOR3F_BACKWARD_INIT)

Vector3f    vector3f_zero       (void);
Vector3f    vector3f_one        (void);
Vector3f    vector3f_add        (Vector3f    a,  Vector3f b);
Vector3f    vector3f_sub        (Vector3f    a,  Vector3f b);
Vector3f    vector3f_mul        (Vector3f    a,  Vector3f b);
Vector3f    vector3f_scale      (Vector3f    v,  float f);
Vector3f    vector3f_cross      (Vector3f   v1,  Vector3f v2);
Vector3f    vector3f_rotate     (Vector3f    v,  Quaternion q);
Vector3f    vector3f_mul_scalar (Vector3f    v,  float s);
Vector3f    vector3f_div_scalar (Vector3f    v,  float s);
Vector3f    vector3f_normalize  (Vector3f    v);
Vector3f    vector3f_negate     (Vector3f    v);
Vector3f    vector3f_make       (float x, float y, float z);
float       vector3f_magnitude  (Vector3f    f);
float       vector3f_dot        (Vector3f    v1, Vector3f v2);