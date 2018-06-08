

#ifdef _WIN32
#	define _USE_MATH_DEFINES
#endif
#include <math.h>

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