#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	_vertexPath = vertexPath;
	_fragmentPath = fragmentPath;
}

void Shader::load()
{
	std::string vertexCode, fragmentCode;
	std::ifstream vShaderFile,fShaderFile;
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(_vertexPath);
		fShaderFile.open(_fragmentPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR:shader::file_not_succesfuliy_read" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR:shader::vertex::compilation_failed\n" << infoLog << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR:shader::fragment::compilation_failed\n" << infoLog << std::endl;
	}

	GLProgram = glCreateProgram();
	glAttachShader(GLProgram, vertex);
	glAttachShader(GLProgram, fragment);
	glLinkProgram(GLProgram);
	glGetProgramiv(GLProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(GLProgram, 512, NULL, infoLog);
		std::cout << "ERROR:shader::program::linking_failed\n" << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use()
{
	glUseProgram(GLProgram);
}

void Shader::setBool(const std::string & name, bool value) const
{
	glUniform1i(glGetUniformLocation(GLProgram, name.c_str()), (int)value);
}

void Shader::setInt(const std::string & name, int value) const
{
	glUniform1i(glGetUniformLocation(GLProgram, name.c_str()), (int)value);
}

void Shader::setFloat(const std::string & name, float value) const
{
	glUniform1f(glGetUniformLocation(GLProgram, name.c_str()), value);
}

void Shader::setVec4(const std::string & name, float v0, float v1, float v2, float v3) const
{
	glUniform4f(glGetUniformLocation(GLProgram, name.c_str()), v0, v1, v2, v3);
}


Shader::~Shader()
{
}
