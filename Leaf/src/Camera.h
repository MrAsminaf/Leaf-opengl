#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
private:
	// current camera position in 3D space
	glm::vec3 m_pos;

	// up vector
	glm::vec3 m_up;

	// direction vector
	glm::vec3 m_front;

	// variables for Euler angles
	float m_pitch;
	float m_yaw;
public:
	Camera();

	// getters
	glm::vec3 GetPosition() const;
	glm::vec3 GetUp() const;
	glm::vec3 GetFront() const;
	float GetPitch() const;
	float GetYaw() const;

	// setters
	void SetPosition(const glm::vec3 pos);
	void SetUp(const glm::vec3 up);
	void SetFront(const glm::vec3 front);
	void SetPitch(const float pitch);
	void SetYaw(const float yaw);
};