//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "Objhero.h"


//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock()
{
	m_block_scroll = 0.0f;

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
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < 400; j++)
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
	/*
	int block_data[20][25] =
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0 },
		{ 0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },

	};
	*/
}

//アクション
void CObjBlock::Action()
{

	//主人公の位置を取得
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	/*/後方スクロールライン
	if (hx < 80)
	{
		hero->SetX(80);						//主人公はラインを超えないようにする
		m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
	}

	//前方スクロールライン
	if (hx > 400)
	{
		hero->SetX(400);					//主人公はラインを超えないようにする
		m_block_scroll -= hero->GetVX();	//主人公が本来動くべき分の値をm_block_scrollに加える
	}*/

	//主人公の衝突確認状態確認用フラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//m_mapの全要素にアクセス
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j*32.0f;
				float y = i*32.0f;

				

				/*/それぞれの方向に要素があるかどうかの検索
				//blockの中央上の位置を要素番号化
				int x = ((int)px + 16) / 32.0f;
				int y = ((int)py) / 32.0f;
				u3 = GetMap(x, y - 1);  //上方向

				//blockの中央左の位置を要素番号化
				x = ((int)px) / 32.0f;
				y = ((int)py + 16) / 32.0f;
				l1 = GetMap(x - 1, y);  //左方向

				//blockの中央右の位置を要素番号化
				x = ((int)px + 64) / 32.0f;
				y = ((int)py + 16) / 32.0f;
				r2 = GetMap(x + 1, y);  //右方向

				//blockの中央下の位置を要素番号化
				x = ((int)px + 16) / 32.0f;
				y = ((int)py + 64) / 32.0f;
				d4 = GetMap(x, y + 1);  //下方向*/
				
				//主人公とブロックの当り判定
				if ((hx + (-m_block_scroll)+64.0f > x) && (hx+(-m_block_scroll) < x + 32.0f) && (hy + 64.0f > y) && (hy < y + 32.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx+(-m_block_scroll)) - x;
					float vy = hy+32 - y;

					//長さを求める
					float len = sqrt(vx*vx + vy*vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 40)
					{

						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);//主人公が左部分に衝突している
							hero->SetX(x + 64.0f+(m_block_scroll));//ブロックの位置ー主人公の幅
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY(y - 64.0f);//ブロック位置ー主人公の幅
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公が右の部分に衝突している
							hero->SetX(x - 64.0f+(m_block_scroll));//ブロックの位置ー主人公の幅
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公の上の部分が衝突している
							hero->SetY(y + 64.0f);//ブロックの位置+主人公の幅
							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}
					}
				}
			}
		}
	}
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置
				dst.m_top    = i*32.0f;
				dst.m_left = j*32.0f + m_block_scroll;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom =  dst.m_top+32.0f;

				//描画
				//土ブロック
				if (m_map[i][j] == 1||m_map[i][j]==13)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = 32.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//木ブロック
				else if (m_map[i][j] == 2)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 64.0f;
					src.m_right = 96.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//妹ブロック
				else if (m_map[i][j] == 4)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 64.0f;
					src.m_right = 96.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//兄ブロック
				else if (m_map[i][j] == 5)
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

				//茨ブロック
				else if (m_map[i][j] == 8)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 32.0f;
					src.m_right = 64.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//茨ブロック
				else if (m_map[i][j] == 15)
				{
					//切り取り位置
					src.m_top = 0.0f;
					src.m_left = 128.0f;
					src.m_right = 162.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
			}
		}
	}

}
