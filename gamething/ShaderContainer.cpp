#include <glew.h>
#include <stdio.h>
#include <stdlib.h>
#include "ShaderContainer.h"

GLuint ShaderContainer::getProgramHandle() {

    return _programHandle;
}

GLuint ShaderContainer::compileShader(GLenum shader, const char *source) {

    GLuint shaderHandle = glCreateShader(shader);
    glShaderSource(shaderHandle, 1, &source, NULL);
    glCompileShader(shaderHandle);

    GLint rc;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &rc);
    if(rc == 0) {
        GLchar errorLog[1024] = {0};
        glGetShaderInfoLog(shaderHandle, sizeof(errorLog), NULL, errorLog);
        std::cout << "Error compiling shader:" << shader << ", " << errorLog;
    }

    return shaderHandle;
}

ShaderContainer::ShaderContainer(const char *filenameVs, const char *filenameFs) {

    const char *sourceVs = loadTextFromFile(filenameVs);
    const char *sourceFs = loadTextFromFile(filenameFs);

    _programHandle = glCreateProgram();

    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, sourceVs);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, sourceFs);

    glAttachShader(_programHandle, vertexShader);
    glAttachShader(_programHandle, fragmentShader);

    glLinkProgram(_programHandle);

    GLint rc;
    glGetProgramiv(_programHandle, GL_LINK_STATUS, &rc);
    if (rc == 0) {
        GLchar errorLog[1024] = {0};
        glGetProgramInfoLog(_programHandle, sizeof(errorLog), NULL, errorLog);
        printf("Error linking shader program: '%s'\n", errorLog);
        exit(EXIT_FAILURE);
    }

    glValidateProgram(_programHandle);

    // Won't delete, but will be marked as deletable
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

char* ShaderContainer::loadTextFromFile(const char *file) {

    FILE *currentFile = fopen(file, "rt");
    fseek(currentFile, 0, SEEK_END);
    int count = (int)ftell(currentFile);

    rewind(currentFile);
    char *data = (char *)malloc(sizeof(char)*(count + 1));
    count = (int)fread(data, sizeof(char), count, currentFile);
    data[count] = '\0';

    fclose(currentFile);

    return data;

}

ShaderContainer::~ShaderContainer() {

    glDeleteProgram(_programHandle);
}
