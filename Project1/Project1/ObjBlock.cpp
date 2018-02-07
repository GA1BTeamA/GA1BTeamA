//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "Objhero.h"

extern CObjhero* objh;
extern CObjhero2* objh2;

//使用するネームスペース
using namespace GameL;

//ブロック＆主人公切り替え false=妹用 true=兄用
bool g_hero_change;

//主人公が鍵を所持しているかのフラグ
bool brother_key;
bool sister_key;
bool armor_block;
bool shose_block;
//主人公が門を開けるときのフラグ
bool brother_gateopen;
bool sister_gateopen;
bool brother_gateopen2;
bool sister_gateopen2;
//スイッチを踏んでいるときのフラグ
bool switch_flag;
bool switch_flag2;

//グローバル位置
extern float g_px;

//主人公がゴール前にいるかどうか
bool brother_goal;
bool sister_goal;

//兄妹の画面切り替えフラグ
bool screen_change_flag;

CObjBlock::CObjBlock()
{
	m_block_scroll = 0.0f;

	gb_block_scroll = 0.0f;

	gs_block_scroll = 0.0f;

	scroll_change_b = 0.0f;

	scroll_change_s = 0.0f;

	scroll_change_keep = 0.0f;

	screen_change_flag = false;

	button_flag = true;

	//マップデータをコピー
	//memcpy(m_map, map, sizeof(int)*(18 * 400));
}

//イニシャライズ
void CObjBlock::Init()
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
			if(w>=10)
				count += 3;
			else 
				count += 2;
		}
	}

	armor_block = false;
	shose_block = false;
	brother_key = false;
	sister_key = false;
	brother_gateopen = false;
	sister_gateopen = false;
	switch_flag = false;
}

