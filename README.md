# CGLMath
Simple library for OpenGL math using structs instead of the unreadable arrays

# What is this

The design principle of this library is not to write something fast using SIMD instructions or advanced hardware tricks, but just a human readable C OpenGL math library where you can write:

```C 
struct vector3f player_forward = quaternion_forward(player.camera.rotation);
```

like a normal human being; instead of the insanity of all the other libraries because arrays can't be returned in C

```C
float player_forward[3] = VECTOR_INIT;
quaternion_forward(player.camera.rotation, player_forward);
```

50% less lines of code for every library call!
