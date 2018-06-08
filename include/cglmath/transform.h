#pragma once


#include "transform_type.h"

#include "matrix4f_type.h"



/* ============================
 *          TRANSFORM
 * ========================= */

Transform transform_identity(void);

Matrix4f transform_to_matrix(Transform transform);