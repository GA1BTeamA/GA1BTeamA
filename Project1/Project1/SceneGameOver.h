#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:ゲームオーバー
class CSceneGameOver :public CSceneTitle
{
	public:
		CSceneGameOver();
		~CSceneGameOver();
		void InitScene(); //ゲームオーバの初期化メソッド
		void Scene(); //ゲームオーバの実行中メソッド
	private:
};