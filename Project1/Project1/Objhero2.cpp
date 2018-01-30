//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Objhero2.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

//ブロック＆主人公切り替え false=妹用 true=兄用
extern  bool g_hero_change;

//グローバル位置
 float g_px;

//兄妹の画面切り替えフラグ
extern bool screen_change_flag;

extern bool shose_block;

//イニシャライズ
void CObjhero2::Init()
{
	m_px = 380.0f;    //位置
	m_py = 512.0f;

	//g_px = 0.0f; //グローバル位置

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
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//ジャンプボタンフラグ
	button_flag_up = false;

	//チェンジボタンフラグ
	button_flag_z = false;

	//描画切り替え
	Draw_flag = true;

	//体力
	HP = 1;

	//ブロック＆主人公切り替え false=妹用 true=兄用
	g_hero_change = false;

	//ゴールブロック
	goal_block = 0;

	m_block_type = 15;

	Hits::SetHitBox(this, m_px, m_py, 29, 55, ELEMENT_PLAYER, OBJ_HERO2, 1);
}

//アクション
void  CObjhero2::Action()
{

	



	if (g_hero_change == false)
	{

		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);

		// ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//HitBoxの位置の変更
		CHitBox* hit = Hits::GetHitBox(this);

		//敵と当たっているか確認
		if (hit->CheckObjNameHit(OBJ_ENEMY1) != nullptr)
		{
			//主人公が敵とどの角度で当たっているか確認
			HIT_DATA** hit_data;							//当たった時の細かな情報を入れるための構造体
			hit_data = hit->SearchObjNameHit(OBJ_ENEMY1);	//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

			//敵の左右に当たったら
			float r = hit_data[0]->r;
			//右
			if ((r <= 45 && r >= 0) || r >= 315)
			{
				HP -= 1;
			}
			//上
			if (r >= 45 && r <= 135)
			{
				HP -= 1;
			}
			//左
			if (r >= 135 && r <= 225)
			{
				HP -= 1;
			}
			if (r >= 225 && r <= 315)
			{
				HP -= 1;
			}
		}

		//主人公切り替え
		if (Input::GetVKey('Z') == true)
		{
			if (button_flag_z == true && m_hit_down == true)
			{

				g_hero_change = true;

				//ブロック情報を持ってくる
				CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

				g_px = block->GetgsScroll();

				screen_change_flag = true;

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
			m_ani_timex += 2;

		}
		else if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx -= 0.4f;
			m_posture = 0.0f;
			m_ani_timex += 2;
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
				m_vy -= 11.0f;
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

		//摩擦
		m_vx += -(m_vx*0.098);

		//自由落下
		m_vy += 9.8 / (16.0f);

		//位置の更新
		m_px += m_vx;
		m_py += m_vy;



		//ゲームオーバーに切り替え
		if (m_py > 850 || HP == 0)
		{
			g_px = 0.0f;
			Scene::SetScene(new CSceneGameOver());
		}

		if (GetBT() == 12 || GetBT() == 6)
		{
			HP -= 1;

		}

		if (GetBT() == 3 && shose_block == false)
		{
			HP -= 1;
		}

		if (goal_block == 11)
		{
			Scene::SetScene(new CSceneClear());
		}

		hit->SetPos(m_px + 18, m_py+9);
	}
}

//ドロー
void  CObjhero2::Draw()
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

	if (g_hero_change == false)
		m = 1.0f;
	else
		m = 0.5f;

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,m };

	RECT_F src;  //描画切り取り位置
	RECT_F dst;  //描画先表示位置

	if (HP == 0)
	{
		//切り取り位置の設定
		src.m_top = 192.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 256.0f;
	}
	else
	{
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

	}

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (g_hero_change == false)
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
		dst.m_left = (64.0f*m_posture) + m_px-g_px + block->GetScroll();
		dst.m_right = (64 - 64.0f*m_posture) + m_px-g_px + block->GetScroll();
		dst.m_bottom = 64.0f + m_py;
	}

	//描画
	Draw::Draw(10, &src, &dst, c, 0.0f);
}