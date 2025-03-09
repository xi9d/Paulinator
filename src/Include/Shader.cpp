#include <iostream>
#include <fstream>
#include <sstream>
#include "Include/Shader.h"
using namespace std;

// implementation of the shader
Shader::Shader(const char* vertexPath, const char* fragmentPath) {
	ifstream vShaderFile(vertexPath);
	ifstream fShaderFile(fragmentPath);



	stringstream vShaderStream, fShaderStream;
	vShaderStream << vShaderFile.rdbuf();
	fShaderStream << fShaderFile.rdbuf();

	string vertexCode = vShaderStream.str();
	string fragmentCode = fShaderStream.str();


	const char* vShaderSrc = vertexCode.c_str();
	const char* fShaderSrc = fragmentCode.c_str();

	//building the vertex 
	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderSrc, NULL);
	glCompileShader(vertex);

	//building the fragment
	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderSrc, NULL);
	glCompileShader(fragment);



	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);







}
// implement the 'use function'
void Shader::use(){
	glUseProgram(ID);
}