#include "Matrix4x4.h"

Matrix4x4::Matrix4x4()
{
}

void Matrix4x4::setIdentity()
{
	::memset(m_mat, 0, sizeof(float) * 16);
	m_mat[0][0] = 1;
	m_mat[1][1] = 1;
	m_mat[2][2] = 1;
	m_mat[3][3] = 1;
}

void Matrix4x4::setTranslation(const Vector3D& translation)
{
	setIdentity();
	m_mat[3][0] = translation.m_x;
	m_mat[3][1] = translation.m_y;
	m_mat[3][2] = translation.m_z;
}

void Matrix4x4::setScale(const Vector3D& scale)
{
	setIdentity();
	m_mat[0][0] = scale.m_x;
	m_mat[1][1] = scale.m_y;
	m_mat[2][2] = scale.m_z;
}

void Matrix4x4::setOrthoLH(float width, float height, float near_plane, float far_plane)
{
	setIdentity();
	m_mat[0][0] = 2.0f / width;
	m_mat[1][1] = 2.0f / height;
	m_mat[2][2] = 1.0f / (far_plane - near_plane);
	m_mat[3][3] = -(near_plane / (far_plane - near_plane));
}

Matrix4x4::~Matrix4x4()
{
}