#pragma once

struct Vector3 {
	float x;
	float y;
	float z;
};
struct Matrix4x4 {
	float m[4][4];
};

//行列同士の計算・転置・逆
Matrix4x4 Add(const Matrix4x4& a, const Matrix4x4& b);
Matrix4x4 Subtract(const Matrix4x4& a, const Matrix4x4& b);
Matrix4x4 Multiply(const Matrix4x4& a, const Matrix4x4& b);
float Determinant(const Matrix4x4 m);
Matrix4x4 Scalar(float a, const Matrix4x4& m);
Matrix4x4 Inverse(const Matrix4x4& a);
Matrix4x4 Transpose(const Matrix4x4& a);
Matrix4x4 MakeIdentity4x4();

//SRTのやつ
Matrix4x4 MakeScaleMatrix(const Vector3& scale);
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
Matrix4x4 MakeRotateXMatrix(float radianX);
Matrix4x4 MakeRotateYMatrix(float radianY);
Matrix4x4 MakeRotateZMatrix(float radianZ);
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

//射影・ビューポート変換行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);