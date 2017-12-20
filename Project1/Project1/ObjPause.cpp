//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

void CObjPause::Init()
{
	m_key_flag = false;
}

void CObjPause::Action()
{
	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag == false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

void CObjPause::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float cl[4] = { 1.0f, 0.0f, 1.0f, 1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 799.0f;
	src.m_bottom = 400.0f;

	//表示位置
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	Font::StrDraw(L"ポーズ", 325, 100, 50, c);
	Font::StrDraw(L"ゲームに戻る", 100, 400, 30, c);
	Font::StrDraw(L"タイトルに戻る", 500, 400, 30, c);

	if (Input::GetVKey(VK_LEFT) == true)
	{
		if (m_key_flag == true)
		{
			Font::StrDraw(L"ゲームに戻る", 100, 400, 30, cl);
		}
	}
	else if(Input::GetVKey(VK_RIGHT) == true)
	{
		if (m_key_flag == true)
		{
			Font::StrDraw(L"タイトルに戻る", 500, 400, 30, cl);
		}
	}

}