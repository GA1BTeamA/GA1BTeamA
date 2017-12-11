//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Objhero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjhero::Init()
{
	m_px = 0.0f;    //位置
	m_py = 0.0f;
	m_vx = 0.0f;    //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0ｆ　左向き1.0ｆ

	m_ani_timex = 0;    //アニメーションフレーム動作間隔x軸
	m_ani_timey = 0;    //アニメーションフレーム動作間隔y軸
	m_ani_framex = 1; //描画フレームx軸
	m_ani_framey = 1; //描画フレームｙ軸
}

//アクション
void  CObjhero::Action()
{
	//移動ベクトルの破棄
	m_vy = 1.0f;

	//キー方向の入力方向
	//x軸移動用
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 0.4f;
		m_posture = 1.0f;
		m_ani_timex+=1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 0.4f;
		m_posture = 0.0f;
		m_ani_timex+=1;
	}
	else
	{
		m_ani_framex=1;  //キー入力が無い場合は静止フレームにする
		m_ani_timex=0;
	}

	if (m_ani_timex > 8)
	{
		m_ani_framex +=1;
		m_ani_timex = 0;
	}
	if (m_ani_framex == 8)
	{
		m_ani_framex = 0;
	}

	//y軸移動用
	if (Input::GetVKey('Z') == true)
	{
		m_vy -= 2.0f;
		m_ani_timey = 4;
	}

	if (m_ani_timey > 8)
	{
		m_ani_framey += 1;
		m_ani_timey = 0;
	}
	if (m_ani_framey == 8)
	{
		m_ani_framey = 0;
	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下
	//m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
}

//ドロー
void  CObjhero::Draw()
{
	//歩き描画用
	int AniDatax[8] =
	{
		-1,0,1,2,3,4,5,6,
	};

	int AniDatay[8] =
	{
		-1,0,0,0,1,1,1,2
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //描画切り取り位置
	RECT_F dst;  //描画先表示位置

	//切り取り位置の設定
	src.m_top    = 64.0f + AniDatax[m_ani_framey] * 64;
	src.m_left   =  0.0f + AniDatax[m_ani_framex] * 64;
	src.m_right  = 64.0f + AniDatax[m_ani_framex] * 64;
	src.m_bottom =128.0f + AniDatax[m_ani_framey] * 64;

	//表示位置の設定
	dst.m_top    =  0.0f+m_py;
	dst.m_left   = (   64.0f*m_posture)+m_px;
	dst.m_right  = (64- 64.0f*m_posture)+m_px;
	dst.m_bottom = 64.0f+m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}