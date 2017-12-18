//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "Objhero.h"


//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock()
{

}

//イニシャライズ
void CObjBlock::Init()
{
	//マップデータ
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
		{ 0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },

	};

	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int)*(20 * 25));
}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//主人公の衝突確認状態確認用フラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//m_mapの全要素にアクセス
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j*32.0f;
				float y = i*32.0f;

				//主人公とブロックの当り判定
				if ((hx+45.0f>x)&&(hx+19.0f<x+32.0f)&&(hy+64.0f>y)&&(hy+9.0f<y+32.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = hx - x;
					float vy = hy - y;

					//長さを求める
					float len = sqrt(vx*vx + vy*vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);


					//角度で上下左右を判定
					if((r<45&&r>0)||r>315)
					{
						//右
					}
					if (r>45&&r<135)
					{
						//上
						hero->SetDown(true);//主人公から見て、下の部分が衝突している
						hero->SetY(y-64.0f);//ブロック位置ー主人公の幅
						hero->SetVY(0.0f);
					}
					if (r>135&&r<225)
					{
						//左
					}
					if (r>255&&r<315)
					{
						//下
						hero->SetUp(true);//主人公から見て、上の部分が衝突している
						hero->SetY(y + 64.0f);//ブロックの位置+主人公の幅
						if (hero->GetVY() < 0)
						{
							hero->SetVY(0.0f);
						}
					}

					//当たっている場合
					//hero->SetX(hx);
					//hero->SetY(0.0f);
					//hero->SetVY(0.0f);
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

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置
				dst.m_top    = i*32.0f;
				dst.m_left   = j*32.0f;
				dst.m_right  =  dst.m_left+32.0f;
				dst.m_bottom =  dst.m_top+32.0f;
				//描画
				//土ブロック
				if (m_map[i][j] == 1)
				{
					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//木ブロック
				else if (m_map[i][j] == 2)
				{
					Draw::Draw(4, &src, &dst, c, 0.0f);
				}
			}
		}
	}

}