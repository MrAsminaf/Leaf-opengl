#include "ShaderProgram.h"

bool ShaderProgram::CheckShaderCompilationStatus(const GLuint& shaderID) const
{
	int success;
	char infoLog[512];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED	\n" << infoLog << std::endl;
		return -1;
	}
	return 0;
}

bool ShaderProgram::CheckProgramLinkingStatus(const GLuint& programID) const
{
	int success;
	char infoLog[512];
	glGetProgramiv(programID, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(programID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED " << infoLog << std::endl;
		return -1;
	}
	return 0;
}

ShaderProgram::ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	unsigned int vertexShaderID, fragmentShaderID;
	
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	CheckShaderCompilationStatus(vertexShaderID);
	CheckShaderCompilationStatus(fragmentShaderID);

	m_shaderProgramID = glCreateProgram();
	glAttachShader(m_shaderProgramID, vertexShaderID);
	glAttachShader(m_shaderProgramID, fragmentShaderID);
	glLinkProgram(m_shaderProgramID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

void ShaderProgram::Use()
{
	glUseProgram(m_shaderProgramID);
}

GLuint ShaderProgram::GetID() const
{
	return m_shaderProgramID;
}
