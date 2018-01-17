#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define MAPSIZE_X 19

//オブジェクト:ブロック
class CObjgateopenleft :public CObj
{
public:
	CObjgateopenleft();
	~CObjgateopenleft() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー


private:
	int m_map[MAPSIZE_X][400]; //マップ情報仮
};