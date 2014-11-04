#ifndef __ShaderLoader_H_
#define __ShaderLoader_H_

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ShaderContainer {
private:

    GLuint _programHandle;

    GLuint compileShader(GLenum shader, const char *source);
    char* loadTextFromFile(const char *file);

public:

    GLuint getProgramHandle();

    ShaderContainer(const char *sourceVS, const char *sourceFS);
    ~ShaderContainer();

};

#endif //__ShaderLoader_H_
