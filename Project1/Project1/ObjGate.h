#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//-----------------------------------------------------

//オブジェクト:門ブロック
class CObjGateBlock :public CObj
{
public:
	CObjGateBlock();
	~CObjGateBlock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:

	float m_block_scroll;  //スクロール用

};

//-----------------------------------------------------

//オブジェクト:開門 左
class CObjGateOpenLeft :public CObj
{
public:
	CObjGateOpenLeft();
	~CObjGateOpenLeft() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	
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