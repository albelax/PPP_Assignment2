#ifndef GLFUNCTIONS_H__
#define GLFUNCTIONS_H__
#ifdef __linux__
	#include <GL/gl.h>
#endif
#ifdef __APPLE__
	#include <OpenGL/gl.h>
#endif

#include "Vec4.h"
#include <cmath>

constexpr float TWO_PI= float(2*M_PI); //6.28318530717958647692   //360
constexpr float PI=float(M_PI); //3.14159265358979323846       //180
constexpr float PI2=float(M_PI/2.0); //1.57079632679489661923      //90
constexpr float PI4=float(M_PI/4.0); //0.785398163397448309615     //45

class GLFunctions
{
  public :
    static void cube(GLfloat _w, GLfloat _h, GLfloat _d);
    static void lookAt(Vec4 _eye, Vec4 _look, Vec4 _up);
    static void perspective(float _fovy,float _aspect, float _zNear, float _zFar);
    static float radians(float _deg );
    static void sphere(float _radius, int _precision );
    static void capsule(float _radius,  float _height,   int _precision );
    static void cylinder( float _radius,const float _height, int _slices, int _stacks );

    static void cone(float _base,float _height,  int _slices, int _stacks  );
    static void disk(float _radius,  int _slices );
    static void torus( float _minorRadius, float _majorRadius,int _nSides, int _nRings);
private :
    GLFunctions() = delete;
    ~GLFunctions() = delete;
    GLFunctions(const GLFunctions &) = delete;
    static void fghCircleTable(double **io_sint, double **io_cost, const int _n  );

};



#endif
