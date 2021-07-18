#pragma once
class Vector3D
{
public:
	Vector3D() : m_x(0), m_y(0), m_z(0)
	{
	}

	Vector3D(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
	{
	}

	Vector3D(const Vector3D& vector) : m_x(vector.m_x), m_y(vector.m_y), m_z(vector.m_z)
	{
	}

	~Vector3D();

private:
	float m_x, m_y, m_z;
};

