#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：アイテム
class CObjitem2 : public CObj
{
public:
	CObjitem2() {};
	~CObjitem2() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

};