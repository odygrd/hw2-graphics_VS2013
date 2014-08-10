#include <iostream>
#include <string>

#ifndef SHADERS_H 
#define SHADERS_H  

std::string textFileRead (const char * filename) ;
void programerrors (const GLint program) ;
void shadererrors (const GLint shader) ;
GLuint initshaders (GLenum type, const char * filename) ;
GLuint initprogram (GLuint vertexshader, GLuint fragmentshader) ;

#endif 
