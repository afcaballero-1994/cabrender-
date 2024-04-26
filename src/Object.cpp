//
// Created by andres on 28/02/24.
//

#include "Object.hpp"

Mesh::Mesh(const std::vector<Vertex> *vertices) {
    //unsigned int texCoord;


    glCreateBuffers(1, &VBO);
    glNamedBufferStorage(VBO, sizeof(Vertex) * vertices->size(), vertices->data(), GL_DYNAMIC_STORAGE_BIT);

//    glCreateBuffers(1, &texCoord);
//    glNamedBufferStorage(texCoord, vertices->size() * sizeof (float) , vertices->data(), GL_DYNAMIC_STORAGE_BIT);

    glCreateVertexArrays(1, &VAO);

    glVertexArrayVertexBuffer(VAO, 0, VBO, 0, sizeof(Vertex));
    //glVertexArrayVertexBuffer(VAO, 1,texCoord, offsetof(Vertex, texCoordinates), sizeof(float ) * 2);

    glEnableVertexArrayAttrib(VAO, 0);
    glEnableVertexArrayAttrib(VAO, 1);
    glEnableVertexArrayAttrib(VAO, 2);

    glVertexArrayAttribFormat(VAO, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));
    glVertexArrayAttribFormat(VAO, 1, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, normal));
    glVertexArrayAttribFormat(VAO, 2, 2, GL_FLOAT, GL_FALSE, offsetof(Vertex, texCoordinates) );

    //glVertexArrayElementBuffer(VAO, VBO);
    //glVertexArrayElementBuffer(VAO, texCoord);

    glVertexArrayAttribBinding(VAO, 0, 0);
    glVertexArrayAttribBinding(VAO, 1, 0);
    glVertexArrayAttribBinding(VAO, 2, 0);
}

void Mesh::destroy() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
