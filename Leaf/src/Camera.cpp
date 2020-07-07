#include "Camera.h"

Camera::Camera()
{
	m_pos = glm::vec3(0.0f, 0.0f, 3.0);
	m_front = glm::vec3(0.0, 0.0f, -1.0f);
	m_up = glm::vec3(0.0f, 1.0f, 0.0f);

	m_yaw = -90.0f;
}

glm::vec3 Camera::GetPosition() const
{
	return m_pos;
}

glm::vec3 Camera::GetUp() const
{
	return m_up;
}

glm::vec3 Camera::GetFront() const
{
	return m_front;
}

float Camera::GetPitch() const
{
	return m_pitch;
}

float Camera::GetYaw() const
{
	return m_yaw;
}

void Camera::SetPosition(const glm::vec3 pos)
{
	m_pos = pos;
}

void Camera::SetUp(const glm::vec3 up)
{
	m_up = up;
}

void Camera::SetFront(const glm::vec3 front)
{
	m_front = front;
}

void Camera::SetPitch(const float pitch)
{
	m_pitch = pitch;
}

void Camera::SetYaw(const float yaw)
{
	m_yaw = yaw;
}
