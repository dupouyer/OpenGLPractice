#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
	const char * _vertexPath;
	const char* _fragmentPath;

public:
	unsigned int GLProgram;

	Shader(const char * vertexPath, const char * fragmentPath);
	~Shader();
	void load();
	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setVec4(const std::string &name, float v0, float v1, float v2, float v3) const;
	void setMat4(const std::string &name, glm::mat4 &mat4) const;
};

