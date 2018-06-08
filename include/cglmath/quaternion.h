/* ============================
 *          QUATERNION
 * ========================= */

#pragma once

#include "quaternion_type.h"
#include "vector3f_type.h"
#include "matrix4f_type.h"


#define QUATERNION_IDENTITY_INIT            {0,0,0,1}
#define QUATERNION_IDENTITY                 ((Quaternion)QUATERNION_IDENTITY_INIT)


Quaternion  quaternion_identity     (void);
Quaternion  quaternion_make         (float   angle, Vector3f axis);
Quaternion  quaternion_mul          (Quaternion q1, Quaternion q2);
Quaternion  quaternion_normalize    (Quaternion q);
Vector3f    quaternion_imaginary    (Quaternion q);
float       quaternion_real         (Quaternion q);
Vector3f    quaternion_forward      (Quaternion q);
Vector3f    quaternion_right        (Quaternion q);
float       quaternion_magnitude    (Quaternion q);
Matrix4f    quaternion_to_matrix4f  (Quaternion q);