//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Objhero.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

//ブロック＆主人公切り替え false=妹用 true=兄用
extern  bool g_hero_change;

//イニシャライズ
void CObjhero::Init()
{
	m_px = 90.0f;    //位置
	m_py = 512.0f;
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

	//ジャンプボタンフラグ
	button_flag_up = false;

	//チェンジボタンフラグ
	button_flag_z = false;

	//描画切り替え
	Draw_flag=true;

	//体力
	HP = 1;

	m_block_type = 15;

	goal_block = 0;
}

//アクション
void  CObjhero::Action()
{

	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	if (g_hero_change == true)
	{


		//主人公切り替え
		if (Input::GetVKey('Z') == true)
		{
			if (button_flag_z == true && m_hit_down == true)
			{

				g_hero_change = false;
				
				button_flag_z = false;
			}
		}

		else
		{
			button_flag_z = true;
		}

		//キー方向の入力方向
		//x軸移動用
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx += 0.4f;
			m_posture = 1.0f;
			m_ani_timex += 1;

		}
		else if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx -= 0.4f;
			m_posture = 0.0f;
			m_ani_timex += 1;
		}
		else
		{
			m_ani_framex = 1;  //キー入力が無い場合は静止フレームにする
			m_ani_timex = 0;
		}

		if (m_ani_timex > 8)
		{
			m_ani_framex += 1;
			m_ani_timex = 0;
		}

		if (m_ani_framex == 8)
		{
			m_ani_framex = 0;
		}

		//y軸移動用
		if (Input::GetVKey(VK_UP) == true)
		{
			if (button_flag_up == true && m_hit_down == true)
			{
				m_vy -= 12.0f;
				button_flag_up = false;
			}
		}
		else
		{
			button_flag_up = true;
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

	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	if (m_py > 850 || HP == 0)
	{
		Scene::SetScene(new CSceneGameOver());
	}

	if (GetBT() == 3 || GetBT() == 12 || GetBT() == 6)
	{
		Scene::SetScene(new CSceneGameOver());
	}

	if (goal_block == 11)
	{
		Scene::SetScene(new CSceneClear());
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

	//明度
	float m;

	if (g_hero_change == true)
		m = 1.0f;
	else
		m = 0.5f;

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,m};

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

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (g_hero_change == true)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f*m_posture) + m_px ;
		dst.m_right = (64 - 64.0f*m_posture) + m_px ;
		dst.m_bottom = 64.0f + m_py;
	}
	else
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f*m_posture) + m_px + block->GetScroll();
		dst.m_right = (64 - 64.0f*m_posture) + m_px + block->GetScroll();
		dst.m_bottom = 64.0f + m_py;
	}

	//描画
	Draw::Draw(3, &src, &dst, c, 1.0f);
}