//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "Objhero.h"
#include "ObjGate.h"

extern CObjhero* objh;

//使用するネームスペース
using namespace GameL;

//ブロック＆主人公切り替え false=妹用 true=兄用
extern bool g_hero_change;

//主人公が門を開けるときのフラグ
extern bool brother_gateopen;
extern bool sister_gateopen;

//----------------------------------------------

//門ブロック

CObjGate::CObjGate()
{
	m_block_scroll = 0.0f;
}
//イニシャライズ
void CObjGate::Init()
{
	//マップデータ
	//外部データの読み込み(ステージ情報)
	unique_ptr<wchar_t>p;  //ステージ情報ポインター
	int size;  //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"mapdata.csv", &size);  //外部データ読み込み


	int count = 1;
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			m_map[i][j] = w;
			if (w >= 10)
				count += 3;
			else
				count += 2;
		}
	}
}
//アクション
void CObjGate::Action()
{
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//兄主人公の位置を取得
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//妹主人公の位置を取得
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx2 = hero2->GetX();
	float hy2 = hero2->GetY();

	if (g_hero_change == true)
	{
		m_block_scroll = block->GetgbScroll();
		//兄後方マップスクロール
		if (hx < 80)
		{
			//m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			m_block_scroll = block->GetgbScroll();
		}

		//兄前方マップスクロール
		if (hx > MAPSIZE_X)
		{
			//m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			m_block_scroll = block->GetgbScroll();
		}
	}
	else
	{
		m_block_scroll = block->GetgsScroll();
		//妹後方マップスクロール
		if (hx2 < 80)
		{
			//m_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			m_block_scroll = block->GetgsScroll();
		}

		//妹前方マップスクロール
		if (hx2 > MAPSIZE_X)
		{
			//m_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			m_block_scroll = block->GetgsScroll();
		}
	}
}

//ドロー
void CObjGate::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画元表示位置

	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置
				//64*64で表示
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f + m_block_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//描画

				//兄閉門ブロック
				if (g_hero_change == true)
				{
					if (m_map[i][j] == 21)
					{
						if (brother_gateopen == false)
						{
							//切り取り位置の設定
							src.m_top = 0.0f;
							src.m_left = 64.0f;
							src.m_right = 128.0f;
							src.m_bottom = 64.0f;

							Draw::Draw(8, &src, &dst, c, 0.0f);
						}
					}
				}
				//妹閉門ブロック
				if (g_hero_change == false)
				{
					if (m_map[i][j] == 21)
					{
						if (sister_gateopen == false)
						{
							//切り取り位置の設定
							src.m_top = 0.0f;
							src.m_left = 128.0f;
							src.m_right = 192.0f;
							src.m_bottom = 64.0f;
							
							Draw::Draw(8, &src, &dst, c, 0.0f);
						}
					}
				}
				
				//門ブロック
				if (m_map[i][j] == 22)
				{
					//切り取り位置の設定
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = 64.0f;
					src.m_bottom = 64.0f;

					Draw::Draw(8, &src, &dst, c, 0.0f);
				}

				//開門ブロック左
				if (m_map[i][j] == 21)
				{
					if (brother_gateopen == true && g_hero_change == true || sister_gateopen == true && g_hero_change == false)
					{
						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 192.0f;
						src.m_right = 256.0f;
						src.m_bottom = 64.0f;
						Draw::Draw(8, &src, &dst, c, 0.0f);
					}

					
				}
			}
		}
	}
	
		

}

//----------------------------------------------

//開門 右

CObjGateOpenRight::CObjGateOpenRight()
{
	m_block_scroll = 0.0f;
}

//イニシャライズ
void CObjGateOpenRight::Init()
{
	

	//マップデータ
	//外部データの読み込み(ステージ情報)
	unique_ptr<wchar_t>p;  //ステージ情報ポインター
	int size;  //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"mapdata.csv", &size);  //外部データ読み込み


	int count = 1;
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			m_map[i][j] = w;
			if (w >= 10)
				count += 3;
			else
				count += 2;
		}
	}
}

//アクション
void CObjGateOpenRight::Action()
{
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//兄主人公の位置を取得
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//妹主人公の位置を取得
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx2 = hero2->GetX();
	float hy2 = hero2->GetY();

	if (g_hero_change == true)
	{
		m_block_scroll = block->GetgbScroll();
		//兄後方マップスクロール
		if (hx < 80)
		{
			//m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			m_block_scroll = block->GetgbScroll();
		}

		//兄前方マップスクロール
		if (hx > MAPSIZE_X)
		{
			//m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			m_block_scroll = block->GetgbScroll();
		}
	}

	else
	{
		m_block_scroll = block->GetgsScroll();
		//妹後方マップスクロール
		if (hx2 < 80)
		{
			//m_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			m_block_scroll = block->GetgsScroll();
		}

		//妹前方マップスクロール
		if (hx2 > MAPSIZE_X)
		{
			//m_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			m_block_scroll = block->GetgsScroll();
		}
	}
}

//ドロー
void CObjGateOpenRight::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画元表示位置

	//表示位置の設定
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] > 0)
			{
				//64*64で表示
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f + m_block_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				if (m_map[i][j] == 21)
				{
					if (brother_gateopen == true && 
						g_hero_change == true || 
						sister_gateopen == true && 
						g_hero_change == false)
					{
						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = 64.0f;
						src.m_bottom = 64.0f;
						Draw::Draw(9, &src, &dst, c, 0.0f);
					}

					
				}
			}
		}
	}
}
