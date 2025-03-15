#include "Circle.h"
#include <glad/glad.h>
#include <vector>  // this are igeometric entities that have both magnitude and direction
#include <cmath>// this is use to provide trigromentry like sin() and cos()

using namespace std;
Circle::Circle() {
    // Number of segments to approximate the circle
    const int numSegments = 100;
    const float radius = 1.0f;

    // Generate vertices for the circle
    vector<float> vertices;
    vertices.push_back(0.0f); // Center x
    vertices.push_back(0.0f); // Center y
    vertices.push_back(0.0f); // Center z

    for (int i = 0; i <= numSegments; ++i) {
        float angle = 2.0f * 3.142* i / numSegments;
        vertices.push_back(radius * cos(angle)); // x-coordinate
        vertices.push_back(radius * sin(angle)); // y-coordinate
        vertices.push_back(0.0f);                // z-coordinate
    }

    // Setup VAO and VBO
    unsigned int VBO;
    glGenVertexArrays(1, &VAO); // Generate VAO
    glGenBuffers(1, &VBO);      // Generate VBO

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind and fill VBO with vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Set vertex attributes (position data)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void Circle::draw() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 102); // 1 center + 101 edge vertices
    glBindVertexArray(0);
}
