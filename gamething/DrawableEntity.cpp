
#include "DrawableEntity.h"

GLuint DrawableEntity::getProgramHandle() {
    return _programHandle;
}

void DrawableEntity::setProgramHandle(GLuint value) {
    _programHandle = value;
}

std::vector<GLfloat> DrawableEntity::getMesh() {
    return meshVector;
}

void DrawableEntity::setMesh(std::vector<GLfloat> vector) {
    meshVector = vector;
}

void DrawableEntity::draw() {

    // test
    std::vector<VertexStruct>* cubeMeshData = createCube();

    // gl here

    delete cubeMeshData;
}

std::vector<VertexStruct>* DrawableEntity::createCube() {

    std::vector<VertexStruct> *pRetMesh = new std::vector<VertexStruct>();

    VertexStruct v1;
    v1.x = -1.0f;
    v1.y = -1.0f;
    v1.z = 1.0f;

    VertexStruct v2;
    v2.x = 1.0f;
    v2.y = -1.0f;
    v2.z = 1.0f;

    VertexStruct v3;
    v3.x = 1.0f;
    v3.y = 1.0f;
    v3.z = 1.0f;

    VertexStruct v4;
    v4.x = -1.0f;
    v4.y = 1.0f;
    v4.z = 1.0f;

    VertexStruct v5;
    v5.x = -1.0f;
    v5.y = -1.0f;
    v5.z = -1.0f;

    VertexStruct v6;
    v6.x = 1.0f;
    v6.y = -1.0f;
    v6.z = -1.0f;

    VertexStruct v7;
    v7.x = 1.0f;
    v7.y = 1.0f;
    v7.z = -1.0f;

    VertexStruct v8;
    v8.x = -1.0f;
    v8.y = 1.0f;
    v8.z = -1.0f;

    pRetMesh->push_back(v1);
    pRetMesh->push_back(v2);
    pRetMesh->push_back(v3);
    pRetMesh->push_back(v4);
    pRetMesh->push_back(v5);
    pRetMesh->push_back(v6);
    pRetMesh->push_back(v7);
    pRetMesh->push_back(v8);

    return pRetMesh;
}