//アクション
void CObjBlock::Action()
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
	
	//主人公画面切り替え
	if (screen_change_flag == true)
	{

		if (g_hero_change == false)
		{
			scroll_change_keep = m_block_scroll;
			m_block_scroll = scroll_change_s;
			scroll_change_b = scroll_change_keep;
			g_hero_change = true;
		}
		else
		{
			scroll_change_keep = m_block_scroll;
			m_block_scroll = scroll_change_b;
			scroll_change_s = scroll_change_keep;
			g_hero_change = false;
		}

		screen_change_flag = false;

	}

	if (g_hero_change == true)
	{
		//兄後方スクロールライン
		if (hx < 250)
		{

			hero->SetX(250);						//主人公はラインを超えないようにする
			m_block_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_block_scrollに加える
			gb_block_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_block_scrollに加える

		}

		//兄前方スクロールライン
		if (hx > 380)
		{
			hero->SetX(380);					//主人公はラインを超えないようにする
			m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			gb_block_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_block_scrollに加える
		}
	}

	else
	{
		//妹後方スクロールライン
		if (hx2 < 250)
		{
			hero2->SetX(250);						//主人公はラインを超えないようにする
			m_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			gs_block_scroll -= hero2->GetVX();//主人公が本来動くべき分の値をm_block_scrollに加える
		}

		//妹前方スクロールライン
		if (hx2 > 380)
		{
			hero2->SetX(380);					//主人公はラインを超えないようにする
			m_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
			gs_block_scroll -= hero2->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
		}
	}


	

	//敵出現ライン
	//主人公の位置＋500を敵出現ラインにする
	float line = hx + (-m_block_scroll) + 1000;

	//敵出現ラインを要素番号化
	int ex = ((int)line) / 32;

	//敵出現ラインの列を検索
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		//列の中から17を探す
		if (m_map[i][ex] == 17)
		{
			//17があれば、敵を出現
			CObjEnemy1* obje = new CObjEnemy1(ex*32.0f, i*32.0f);
			Objs::InsertObj(obje, OBJ_ENEMY1, 2);

			//敵出現場所の値を0にする
			m_map[i][ex] = 0;
		}
	}

	//キャラ切り替えに際した門ギミックの画像と当たり判定切り替え
	if (g_hero_change == true)
	{
		if (brother_gateopen == false)
		{
			for (int i = 0; i < MAPSIZE_Y; i++)
			{
				for (int j = 0; j < MAPSIZE_X; j++)
				{
					if (m_map[i][j] == 99)
					{
						m_map[i][j] = 21;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < MAPSIZE_Y; i++)
			{
				for (int j = 0; j < MAPSIZE_X; j++)
				{
					if (m_map[i][j] == 21)
					{
						m_map[i][j] = 99;
					}
				}
			}
		}
	}
	else
	{
		if (sister_gateopen == false)
		{
			for (int i = 0; i < MAPSIZE_Y; i++)
			{
				for (int j = 0; j < MAPSIZE_X; j++)
				{
					if (m_map[i][j] == 99)
					{
						m_map[i][j] = 21;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < MAPSIZE_Y; i++)
			{
				for (int j = 0; j < MAPSIZE_X; j++)
				{
					if (m_map[i][j] == 21)
					{
						m_map[i][j] = 99;
					}
				}
			}
		}
	}

	//主人公がスイッチを踏んでいる間、踏スイッチとブロックを用意する
	if (switch_flag == true||switch_flag2==true)
	{
		for (int i = 0; i < MAPSIZE_Y; i++)
		{
			for (int j = 0; j < MAPSIZE_X; j++)
			{
				if (m_map[i][j] == 27)
				{
					m_map[i][j] = 29;
					m_map[i + 1][j] = 30;
				}
				if (m_map[i][j] == 28)
				{
					m_map[i][j] = 31;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < MAPSIZE_Y; i++)
		{
			for (int j = 0; j < MAPSIZE_X; j++)
			{
				if (m_map[i][j] == 29)
				{
					m_map[i][j] = 27;
					m_map[i + 1][j] = 1;
				}
				if (m_map[i][j] == 31)
				{
					m_map[i][j] = 28;
				}
			}
		}
	}
}

//ドロー
void CObjBlock::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f};

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] > 0)
			{
				
				//表示位置
				//ゴールは64*64で表示
				if (m_map[i][j] == 11)
				{
					dst.m_top = i*32.0f;
					dst.m_left = j*32.0f + m_block_scroll;
					dst.m_right = dst.m_left + 64.0f;
					dst.m_bottom = dst.m_top + 64.0f;
				}
				//それ以外は32*32で表示
				else
				{
					dst.m_top = i*32.0f;
					dst.m_left = j*32.0f + m_block_scroll;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;
				}

			//描画
				
					//妹ブロック(木)
			if (m_map[i][j] == 4)
			{
						//切り取り位置
						src.m_top = 0.0f;
						src.m_left = 64.0f;
						src.m_right = 96.0f;
						src.m_bottom = 32.0f;

						if (g_hero_change == true)
							c[3] = 0.5f;

						Draw::Draw(1, &src, &dst, c, 0.0f);

						c[3] = 1.0f;

						
			}

			//妹ブロック(草)
			else if (m_map[i][j] == 13)
			{
				//切り取り位置
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 32.0f;
				src.m_bottom = 32.0f;

				if (g_hero_change == true)
					c[3] = 0.5f;

				Draw::Draw(1, &src, &dst, c, 0.0f);

				c[3] = 1.0f;

			}
					//妹ブロック(土)
			else if (m_map[i][j] == 16)
			{
				//切り取り位置
				src.m_top = 0.0f;
				src.m_left = 32.0f;
				src.m_right = 64.0f;
				src.m_bottom = 32.0f;

				if (g_hero_change == true)
					c[3] = 0.5f;

				Draw::Draw(1, &src, &dst, c, 0.0f);

				c[3] = 1.0f;
			}
				
				
				//兄ブロック(木)
			else if (m_map[i][j] == 5)
			{
				//切り取り位置
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = 96.0f;
				src.m_bottom = 32.0f;

				if (g_hero_change == false)
					c[3] = 0.5f;

				Draw::Draw(1, &src, &dst, c, 0.0f);

				c[3] = 1.0f;
			}

				//草ブロック
				if (m_map[i][j] == 1|| m_map[i][j] == 26||m_map[i][j]==30)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = 32.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//木ブロック
				else if (m_map[i][j] == 2 || m_map[i][j] == 31)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 64.0f;
					src.m_right = 96.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//茨ブロック
				else if (m_map[i][j] == 3)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 96.0f;
					src.m_right = 128.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//土ブロック
				else if (m_map[i][j] == 8)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 32.0f;
					src.m_right = 64.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//茨ブロック(上部分)
				else if (m_map[i][j] == 15)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 128.0f;
					src.m_right = 162.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//針ブロック
				else if (m_map[i][j] == 6)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 160.0f;
					src.m_right = 192.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//針ブロック（逆さま）
				else if (m_map[i][j] == 12)
				{
					//切り取り位置
					src.m_top = 32.0f;
					src.m_left = 160.0f;
					src.m_right = 192.0f;
					src.m_bottom = 0.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//ゴール
				else if (m_map[i][j] == 11)
				{
					//切り取り位置の設定
					src.m_top = 32.0f;
					src.m_left = 0.0f;
					src.m_right = 64.0f;
					src.m_bottom = 96.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//カギ(兄)
				else if (m_map[i][j] == 18)
				{
					//切り取り位置の設定
					src.m_top = 32.0f;
					src.m_left = 128.0f;
					src.m_right = 160.0f;
					src.m_bottom = 63.0f;

					if (g_hero_change == false)
						c[3] = 0.5f;

					Draw::Draw(1, &src, &dst, c, 0.0f);

					c[3] = 1.0f;
				}
				//カギ(妹)
				else if (m_map[i][j] == 23)
				{
					//切り取り位置の設定
					src.m_top = 32.0f;
					src.m_left = 161.0f;
					src.m_right = 192.0f;
					src.m_bottom = 63.0f;

					if (g_hero_change == true)
						c[3] = 0.5f;

					Draw::Draw(1, &src, &dst, c, 0.0f);

					c[3] = 1.0f;
				}
				//くつ
				else if (m_map[i][j] == 19)
				{
					//切り取り位置の設定
					src.m_top = 32.0f;
					src.m_left = 64.0f;
					src.m_right = 95.0f;
					src.m_bottom = 63.0f;

					if (g_hero_change == true)
						c[3] = 0.5f;

					Draw::Draw(1, &src, &dst, c, 0.0f);

					c[3] = 1.0f;
				}
				//よろい
				else if (m_map[i][j] == 20)
				{
					//切り取り位置の設定
					src.m_top = 32.0f;
					src.m_left = 96.0f;
					src.m_right = 127.0f;
					src.m_bottom = 63.0f;

					if (g_hero_change == false)
						c[3] = 0.5f;

					Draw::Draw(1, &src, &dst, c, 0.0f);

					c[3] = 1.0f;
				}
				//スイッチ踏
				else if (m_map[i][j] == 29)
				{
					//切り取り位置の設定
					src.m_top = 64.0f;
					src.m_left = 128.0f;
					src.m_right = 160.0f;
					src.m_bottom = 96.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//スイッチ未踏(兄)
				else if (g_hero_change == true && m_map[i][j] == 27)
				{
					//切り取り位置の設定
					src.m_top = 64.0f;
					src.m_left = 64.0f;
					src.m_right = 96.0f;
					src.m_bottom = 96.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//スイッチ未踏(妹)
				else if (g_hero_change == false && m_map[i][j] == 27)
				{
					//切り取り位置の設定
					src.m_top = 64.0f;
					src.m_left = 96.0f;
					src.m_right = 128.0f;
					src.m_bottom = 96.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
			}
		}
	}

	//鍵取得時、アイテム覧に表示

	if (g_hero_change == true && brother_key == true)
	{
		dst.m_top = 16.0f;
		dst.m_left = 16.0f;
		dst.m_right = 48.0f;
		dst.m_bottom = 48.0f;

		//切り取り位置の設定
		src.m_top = 32.0f;
		src.m_left = 128.0f;
		src.m_right = 160.0f;
		src.m_bottom = 64.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	
	else if (g_hero_change == false && sister_key == true)
	{
		dst.m_top = 16.0f;
		dst.m_left = 16.0f;
		dst.m_right = 48.0f;
		dst.m_bottom = 48.0f;

		//切り取り位置の設定
		src.m_top = 32.0f;
		src.m_left = 160.0f;
		src.m_right = 192.0f;
		src.m_bottom = 64.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

	//よろい取得時、アイテム覧に表示

	if (g_hero_change == true && armor_block == true)
	{
		dst.m_top = 16.0f;
		dst.m_left = 82.0f;
		dst.m_right = 114.0f;
		dst.m_bottom = 48.0f;

		//切り取り位置の設定
		src.m_top = 32.0f;
		src.m_left = 96.0f;
		src.m_right = 127.0f;
		src.m_bottom = 63.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}


	//くつ取得時、アイテム覧に表示

	if (g_hero_change == false && shose_block == true)
	{
		dst.m_top = 16.0f;
		dst.m_left = 82.0f;
		dst.m_right = 114.0f;
		dst.m_bottom = 48.0f;

		//切り取り位置の設定
		src.m_top = 32.0f;
		src.m_left = 64.0f;
		src.m_right = 95.0f;
		src.m_bottom = 63.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

}


//主人公用-----------------------------------------------------------------------------------------------------------------------------------------
//BlockHit関数
//引数1  float* x          ;判定を行うobjectのx位置
//引数2  float* y          ;判定を行うobjectのy位置
//引数3  bool   scroll_on  ;判定を行うobjectはスクロールの影響与えるかどうか（true=与える false=与えない）
//引数4  bool*  up         ;上下左右判定の上部分に当たっているかどうかを返す
//引数5  bool*  down       ;上下左右判定の下部分に当たっているかどうかを返す
//引数6  bool*  left       ;上下左右判定の左部分に当たっているかどうかを返す
//引数7  bool*  right      ;上下左右判定の右部分に当たっているかどうかを返す
//引数8  float* vx         ;左右判定時の反発による移動方向・力の値変えて返す
//引数9  float* vy         ;上下判定時による自由落下運動の移動方向・力の値変えて返す
//引数10 int*   bt         ;下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック64＊64限定で、当たり判定と上下左右半手を行う
//その結果は引数4～10に返す
void CObjBlock::BlockHit
(
	float* x, float* y, bool scroll_on,
	bool*up, bool* down, bool* left, bool* right,
	float *vx, float *vy, int* bt
)
{
	//主人公の衝突確認状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] >   0 && 
				m_map[i][j] != 15 && 
				m_map[i][j] != 17 && 
				m_map[i][j] != 99 && 
				m_map[i][j] != 28 &&
				m_map[i][j] != 29 )
			{
				//要素番号を座標に変更
				float bx = j*32.0f;
				float by = i*32.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_block_scroll : 0;

				//主人公とブロックの当り判定
				if ((*x + 41.0f + (-m_block_scroll) > bx) && (*x + 19.0 + (-m_block_scroll) < bx + 32.0f) && (*y + 64.0f > by) && (*y < by + 32.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx[2];
					float rvy[2];

					rvx[0] = (*x + (-m_block_scroll)) + 16 - bx;
					rvy[0] = *y + 32 - by;

					rvx[1] = (*x + (-m_block_scroll) + 16) - bx;
					rvy[1] = *y  - by;
					//float vx = (hx+32+(-m_block_scroll)) - x;
					//float vy = hy + 32 - y;

					for (int k = 0; k < 2; k++)
					{
						//長さを求める
						float len = sqrt(rvx[k] * rvx[k] + rvy[k] * rvy[k]);

						//角度を求める
						float r = atan2(rvy[k], rvx[k]);
						r = r*180.0f / 3.14f;

						if (r <= 0.0f)
							r = abs(r);
						else
							r = 360.0f - abs(r);

						//lenがある一定の長さより短い場合判定に入る
						if (len < 38)
						{

							//主人公専用ブロック判定
							//兄 5=木ブロック 18=兄鍵 20=鎧
							if (g_hero_change == false && m_map[i][j] == 5 || g_hero_change == false && m_map[i][j] == 18 || g_hero_change == false && m_map[i][j] == 20)
								;
							//妹 4=木ブロック 13=草ブロック 16=土ブロック 23=妹鍵 19=靴
							else if (g_hero_change == true && m_map[i][j] == 4 || g_hero_change == true && m_map[i][j] == 13 || g_hero_change == true && m_map[i][j] == 16 ||
								g_hero_change == true && m_map[i][j] == 23 || g_hero_change == true && m_map[i][j] == 19)
								;
							//その他
							else
							{
								//角度で上下左右を判定
								if ((r <= 45 && r >= 0) || r >= 315)
								{
									//右
									*right = true;//主人公が左部分に衝突している
									*x = (bx + 13.0f + (m_block_scroll));//ブロックの位置ー主人公の幅
									*vx = -(*vx)*0.1f;//-VX*反発係数
									*bt = m_map[i][j];//ブロックの要素(type)を主人公に渡す

								}
								if (r >= 45 && r <= 135)
								{
									if (k == 0)
									{
										//上
										*down = true;//主人公の下の部分が衝突している
										*y = by - 64.0f;//ブロック位置ー主人公の幅
										*bt = m_map[i][j];//ブロックの要素(type)を主人公に渡す
										*vy = 0.0f;

										if (*bt==26)
										{
											if (g_hero_change == true)
												brother_goal = true;
											else
												sister_goal = true;
										}
										else
										{
											if(g_hero_change == true)
												brother_goal = false;
											else
												sister_goal = false;
										}
									}
								}
								if (r >= 135 && r <= 225)
								{
									//左
									*left = true;//主人公が右の部分に衝突している
									*x = bx - 41.0f + (m_block_scroll);//ブロックの位置ー主人公の幅
									*vx = -(*vx)*0.1f;//-VX*反発係数

									*bt = m_map[i][j];//ブロックの要素(type)を主人公に渡す


									if (m_map[i][j] == 11 && g_hero_change == false)
									{
										objh2->SetGoalBlock(11);
									}
									else if (m_map[i][j] == 11 && g_hero_change == true)
									{
										objh->SetGoalBlock(11);
									}
									
								}
								if (r >= 225 && r <= 315)
								{
									//下
									if (k == 1)
									{
										*up = true;//主人公の上の部分が衝突している
										*bt = m_map[i][j];//ブロックの要素(type)を主人公に渡す
										//*y=by + 64.0f;//ブロックの位置+主人公の幅

										if (*vy < 0)
										{
											*vy = 0.0f;
										}
									}

								}

								if (g_hero_change == true)
								{
									//兄が鍵に触れたらフラグを立てる
									if (m_map[i][j] == 18)
									{
										brother_key = true;
										m_map[i][j] = 0;
									}
									//brother_keyがtrueで触れたとき「門」を開く
									if (m_map[i][j] == 21)
									{
										if (brother_key == true)
										{
											brother_gateopen = true;
											brother_key = false;

											m_map[i][j] = 99;
										}
									}
									//brother_keyがtrueで触れたとき「門2」を開く
									if (m_map[i][j] == 32)
									{
										if (brother_key == true)
										{
											brother_gateopen2 = true;
											brother_key = false;
											if (brother_gateopen2 == true && sister_gateopen2 == true)
											{
												m_map[i][j] = 99;
											}
										}
									}
								}
								else
								{
									//妹が鍵に触れたらフラグを立てる
									if (m_map[i][j] == 23)
									{
										sister_key = true;
										m_map[i][j] = 0;
									}
									//sister_keyがtrueで触れたとき門を開く
									if (m_map[i][j] == 21)
									{
										if (sister_key == true)
										{
											sister_gateopen = true;
											sister_key = false;

											m_map[i][j] = 99;
										}
									}
									//sister_keyがtrueで触れたとき門2を開く
									if (m_map[i][j] == 32)
									{
										if (sister_key == true)
										{
											sister_gateopen2 = true;
											sister_key = false;
											if (brother_gateopen2 == true && sister_gateopen2 == true)
											{
												m_map[i][j] = 99;
											}
										}
									}
								}

								if (g_hero_change == true)
								{
									//兄がよろいに触れたらフラグを立てる
									if (m_map[i][j] == 20)
									{
										armor_block = true;
										m_map[i][j] = 0;
									}
								}
								else
								{
									//妹がくつに触れたらフラグを立てる
									if (m_map[i][j] == 19)
									{
										shose_block = true;
										m_map[i][j] = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

//オオカミ用-----------------------------------------------------------------------------------------------------------------------------------------
//BlockHit関数
//引数1  float* x          ;判定を行うobjectのx位置
//引数2  float* y          ;判定を行うobjectのy位置
//引数3  bool   scroll_on  ;判定を行うobjectはスクロールの影響与えるかどうか（true=与える false=与えない）
//引数4  bool*  up         ;上下左右判定の上部分に当たっているかどうかを返す
//引数5  bool*  down       ;上下左右判定の下部分に当たっているかどうかを返す
//引数6  bool*  left       ;上下左右判定の左部分に当たっているかどうかを返す
//引数7  bool*  right      ;上下左右判定の右部分に当たっているかどうかを返す
//引数8  float* vx         ;左右判定時の反発による移動方向・力の値変えて返す
//引数9  float* vy         ;上下判定時による自由落下運動の移動方向・力の値変えて返す
//引数10 int*   bt         ;下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック64＊64限定で、当たり判定と上下左右半手を行う
//その結果は引数4～10に返す
void CObjBlock::BlockEnemyHit
(
	float* x, float* y, bool scroll_on,
	bool*up, bool* down, bool* left, bool* right,
	float *vx, float *vy, int* bt
)
{
	//主人公の衝突確認状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] > 0 &&
				m_map[i][j] != 15 &&
				m_map[i][j] != 17 &&
				m_map[i][j] != 99 &&
				m_map[i][j] != 28 &&
				m_map[i][j] != 29)
			{
				//要素番号を座標に変更
				float bx = j*32.0f;
				float by = i*32.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_block_scroll : 0;

				//主人公とブロックの当り判定
				if ((*x+58.0+ (-m_block_scroll) > bx) && (*x+4.0f + (-m_block_scroll) < bx + 32.0f) && (*y + 64.0f > by) && (*y < by + 32.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx[2];
					float rvy[2];

					rvx[0] = (*x + (-m_block_scroll))+16 - bx;
					rvy[0] = *y + 32 - by;

					rvx[1] = (*x + (-m_block_scroll)+16) - bx;
					rvy[1] = *y - by;
					//float vx = (hx+32+(-m_block_scroll)) - x;
					//float vy = hy + 32 - y;

					for (int k = 0; k < 2; k++)
					{
						//長さを求める
						float len = sqrt(rvx[k] * rvx[k] + rvy[k] * rvy[k]);

						//角度を求める
						float r = atan2(rvy[k], rvx[k]);
						r = r*180.0f / 3.14f;

						if (r <= 0.0f)
							r = abs(r);
						else
							r = 360.0f - abs(r);

						//lenがある一定の長さより短い場合判定に入る
						if (len < 38)
						{


							//角度で上下左右を判定
							if ((r <= 45 && r >= 0) || r >= 315)
							{
								//右
								*right = true;//主人公が左部分に衝突している
								*x = (bx + 58.0f + (m_block_scroll));//ブロックの位置ー主人公の幅
								*vx = -(*vx)*0.1f;//-VX*反発係数
								*bt = m_map[i][j];//ブロックの要素(type)を主人公に渡す

							}
							if (r >= 45 && r <= 135)
							{
								if (k == 0)
								{
									//上
									*down = true;//主人公の下の部分が衝突している
									*y = by - 64.0f;//ブロック位置ー主人公の幅
									*bt = m_map[i][j];//ブロックの要素(type)を主人公に渡す
									*vy = 0.0f;
								}
							}
							if (r >= 135 && r <= 225)
							{
								//左
								*left = true;//主人公が右の部分に衝突している
								*x = bx - 64.0f + (m_block_scroll);//ブロックの位置ー主人公の幅
								*vx = -(*vx)*0.1f;//-VX*反発係数
								*bt = m_map[i][j];//ブロックの要素(type)を主人公に渡す

							}
							if (r >= 225 && r <= 315)
							{
								//下
								if (k == 1)
								{
									*up = true;//主人公の上の部分が衝突している
									*bt = m_map[i][j];//ブロックの要素(type)を主人公に渡す
									//*y=by + 64.0f;//ブロックの位置+主人公の幅

									if (*vy < 0)
									{
										*vy = 0.0f;
									}
								}

							}
						}
					}
				}
			}
		}
	}
}