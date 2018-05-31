#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>

class Shader
{
private:
	const char * _vertexPath;
	const char* _fragmentPath;

	unsigned int GLProgram;

public:
	Shader(const char * vertexPath, const char * fragmentPath);
	~Shader();
	void load();
	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setVec4(const std::string &name, float v0, float v1, float v2, float v3) const;
};

