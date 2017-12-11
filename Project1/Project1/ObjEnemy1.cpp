//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjEnemy1.h"

//使用するネームスペース
using namespace GameL;

CObjEnemy1::CObjEnemy1()
{

}

CObjEnemy1::~CObjEnemy1()
{

}

//イニシャライズ
void CObjEnemy1::Init()
{

}

//アクション
void CObjEnemy1::Action()
{

}

//ドロー
void CObjEnemy1::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画元表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 64.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 128.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}