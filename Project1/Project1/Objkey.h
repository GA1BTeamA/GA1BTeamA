#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define MAPSIZE_X 289
#define MAPSIZE_Y 19

//オブジェクト:ゴール
class CObjkey :public CObj
{
public:
	CObjkey();
	~CObjkey() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー


private:
	int m_map[MAPSIZE_Y][MAPSIZE_X]; //マップ情報仮
};