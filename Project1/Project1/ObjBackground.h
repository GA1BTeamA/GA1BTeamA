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
	float m_x1;  //背景1の位置情報
	float m_x2;  //背景2の位置情報
	bool m_key_flag;

	//主人公の位置を取得
	float hx;
	float hy;
};

