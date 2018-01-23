//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjGate.h"
#include "Objhero.h"

//使用するネームスペース
using namespace GameL;

//----------------------------------------------

//門ブロック

CObjGateBlock::CObjGateBlock()
{
}
//イニシャライズ
void CObjGateBlock::Init()
{
}
//アクション
void CObjGateBlock::Action()
{
}
//ドロー
void CObjGateBlock::Draw()
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
	dst.m_top = 448.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 512.0f;

	Draw::Draw(15, &src, &dst, c, 0.0f);
}

//----------------------------------------------

//開門 左

CObjGateOpenLeft::CObjGateOpenLeft()
{
}
//イニシャライズ
void CObjGateOpenLeft::Init()
{
}
//アクション
void CObjGateOpenLeft::Action()
{
}
//ドロー
void CObjGateOpenLeft::Draw()
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
	dst.m_top = 512.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 576.0f;

	Draw::Draw(8, &src, &dst, c, 0.0f);
}

//----------------------------------------------

//開門 右

CObjGateOpenRight::CObjGateOpenRight()
{
}

//イニシャライズ
void CObjGateOpenRight::Init()
{
}

//アクション
void CObjGateOpenRight::Action()
{
}

//ドロー
void CObjGateOpenRight::Draw()
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
	dst.m_top = 512.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 576.0f;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}
