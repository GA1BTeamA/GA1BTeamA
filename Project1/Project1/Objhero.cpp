//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Objhero.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjhero::Init()
{
	m_px = 20.0f;    //位置
	m_py = 520.0f;
	m_vx = 0.0f;    //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0ｆ　左向き1.0ｆ

	m_ani_timex = 0;    //アニメーションフレーム動作間隔x軸
	m_ani_timey = 0;    //アニメーションフレーム動作間隔y軸
	m_ani_timea = 0;    //アニメーションフレーム動作間隔アクション
	m_ani_framex = 1; //描画フレームx軸
	m_ani_framey = 1; //描画フレームｙ軸
	m_ani_framea = 1; //描画フレームアクション

	//ブロックとの衝突状態確認用
	m_hit_up=false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//ボタンフラグ
	button_flag = false;

	//描画切り替え
	Draw_flag=true;

	//体力
	HP = 1;

	//主人公切り替え(false=妹,true=兄)
	hero_change = false;

	m_block_type = 15;
}

//アクション
void  CObjhero::Action()
{
	

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
	if (Input::GetVKey(VK_UP) == true)
	{
		if(button_flag== true&&m_hit_down==true)
		{
			m_vy -= 12.0f;
			button_flag = false;
		}
	}
	else
	{
		button_flag = true;
	}

	//空中にいるかの確認
	if (m_hit_down == false)
	{
		Draw_flag = false;

		m_ani_timey += 1;

		if (m_ani_timey > 8)
		{
			m_ani_framey += 1;
			m_ani_timey = 0;
		}
		if (m_ani_framey == 8)
		{
			m_ani_framey = 0;
		}
	}
	else
	{
		Draw_flag = true;
		m_ani_timey = 0;
		m_ani_framey = 0;
	}

	//アクション描画用
	if (Input::GetVKey('A') == true)
	{
		if (button_flag == true)
		{
			button_flag = false;
		}
	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	if (m_py>850)
	{
		Scene::SetScene(new CSceneTitle());
	}

	if (GetBT() == 3 || GetBT() == 12 || GetBT() == 6)
	{
		HP = 0;
	}
}

//ドロー
void  CObjhero::Draw()
{

	//歩き描画用
	int AniDatax[8] =
	{
		-1,0,1,2,3,4,5,6,
	};
	//ジャンプ用
	int AniDatay[9] =
	{
		1,1,2,2,2,2,2,2,0,
	};
	//アクション用
	int AniDataa[3] =
	{
		0,1,2,
	};


	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //描画切り取り位置
	RECT_F dst;  //描画先表示位置
	if (Draw_flag == true)
	{
		//切り取り位置の設定
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniDatax[m_ani_framex] * 64;
		src.m_right = 64.0f + AniDatax[m_ani_framex] * 64;
		src.m_bottom = 128.0f;
	}
	else
	{
		//切り取り位置の設定
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniDatay[m_ani_framey] * 64;
		src.m_right = 64.0f + AniDatay[m_ani_framey] * 64;
		src.m_bottom = 192.0f;
	}

	//表示位置の設定
	dst.m_top    = 0.0f+m_py;
	dst.m_left   = (   64.0f*m_posture)+m_px;
	dst.m_right  = (64- 64.0f*m_posture)+m_px;
	dst.m_bottom = 64.0f+m_py;

	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);
}