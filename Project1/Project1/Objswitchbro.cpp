//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "Objswitchbro.h"
#include "Objhero.h"


//使用するネームスペース
using namespace GameL;

CObjswitchbro::CObjswitchbro()
{
}

//イニシャライズ
void CObjswitchbro::Init()
{
}

//アクション
void CObjswitchbro::Action()
{
}

//ドロー
void CObjswitchbro::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画元表示位置

				//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 288.0f;
	dst.m_right = 320.0f;
	dst.m_bottom = 48.0f;

	Draw::Draw(13, &src, &dst, c, 0.0f);
}
