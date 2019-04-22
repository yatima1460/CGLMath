# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`float_min`](#float_8c_1a164871d6600b508302f0f278f0567e33)`(float a,float b)`            | 
`public float `[`float_max`](#float_8c_1ad017d071756c41882116cfba1845b0b9)`(float a,float b)`            | 
`public float `[`float_clamp`](#float_8c_1ab28aeccaea1efea5742a109205eb9f95)`(float value,float value_min,float value_max)`            | 
`public float `[`float_rad`](#float_8c_1a739581795f3c303c10c76e0822d49d50)`(float degree)`            | 
`public Matrix4f `[`matrix4f_identity`](#matrix4f_8c_1a6b7ef13b41b8acdea5e5d7dbf8dedecf)`()`            | 
`public Matrix4f `[`matrix4f_mul`](#matrix4f_8c_1a0ccd6dd099114187f9b040f1ef787ec6)`(Matrix4f m1,Matrix4f m2)`            | 
`public Matrix4f `[`matrix4f_scale`](#matrix4f_8c_1a94833809a746134cc746a2d3c8ef1d01)`(Matrix4f m,Vector3f v)`            | 
`public Matrix4f `[`matrix4f_mul_scalar`](#matrix4f_8c_1a69662c4f5168e83684a1891d58e0957d)`(Matrix4f m,float scalar)`            | 
`public Matrix4f `[`matrix4f_perspective`](#matrix4f_8c_1a570b852935afad5c639f5e331ffe60c1)`(float fov,float ratio,float near,float far)`            | 
`public Matrix4f `[`matrix4f_lookat`](#matrix4f_8c_1ad2d7bb13706d8fb4abdd61e8f003f61e)`(Vector3f eye,Vector3f target,Vector3f axis)`            | 
`public Matrix4f `[`matrix4f_translate`](#matrix4f_8c_1a8795545b0ce48743de51d16f41b21b82)`(Matrix4f m,Vector3f v)`            | 
`public Matrix4f `[`matrix4f_translate_make`](#matrix4f_8c_1aea7b7fd3a43e913e5b0701d9136d6c92)`(Vector3f position)`            | 
`public Matrix4f `[`matrix4f_rotate`](#matrix4f_8c_1a7b7c47a29c7bdc6ee230e8c618480fc5)`(Matrix4f m,float angle,Vector3f axis)`            | 
`public Matrix4f `[`matrix4f_mul_rot`](#matrix4f_8c_1af2c39d9b49cb76ac8a07824faa6eca1b)`(Matrix4f m1,Matrix4f m2)`            | 
`public Matrix4f `[`matrix4f_rotate_make`](#matrix4f_8c_1a829cddec595ee6fb695cafc6fba6436e)`(float angle,Vector3f axis)`            | 
`public Matrix4f `[`matrix4f_inv`](#matrix4f_8c_1a65ee76d04128a569db74ebddd6d1178c)`(Matrix4f mat)`            | 
`public Matrix4f `[`matrix4f_ortho`](#matrix4f_8c_1af5a6eb31bd5c001231e16fbbc1998146)`(float left,float right,float bottom,float top,float near,float far)`            | 
`public Quaternion `[`quaternion_identity`](#quaternion_8c_1a6e73322701a7678f622aec1b1c1c8be4)`()`            | Identity 
`public Quaternion `[`quaternion_normalize`](#quaternion_8c_1a97224993cc3ef13a44c927a8c8680ba5)`(Quaternion q)`            | Normalizes the quaternion 
`public Matrix4f `[`quaternion_to_matrix4f`](#quaternion_8c_1aae48366d3c41626701b3733118251d57)`(Quaternion q)`            | 
`public Vector3f `[`quaternion_imaginary`](#quaternion_8c_1a8a2cad7a845d39153ef8ac7f07b586ae)`(Quaternion q)`            | 
`public float `[`quaternion_real`](#quaternion_8c_1ab8dc2f598e9168e5df20a46002fdf187)`(Quaternion q)`            | Returns the real part of the quaternion 
`public Quaternion `[`quaternion_mul`](#quaternion_8c_1a6dc56f7e90f873f825690c7e16942772)`(Quaternion q1,Quaternion q2)`            | 
`public Quaternion `[`quaternion_make`](#quaternion_8c_1abdb584203da584937857c54636c4e91e)`(float angle,Vector3f axis)`            | 
`public Vector3f `[`quaternion_forward`](#quaternion_8c_1aa59401ecf8beb1dba84bc708e97a16a4)`(Quaternion q)`            | Gets the forward vector of the quaternion 
`public Vector3f `[`quaternion_right`](#quaternion_8c_1ac20489143bbd0203423a83dcee2a2054)`(Quaternion q)`            | 
`public float `[`quaternion_magnitude`](#quaternion_8c_1a000103a86287e5f7da7da34a86dc4c3b)`(Quaternion q)`            | 
`public Transform `[`transform_identity`](#transform_8c_1a371675cf0b68a1097914fbe0965f99c9)`()`            | 
`public Matrix4f `[`transform_to_matrix`](#transform_8c_1a623eb0037998d17f4ab86574b98505b5)`(struct transform transform)`            | 
`public Vector3f `[`vector3f_add`](#vector3f_8c_1ab2768621fa85125a5b4c76117004da18)`(Vector3f a,Vector3f b)`            | 
`public Vector3f `[`vector3f_sub`](#vector3f_8c_1ab69ea26f98e29bf9c23e915552bc6aed)`(Vector3f a,Vector3f b)`            | 
`public Vector3f `[`vector3f_mul`](#vector3f_8c_1ad9a57675d586de60b38e369712218a42)`(Vector3f a,Vector3f b)`            | 
`public Vector3f `[`vector3f_make`](#vector3f_8c_1adf85b2db6c9fde5d774560ccb9e98ce0)`(float x,float y,float z)`            | 
`public Vector3f `[`vector3f_scale`](#vector3f_8c_1a35c390f13ab22cd423aca8d732ba4d42)`(Vector3f v,float f)`            | 
`public float `[`vector3f_dot`](#vector3f_8c_1a0e48f94db254b0f210d6c18a44042b13)`(Vector3f v1,Vector3f v2)`            | 
`public Vector3f `[`vector3f_cross`](#vector3f_8c_1a8a278c35766357191b397a325e450737)`(Vector3f v1,Vector3f v2)`            | 
`public Vector3f `[`vector3f_div_scalar`](#vector3f_8c_1a690f5971405c43437aa7c80fc5fceac8)`(Vector3f v,float s)`            | 
`public Vector3f `[`vector3f_normalize`](#vector3f_8c_1a8ec1c0db77fe960ffa7ea7ea1dd54213)`(Vector3f v)`            | 
`public float `[`vector3f_magnitude`](#vector3f_8c_1a0b9405cbc5a857bcd4041fcfc8e42222)`(Vector3f v)`            | 
`public Vector3f `[`vector3f_negate`](#vector3f_8c_1aefbdec22da1198015f92b48dd2b9fa85)`(Vector3f v)`            | 
`public Vector3f `[`vector3f_zero`](#vector3f_8c_1ae540e5271ec5a4127e904945f5457cf4)`()`            | 
`public Vector3f `[`vector3f_one`](#vector3f_8c_1a299963542d180638e5ba770e95fdc260)`()`            | 
`public Vector3f `[`vector3f_mul_scalar`](#vector3f_8c_1acbd8f8b88ff97bf104faba163d319bb8)`(Vector3f v,float s)`            | 
`public Vector3f `[`vector3f_rotate`](#vector3f_8c_1a6b77abed99eac87b4e97babcf7407783)`(Vector3f v,Quaternion q)`            | Rotates a vector using a quaternion 
`public Vector4f `[`vector4f_one`](#vector4f_8c_1a8bde3ebed5df63ce8a87dcd69f4127ef)`()`            | 

## Members

#### `public float `[`float_min`](#float_8c_1a164871d6600b508302f0f278f0567e33)`(float a,float b)` 

#### `public float `[`float_max`](#float_8c_1ad017d071756c41882116cfba1845b0b9)`(float a,float b)` 

#### `public float `[`float_clamp`](#float_8c_1ab28aeccaea1efea5742a109205eb9f95)`(float value,float value_min,float value_max)` 

#### `public float `[`float_rad`](#float_8c_1a739581795f3c303c10c76e0822d49d50)`(float degree)` 

#### `public Matrix4f `[`matrix4f_identity`](#matrix4f_8c_1a6b7ef13b41b8acdea5e5d7dbf8dedecf)`()` 

#### `public Matrix4f `[`matrix4f_mul`](#matrix4f_8c_1a0ccd6dd099114187f9b040f1ef787ec6)`(Matrix4f m1,Matrix4f m2)` 

#### `public Matrix4f `[`matrix4f_scale`](#matrix4f_8c_1a94833809a746134cc746a2d3c8ef1d01)`(Matrix4f m,Vector3f v)` 

#### `public Matrix4f `[`matrix4f_mul_scalar`](#matrix4f_8c_1a69662c4f5168e83684a1891d58e0957d)`(Matrix4f m,float scalar)` 

#### `public Matrix4f `[`matrix4f_perspective`](#matrix4f_8c_1a570b852935afad5c639f5e331ffe60c1)`(float fov,float ratio,float near,float far)` 

#### `public Matrix4f `[`matrix4f_lookat`](#matrix4f_8c_1ad2d7bb13706d8fb4abdd61e8f003f61e)`(Vector3f eye,Vector3f target,Vector3f axis)` 

#### `public Matrix4f `[`matrix4f_translate`](#matrix4f_8c_1a8795545b0ce48743de51d16f41b21b82)`(Matrix4f m,Vector3f v)` 

#### `public Matrix4f `[`matrix4f_translate_make`](#matrix4f_8c_1aea7b7fd3a43e913e5b0701d9136d6c92)`(Vector3f position)` 

#### `public Matrix4f `[`matrix4f_rotate`](#matrix4f_8c_1a7b7c47a29c7bdc6ee230e8c618480fc5)`(Matrix4f m,float angle,Vector3f axis)` 

#### `public Matrix4f `[`matrix4f_mul_rot`](#matrix4f_8c_1af2c39d9b49cb76ac8a07824faa6eca1b)`(Matrix4f m1,Matrix4f m2)` 

#### `public Matrix4f `[`matrix4f_rotate_make`](#matrix4f_8c_1a829cddec595ee6fb695cafc6fba6436e)`(float angle,Vector3f axis)` 

#### `public Matrix4f `[`matrix4f_inv`](#matrix4f_8c_1a65ee76d04128a569db74ebddd6d1178c)`(Matrix4f mat)` 

#### `public Matrix4f `[`matrix4f_ortho`](#matrix4f_8c_1af5a6eb31bd5c001231e16fbbc1998146)`(float left,float right,float bottom,float top,float near,float far)` 

#### `public Quaternion `[`quaternion_identity`](#quaternion_8c_1a6e73322701a7678f622aec1b1c1c8be4)`()` 

Identity 
#### Returns
the identity quaternion

#### `public Quaternion `[`quaternion_normalize`](#quaternion_8c_1a97224993cc3ef13a44c927a8c8680ba5)`(Quaternion q)` 

Normalizes the quaternion 
#### Parameters
* `q` 

#### Returns

#### `public Matrix4f `[`quaternion_to_matrix4f`](#quaternion_8c_1aae48366d3c41626701b3733118251d57)`(Quaternion q)` 

#### `public Vector3f `[`quaternion_imaginary`](#quaternion_8c_1a8a2cad7a845d39153ef8ac7f07b586ae)`(Quaternion q)` 

#### `public float `[`quaternion_real`](#quaternion_8c_1ab8dc2f598e9168e5df20a46002fdf187)`(Quaternion q)` 

Returns the real part of the quaternion 
#### Parameters
* `q` 

#### Returns

#### `public Quaternion `[`quaternion_mul`](#quaternion_8c_1a6dc56f7e90f873f825690c7e16942772)`(Quaternion q1,Quaternion q2)` 

#### `public Quaternion `[`quaternion_make`](#quaternion_8c_1abdb584203da584937857c54636c4e91e)`(float angle,Vector3f axis)` 

#### `public Vector3f `[`quaternion_forward`](#quaternion_8c_1aa59401ecf8beb1dba84bc708e97a16a4)`(Quaternion q)` 

Gets the forward vector of the quaternion 
#### Parameters
* `q` 

#### Returns

#### `public Vector3f `[`quaternion_right`](#quaternion_8c_1ac20489143bbd0203423a83dcee2a2054)`(Quaternion q)` 

#### `public float `[`quaternion_magnitude`](#quaternion_8c_1a000103a86287e5f7da7da34a86dc4c3b)`(Quaternion q)` 

#### `public Transform `[`transform_identity`](#transform_8c_1a371675cf0b68a1097914fbe0965f99c9)`()` 

#### `public Matrix4f `[`transform_to_matrix`](#transform_8c_1a623eb0037998d17f4ab86574b98505b5)`(struct transform transform)` 

#### `public Vector3f `[`vector3f_add`](#vector3f_8c_1ab2768621fa85125a5b4c76117004da18)`(Vector3f a,Vector3f b)` 

#### `public Vector3f `[`vector3f_sub`](#vector3f_8c_1ab69ea26f98e29bf9c23e915552bc6aed)`(Vector3f a,Vector3f b)` 

#### `public Vector3f `[`vector3f_mul`](#vector3f_8c_1ad9a57675d586de60b38e369712218a42)`(Vector3f a,Vector3f b)` 

#### `public Vector3f `[`vector3f_make`](#vector3f_8c_1adf85b2db6c9fde5d774560ccb9e98ce0)`(float x,float y,float z)` 

#### `public Vector3f `[`vector3f_scale`](#vector3f_8c_1a35c390f13ab22cd423aca8d732ba4d42)`(Vector3f v,float f)` 

#### `public float `[`vector3f_dot`](#vector3f_8c_1a0e48f94db254b0f210d6c18a44042b13)`(Vector3f v1,Vector3f v2)` 

#### `public Vector3f `[`vector3f_cross`](#vector3f_8c_1a8a278c35766357191b397a325e450737)`(Vector3f v1,Vector3f v2)` 

#### `public Vector3f `[`vector3f_div_scalar`](#vector3f_8c_1a690f5971405c43437aa7c80fc5fceac8)`(Vector3f v,float s)` 

#### `public Vector3f `[`vector3f_normalize`](#vector3f_8c_1a8ec1c0db77fe960ffa7ea7ea1dd54213)`(Vector3f v)` 

#### `public float `[`vector3f_magnitude`](#vector3f_8c_1a0b9405cbc5a857bcd4041fcfc8e42222)`(Vector3f v)` 

#### `public Vector3f `[`vector3f_negate`](#vector3f_8c_1aefbdec22da1198015f92b48dd2b9fa85)`(Vector3f v)` 

#### `public Vector3f `[`vector3f_zero`](#vector3f_8c_1ae540e5271ec5a4127e904945f5457cf4)`()` 

#### `public Vector3f `[`vector3f_one`](#vector3f_8c_1a299963542d180638e5ba770e95fdc260)`()` 

#### `public Vector3f `[`vector3f_mul_scalar`](#vector3f_8c_1acbd8f8b88ff97bf104faba163d319bb8)`(Vector3f v,float s)` 

#### `public Vector3f `[`vector3f_rotate`](#vector3f_8c_1a6b77abed99eac87b4e97babcf7407783)`(Vector3f v,Quaternion q)` 

Rotates a vector using a quaternion 
#### Parameters
* `vA` the vector to rotate 

* `qA` the quaternion as rotation 

#### Returns
the vector rotated

#### `public Vector4f `[`vector4f_one`](#vector4f_8c_1a8bde3ebed5df63ce8a87dcd69f4127ef)`()` 

Generated by [Moxygen](https://sourcey.com/moxygen)