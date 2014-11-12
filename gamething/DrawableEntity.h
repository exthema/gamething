
#ifndef __DrawableEntity_H_
#define __DrawableEntity_H_

#include <glew.h>
#include <vector>
#include "types.h"

class DrawableEntity {
private:

    std::vector<GLfloat> meshVector;
    GLuint _programHandle;

public:

    GLuint getProgramHandle();
    void setProgramHandle(GLuint value);
    std::vector<GLfloat> getMesh();
    void setMesh(std::vector<GLfloat> meshVector);

    void draw();

    std::vector<VertexStruct>* createCube();

};


#endif //__DrawableEntity_H_
