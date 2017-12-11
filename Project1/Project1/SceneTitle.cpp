//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GameStart");

	Draw::LoadImageW(L"タイトル.png", 1, TEX_SIZE_1024);

	//タイトルオブジェクト作成
	CObjTitle* objt = new CObjTitle(); //タイトルオブジェクト作成
	Objs::InsertObj(objt, OBJ_TITLE, 1); //主人公オブジェクト登録

	
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}