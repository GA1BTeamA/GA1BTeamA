#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：アイテム
class CObjitem : public CObj
{
public:
	CObjitem() {};
	~CObjitem() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

};