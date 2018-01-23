#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define MAPSIZE_X 19

//オブジェクト:ブロック
class CObjBlock :public CObj
{
public:
	CObjBlock();
	~CObjBlock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetScroll() { return m_block_scroll; }
	int GetMap(int x, int y) { return m_map[y][x]; }

	//ブロックとの当たり判定
	void BlockHit
	(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool* left, bool* right,
		float* vx, float*vy, int* bt
	);

	

private:
	int m_map[MAPSIZE_X][400]; //マップ情報仮

	//描画カラー情報
	float c[4];

	float m_block_scroll;  //スクロール用

	////主人公位置
	//float hx;
	//float hy;

};