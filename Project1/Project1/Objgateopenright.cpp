//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "Objgateopenright.h"
#include "Objhero.h"


//使用するネームスペース
using namespace GameL;

CObjgateopenright::CObjgateopenright()
{
}

//イニシャライズ
void CObjgateopenright::Init()
{
}

//アクション
void CObjgateopenright::Action()
{
}

//ドロー
void CObjgateopenright::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画元表示位置

				//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 150.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 224.0f;
	dst.m_right = 256.0f;
	dst.m_bottom = 160.0f;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}
