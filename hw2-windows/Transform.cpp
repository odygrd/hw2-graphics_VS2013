// Transform.cpp: implementation of the Transform class.

// Note: when you construct a matrix using mat4() or mat3(), it will be COLUMN-MAJOR
// Keep this in mind in readfile.cpp and display.cpp

#include "Transform.h"

// Helper rotation function.  Please implement this.  
mat3 Transform::rotate(const float degrees, const vec3& axis) 
{
	float radian = degrees / 180.0 * pi;
	float x = axis.x, y = axis.y, z = axis.z;
	mat3 Identity;
	mat3 aa(x*x, x*y, x*z,
		x*y, y*y, y*z,
		x*z, y*z, z*z);
	mat3 Astar(0.0, -z, y,
		z, 0.0, -x,
		-y, x, 0.0);
	mat3 result = cos(radian) * Identity + (1.0 - cos(radian)) * aa + sin(radian) * Astar;
	return result;
}

void Transform::left(float degrees, vec3& eye, vec3& up) 
{
	vec3 y_axis(0.0, 1.0, 0.0);
	eye = eye * rotate(degrees, y_axis);
	up = up * rotate(degrees, y_axis);
}

void Transform::up(float degrees, vec3& eye, vec3& up) 
{
	vec3 x_axis(1.0, 0.0, 0.0);
	eye = eye * rotate(degrees, x_axis);
	up = up * rotate(degrees, x_axis);
}

mat4 Transform::lookAt(const vec3 &eye, const vec3 &center, const vec3 &up) 
{
	vec3 w = glm::normalize(eye - center); //view direction vector
	vec3 u = glm::normalize(glm::cross(up, w)); //right vector
	vec3 v = glm::cross(w, u); //the up vector

	mat4 rotation(u.x, u.y, u.z, 0.0,
		v.x, v.y, v.z, 0.0,
		w.x, w.y, w.z, 0.0,
		0.0, 0.0, 0.0, 1.0);
	mat4 translation(1.0, 0.0, 0.0, -eye.x,
		0.0, 1.0, 0.0, -eye.y,
		0.0, 0.0, 1.0, -eye.z,
		0.0, 0.0, 0.0, 1.0);

	return  (translation * rotation);
}

mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
    mat4 ret;
    //implement the perspective transform
	float d = cos(glm::radians(fovy) / 2) / sin(glm::radians(fovy) / 2);
	float A = -(zFar + zNear) / (zFar - zNear);
	float B = -(2 * zFar*zNear) / (zFar - zNear);

	return glm::mat4(d / aspect, 0, 0, 0,
		0, d, 0, 0,
		0, 0, A, B,
		0, 0, -1, 0);
    return ret;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz) 
{
    mat4 ret;
    // Implement scaling 
	return glm::mat4(sx, 0, 0, 0,
		0, sy, 0, 0,
		0, 0, sz, 0,
		0, 0, 0, 1);
    return ret;
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz) 
{
    mat4 ret;
    // YOUR CODE FOR HW2 HERE
	return glm::mat4(1, 0, 0, tx,
		0, 1, 0, ty,
		0, 0, 1, tz,
		0, 0, 0, 1);
    return ret;
}

// To normalize the up direction and construct a coordinate frame.  
// This function is provided as a helper, in case you want to use it. 
// Using this function (in readfile.cpp or display.cpp) is optional.  
vec3 Transform::upvector(const vec3 &up, const vec3 & zvec) 
{
    vec3 x = glm::cross(up,zvec); 
    vec3 y = glm::cross(zvec,x); 
    vec3 ret = glm::normalize(y); 
    return ret; 
}


Transform::Transform()
{

}

Transform::~Transform()
{

}
