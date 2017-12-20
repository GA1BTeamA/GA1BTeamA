//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

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
	//背景1の動作
	m_x1 -= 1.0f;
	if (m_x1 < -800.0f)
		m_x1 = 800;
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

	//背景2の動作
	m_x2 -= 1.0f;
	if (m_x2 < -800.0f)
		m_x2 = 800;
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
	src.m_right = 799.0f;
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