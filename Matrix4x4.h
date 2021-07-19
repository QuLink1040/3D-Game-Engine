#pragma once
#include <memory>
#include "Vector3D.h"

class Matrix4x4
{
public:
	Matrix4x4();

	void setIdentity();

	void setTranslation(const Vector3D& translation);

	void setScale(const Vector3D& scale);

	void operator*=(const Matrix4x4& matrix);

	void setOrthoLH(float width, float height, float near_plane, float far_plane);

	~Matrix4x4();

private:
	float m_mat[4][4] = {};
};

#pragma once
