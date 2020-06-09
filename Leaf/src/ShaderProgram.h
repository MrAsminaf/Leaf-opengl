#include <iostream>
#include <glad/glad.h>

class ShaderProgram
{
private:
	GLuint m_shaderProgramID;
private:
	bool CheckShaderCompilationStatus(const GLuint& shaderID) const;
	bool CheckProgramLinkingStatus(const GLuint& programID) const;
public:
	ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
	void Use();

	GLuint GetID() const;
};