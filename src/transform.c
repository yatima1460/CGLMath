

#include "cglmath/vector3f.h"
#include "cglmath/transform.h"
#include "cglmath/matrix4f.h"

Transform transform_identity()
{
    Transform result;
    result.position = vector3f_zero();
    result.rotation = quaternion_identity();
    result.scale = vector3f_one();
    return result;
}

Matrix4f transform_to_matrix(struct transform transform)
{
    Matrix4f scale_matrix = matrix4f_scale(matrix4f_identity(), transform.scale);
    Matrix4f rotate_matrix = quaternion_to_matrix4f(transform.rotation);
    Matrix4f translate_matrix = matrix4f_translate_make(transform.position);

    //TRS rule
    return matrix4f_mul(translate_matrix, matrix4f_mul(rotate_matrix,scale_matrix));
}
