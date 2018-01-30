#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjBackground : public CObj
{
public:
	CObjBackground() {};
	~CObjBackground() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_scroll;  //左右スクロール用
	float bm_x1;  //兄背景1の位置情報
	float bm_x2;  //兄背景2の位置情報
	float sm_x1;  //妹背景1の位置情報
	float sm_x2;  //妹背景2の位置情報
	bool m_key_flag;

	//主人公の位置を取得
	float hx;
	float hy;
};

