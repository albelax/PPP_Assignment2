#ifndef VEC4_H__
#define VEC4_H__

//#include "Mat4.h"
#ifdef __linux__
  #include <GL/gl.h>
#endif
#ifdef __APPLE__
  #include <OpenGL/gl.h>
#endif

class Mat4;

class Vec4
{

public:
  Vec4(const Vec4 &_rhs) = default;
  Vec4(GLfloat _x = 0.0f, GLfloat _y = 0.0f,
       GLfloat _z = 0.0f, GLfloat _w = 1.0f) : m_x(_x), m_y(_y), m_z(_z), m_w(_w){}

  void colourGL() const;

  Vec4 cross(const Vec4 &_rhs) const;

  float dot(const Vec4 &_rhs) const;
  float length() const;
  float lengthSquared() const;
  void normalGL() const;
  void normalize();

  Vec4 operator * (const Mat4 &_r) const;
  Vec4 operator * (GLfloat _rhs) const;
  void operator *= (GLfloat _rhs);
  Vec4 operator + (const Vec4 &_rhs) const;
  void operator += (const Vec4 &_rhs);
  Vec4 operator - (const Vec4 &_rhs) const;
  //void operator -= (const Vec4 &_rhs);
  bool operator == (const Vec4 &_rhs) const;
  GLfloat & operator [](int _i);

  void set(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w = 1.0f);
  void vertexGL() const;





  union // unions are cheap, its values occupy the same area of memory, also works as an array, handy for GL
  {
    GLfloat m_openGL[4];
    struct
    {
      GLfloat m_x;
      GLfloat m_y;
      GLfloat m_z;
      GLfloat m_w;
    };
  };

};

#endif
