#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define MAPSIZE_X 300
#define MAPSIZE_Y 19

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

	float GetScroll() { return m_block_scroll; }
	int GetMap(int x, int y) { return m_map[y][x]; }

private:
	int m_map[MAPSIZE_Y][MAPSIZE_X]; //マップ情報仮

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

	float GetScroll() { return m_block_scroll; }
	int GetMap(int x, int y) { return m_map[y][x]; }

private:
	int m_map[MAPSIZE_Y][MAPSIZE_X]; //マップ情報仮

	float m_block_scroll;  //スクロール用
	
};