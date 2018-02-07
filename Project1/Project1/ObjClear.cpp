//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameHead.h"

using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;
}

//アクション
void CObjClear::Action()
{
	//エンターキーを押してシーン：タイトルに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag == false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjClear::Draw()
{
	//描画カラー情報

	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//表示位置
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	Font::StrDraw(L"ゲームクリア！", 300, 200, 30, c);
	Font::StrDraw(L"Enterを押してタイトルに戻る", 200, 400, 30, c);

}