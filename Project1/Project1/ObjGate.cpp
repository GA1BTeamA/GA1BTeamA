//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "ObjGate.h"
#include "Objhero.h"

//使用するネームスペース
using namespace GameL;

//----------------------------------------------

//門ブロック

//ブロック＆主人公切り替え false=妹用 true=兄用
extern bool g_hero_change;

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
	//兄主人公の位置を取得
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//妹主人公の位置を取得
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx2 = hero2->GetX();
	float hy2 = hero2->GetY();

	/*if (g_hero_change == true)
	{
		//兄後方スクロールライン
		if (hx < 80)
		{
			hero->SetX(80);						//主人公はラインを超えないようにする
			m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
		}

		//兄前方スクロールライン
		if (hx > 400)
		{
			hero->SetX(400);					//主人公はラインを超えないようにする
			m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
		}
	}

	else
	{
		//妹後方スクロールライン
		if (hx2 < 80)
		{
			hero2->SetX(80);						//主人公はラインを超えないようにする
			m_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
		}

		//妹前方スクロールライン
		if (hx2 > 400)
		{
			hero2->SetX(400);					//主人公はラインを超えないようにする
			m_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
		}
	}*/
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
