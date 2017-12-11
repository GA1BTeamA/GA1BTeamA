//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "Objhero.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImageW(L"imouto2.png", 0, TEX_SIZE_512);


	//タイムオブジェクト
	//CObjTime* objt = new CObjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 0);

	//主人公オブジェクト作成
	CObjhero* objh = new CObjhero();
	Objs::InsertObj(objh, OBJ_HERO, 10);

	//blockオブジェクト作成
	//CObjBlock* obj = new CObjBlock();
	//Objs::InsertObj(obj, OBJ_BLOCK,0);

}

//実行中メソッド
void CSceneMain::Scene()
{

}