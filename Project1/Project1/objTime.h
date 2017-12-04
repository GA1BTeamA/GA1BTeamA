#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:タイム
class CObjTime :public CObj
{
public:
	CObjTime() {};
	~CObjTime() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	int m_time;//時間
	int m_flag_time;
};