#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjhero : public CObj
{
public:
	CObjhero() {};
	~CObjhero() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

protected:
	float m_px;    //位置
	float m_py; 
	float m_vx;    //移動ベクトル
	float m_vy;
	float m_posture; //向き

	int m_ani_timex;  //アニメーションフレーム動作間隔x軸用
	int m_ani_timey;  //アニメーションフレーム動作間隔y軸用
	int m_ani_framex; //描画フレームx軸用
	int m_ani_framey; //描画フレームy軸用
};