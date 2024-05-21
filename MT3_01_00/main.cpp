#include <Novice.h>
#include <cmath>
#include "mathFunction.h"

const char kWindowTitle[] = "GC1B_12_ハラサワミツタカ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

struct Vector3 {
	float x;
	float y;
	float z;
};
struct Matrix4x4 {
	float m[4][4];
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 worldScale = { 1,1,1 };
	Vector3 worldRotate = { 0,0,0 };
	Vector3 worldTranslate = { 0,0,0 };

	Vector3 cameraScale = { 1,1,1 };
	Vector3 cameraRotate = { 0,0,0 };
	Vector3 cameraPosition = { 0,0,0 };

	float fovY = 0.45f;
	float nearClip = 0.1f;
	float farClip = 100.0f;

	float left = 0.0f;
	float top = 0.0f;
	float minDepth = 0.0f;
	float maxDepth = 1.0f;


	Matrix4x4 worldMatrix = MakeAffineMatrix(worldScale, worldRotate, worldTranslate);
	Matrix4x4 cameraMatrix = MakeAffineMatrix(cameraScale, cameraRotate, cameraPosition);
	Matrix4x4 viewMatrix = Inverse(cameraMatrix);
	Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(fovY, float(kWindowWidth) / float(kWindowHeight), nearClip, farClip);
	Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	Matrix4x4 viewportMatrix = MakeViewportMatrix(left, top, float(kWindowWidth), float(kWindowHeight), minDepth, maxDepth);
	
	
	const Vector3 kLocalVertices[3] = { 0 };
	Vector3 screenVertices[3] = { 0 };
	for (uint32_t i = 0; i < 3; i++) {
		Vector3 ndcVertex = Transform(kLocalVertices[i], worldViewProjectionMatrix);
		screenVertices[i] = Transform(ndcVertex, viewportMatrix);
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
