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

//extern CObjhero* objh;

//使用するネームスペース
using namespace GameL;

//ブロック＆主人公切り替え false=妹用 true=兄用
extern bool g_hero_change;

//----------------------------------------------

//門ブロック

CObjGate::CObjGate()
{
}
//イニシャライズ
void CObjGate::Init()
{
	gb_map_x = /*246*/0;
	gb_x = 0.0f;
}
//アクション
void CObjGate::Action()
{
	//兄主人公の位置を取得
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//妹主人公の位置を取得
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx2 = hero2->GetX();
	float hy2 = hero2->GetY();

	//主人公ライン
	if (g_hero_change == true)
	{
		//兄ライン
		if (hx < 80|| hx > MAPSIZE_X)
		{
			gb_x -= hero->GetVX();
		}
	}
	else
	{
		//妹ライン
		if (hx2 < 80|| hx2 > MAPSIZE_X)
		{
			gb_x -= hero2->GetVX();
		}
	}

	//当たり判定-------------------------------------------

	//要素番号を座標に変更
	float x = gb_map_x * 64;

	//主人公とブロックの当たり判定
	

}
//ドロー
void CObjGate::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画元表示位置

	int i;

	//門ブロック----------------------------------------------------
	for (i = 0; i < 8; i++)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;
		//表示位置の設定
		dst.m_top    = ((i * 2) * 32.0f);
		dst.m_left   =  (gb_map_x            * 32.0f)       + gb_x;
		dst.m_right  = ((gb_map_x            * 32.0f) + 64) + gb_x;
		dst.m_bottom = ((i * 2) * 32.0f) + 64;

		Draw::Draw(8, &src, &dst, c, 0.0f);
	}

	//兄閉門ブロック------------------------------------------------
	if (g_hero_change == true)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 64.0f;
		src.m_right = 128.0f;
		src.m_bottom = 64.0f;
		//表示位置の設定
		dst.m_top = ((i * 2) * 32.0f);
		dst.m_left = (gb_map_x * 32.0f) + gb_x;
		dst.m_right = ((gb_map_x * 32.0f) + 64) + gb_x;
		dst.m_bottom = ((i * 2) * 32.0f) + 64;

		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	//妹閉門ブロック------------------------------------------------
	else
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 128.0f;
		src.m_right = 192.0f;
		src.m_bottom = 64.0f;
		//表示位置の設定
		dst.m_top = ((i * 2) * 32.0f);
		dst.m_left = (gb_map_x * 32.0f) + gb_x;
		dst.m_right = ((gb_map_x * 32.0f) + 64) + gb_x;
		dst.m_bottom = ((i * 2) * 32.0f) + 64;

		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
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
	/*dst.m_top = 512.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 576.0f;*/

	Draw::Draw(9, &src, &dst, c, 0.0f);
}
