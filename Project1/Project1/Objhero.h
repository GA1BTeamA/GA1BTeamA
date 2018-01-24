#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjBlock.h"
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

	//主人公の位置取得用
	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	//主人公の位置変更用
	void SetX (float x ) { m_px =  x; }
	void SetY (float y ) { m_py =  y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	int GetBT() { return m_block_type; }

	//ブロックとの衝突状態確認
	void SetUp(bool b) { m_hit_up    = b; }
	void SetDown(bool b) { m_hit_down  = b; }
	void SetLeft(bool b) { m_hit_left  = b; }
	void SetRight(bool b) { m_hit_right = b; }
	void SetBT(int t) { m_block_type = t; }
	void SetGoalBlock(int goalblock) { goal_block = goalblock; }


protected:
	float m_px;    //位置
	float m_py; 
	float m_vx;    //移動ベクトル
	float m_vy;
	float m_posture; //向き

	int m_ani_timex;  //アニメーションフレーム動作間隔x軸用
	int m_ani_timey;  //アニメーションフレーム動作間隔y軸用
	int m_ani_timea;  //アニメーションフレーム動作間隔アクション用
	int m_ani_framex; //描画フレームx軸用
	int m_ani_framey; //描画フレームy軸用
	int m_ani_framea; //描画フレームアクション用

	//ブロックとの衝突状態確認用変数
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//ジャンプボタンフラグ
	bool button_flag_up;

	//チェンジボタンフラグ
	bool button_flag_z;

	//描画切り替え
	bool Draw_flag;

	//体力
	int HP;

	//踏んでいるblockの種類を確認用
	int m_block_type;

	int goal_block;
	int key_block;
	int shoes_block;
};