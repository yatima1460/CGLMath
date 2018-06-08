

#pragma once

#include "quaternion_type.h"
#include "vector3f_type.h"


typedef struct transform
{
    Vector3f position;
    Quaternion rotation;
    Vector3f scale;
} Transform;
