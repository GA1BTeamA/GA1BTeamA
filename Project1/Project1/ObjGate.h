#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//-----------------------------------------------------

//オブジェクト:門ブロック
class CObjGate :public CObj
{
public:
	CObjGate();
	~CObjGate() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	//ブロックとの当たり判定
	/*void BlockHit
	(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool* left, bool* right,
		float* vx, float*vy, int* bt
	);*/

private:
	//int m_map[MAPSIZE_X][400]; //マップ情報仮

	int gb_map_x; //門ブロックのマップ情報
	float gb_x;   //門ブロックの位置情報

	float m_block_scroll;  //スクロール用

};

//-----------------------------------------------------

//オブジェクト:開門 右
class CObjGateOpenRight :public CObj
{
public:
	CObjGateOpenRight();
	~CObjGateOpenRight() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	
};