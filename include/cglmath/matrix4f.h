
#pragma once


#include "matrix4f_type.h"
#include "vector3f_type.h"

/* ============================
 *          MATRIX
 * ========================= */

Matrix4f matrix4f_identity          (void);
Matrix4f matrix4f_mul               (Matrix4f      left, Matrix4f right);
Matrix4f matrix4f_mul_rot           (Matrix4f         f,    Matrix4f matrix4f);
Matrix4f matrix4f_translate         (Matrix4f         m,    Vector3f v);
Matrix4f matrix4f_rotate            (Matrix4f         m,    float angle, Vector3f axis);
Matrix4f matrix4f_scale             (Matrix4f         m,    Vector3f v);
Matrix4f matrix4f_mul_scalar        (Matrix4f         m,    float scalar);
Matrix4f matrix4f_translate_make    (Vector3f position);
Matrix4f matrix4f_rotate_make       (float        angle, Vector3f axis);
Matrix4f matrix4f_scale_make        (Matrix4f m, Vector3f v);
Matrix4f matrix4f_inv               (Matrix4f m);
Matrix4f matrix4f_lookat            (Vector3f eye, Vector3f target, Vector3f axis);
Matrix4f matrix4f_ortho             (float left, float right, float bottom, float top, float near, float far);
Matrix4f matrix4f_perspective       (float fov, float ratio, float near, float far);