
#include "Triangle.h"

float triangleVertices[] = {
	-0.5f,-0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.5f, 0.5f, 0.0f
};
Triangle::Triangle() {
    unsigned int VBO;
    // generate 
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind 
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

    // Change this line:
    // From: glVertexAttribIPointer(0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    // To:
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);
}
void Triangle::draw(){
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}