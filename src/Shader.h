
//@filename: Shader.h
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>

// the declaration for the shader
class Shader {
public:
	unsigned int ID;
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	//void setUniform(const std::string& name, float value);

};
#endif