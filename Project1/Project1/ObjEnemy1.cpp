//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy1.h"

//使用するネームスペース
using namespace GameL;

CObjEnemy1::CObjEnemy1(float x, float y)
{
	//位置
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjEnemy1::Init()
{
	//m_px = 0.0f;		//位置
	//m_py = 0.0f;
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0ｆ　左向き1.0ｆ

	m_ani_timex = 0;    //アニメーションフレーム動作間隔x軸
	m_ani_timey = 0;	//アニメーションフレーム動作間隔y軸
	m_ani_framex = 1;   //描画フレームx軸
	m_ani_framey = 1;	//描画フレームy軸

	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	m_move = false; //true=右　false=左

	Hits::SetHitBox(this, m_px, m_py, 64, 50, ELEMENT_ENEMY, OBJ_ENEMY1, 1);
}

//アクション
void CObjEnemy1::Action()
{


	//落下
	if (m_py > 1000.0f)
	{
		;
	}

	//通常速度
	m_speed_power = 0.35f;
	m_ani_max_time = 6;
	/*
	//ブロック衝突で向き変更
	if (m_hit_left == true)
	{
		m_move = true;
	}
	if (m_hit_right == true)
	{
		m_move = false;
	}
	*/
	//方向
	/*if (m_move == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_timex += 1;
	}
	else if (m_move == false)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_timex += 1;
	}

	if (m_ani_timex > m_ani_max_time)
	{
		m_ani_framex += 1;
		m_ani_timex = 0;
	}

	if (m_ani_framex == 4)
	{
		m_ani_framex = 0;
	}*/

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8/(16.0f);
	
	//ブロックタイプ検知用の変数がないためのダミー
	int d;
	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	float x = pb->GetScroll() + m_px;

	pb->BlockHit(&x, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d);

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py+12);

	if (m_px < 0 || m_px > 2500 || m_py < 0 || m_py > 600)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
		
	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
	
}

//ドロー
void CObjEnemy1::Draw()
{
	int AniDatax[4] =
	{
		0, 1, 2, 1,
	};

	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画元表示位置

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniDatax[m_ani_framex] * 64;
	src.m_right = 64.0f + AniDatax[m_ani_framex] * 64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = m_py;
	dst.m_left = (64.0f * m_posture) + m_px + block->GetScroll();
	dst.m_right = (64 - 64.0f * m_posture) + m_px + block->GetScroll();
	dst.m_bottom = m_py+64.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}