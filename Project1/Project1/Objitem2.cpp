//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Objitem2.h"

//使用するネームスペース
using namespace GameL;

//ブロック＆主人公切り替え false=妹用 true=兄用
extern  bool g_hero_change;

//兄のアイテムポーチ[0]=鎧[1]=鍵
extern int Bitem_porch[2];

//妹のアイテムポーチ[0]=靴[1]=鍵
extern int Sitem_porch[2];

//イニシャライズ
void CObjitem2::Init()
{

}

//アクション
void CObjitem2::Action()
{

}

//ドロー
void CObjitem2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 66.0f;
	dst.m_right = 130.0f;
	dst.m_bottom = 64.0f;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
}