//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

//ブロック＆主人公切り替え false=妹用 true=兄用
extern  bool g_hero_change;

//イニシャライズ
void CObjBackground::Init()
{
	m_scroll = 0.0f;
	m_x1 = 0.0f;
	m_x2 = 800.0f;
	m_key_flag = false;

	
}

//アクション
void CObjBackground::Action()
{
	//主人公の位置を取得
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);

	if (g_hero_change == false)
	{
		hx = hero2->GetX();
		hy = hero2->GetY();
		//背景1・2の動作
		if (hx > 400)
		{
			m_x1 -= hero2->GetVX();
			m_x2 -= hero2->GetVX();
		}
		else if (hx < 80)
		{
			m_x1 -= hero2->GetVX();
			m_x2 -= hero2->GetVX();
		}
	}
	else
	{
		hx = hero->GetX();
		hy = hero->GetY();

		//背景1・2の動作
		if (hx > 400)
		{
			m_x1 -= hero->GetVX();
			m_x2 -= hero->GetVX();
		}
		else if (hx < 80)
		{
			m_x1 -= hero->GetVX();
			m_x2 -= hero->GetVX();
		}
	}


	
	
	if (m_x1 < -800.0f)
	{
		m_x1 = m_x2 + 800;
	}
	if (m_x1 > 800.0f)
	{
		m_x1 = m_x2 - 800;
	}
	
	if (m_x2 < -800.0f)
	{
		m_x2 = m_x1 + 800;
	}
	if (m_x2 > 800.0f)
	{
		m_x2 = m_x1 - 800;
	}

	//ポーズ画面に移動(の背景表示)
	if (Input::GetVKey('C') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CScenePause);

			m_key_flag == false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjBackground::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 400.0f;

	//背景1位置設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//背景2位置設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}