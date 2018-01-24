#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//#define MAPSIZE_X 19

//オブジェクト:ブロック
class CObjgateopenright :public CObj
{
public:
	CObjgateopenright();
	~CObjgateopenright() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー


private:
	//int m_map[MAPSIZE_X][400]; //マップ情報仮
};