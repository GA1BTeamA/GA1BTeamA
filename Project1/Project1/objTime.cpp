//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjTime.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTime::Init()
{
	m_time = 0;
}

//アクション
void CObjTime::Action()
{

}

//ドロー
void CObjTime::Draw()
{
	//m_timeから秒分を求める
	int minute;//分
	int second;//秒

	second = (m_time / 60) % 60;//秒
	minute = (m_time / 60) / 60;//分

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];

	//分:秒の値を文字列化
	if (second < 10)
		swprintf_s(str, L"%d分0%d秒", minute, second);//秒の1桁目に0を用意
	else
		swprintf_s(str, L"%d分%d秒", minute, second);

	Font::StrDraw(str, 10, 10, 20, c);
}