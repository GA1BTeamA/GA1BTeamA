#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

//#define MAPSIZE_X 19

//オブジェクト:看板(兄)
class CObjkanbanb :public CObj
{
public:
	CObjkanbanb();
	~CObjkanbanb() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	//int m_map[MAPSIZE_X][400]; //マップ情報仮
};