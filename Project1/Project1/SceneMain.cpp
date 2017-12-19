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
	Draw::LoadImageW(L"block0.png", 1, TEX_SIZE_512);
	//Draw::LoadImageW(L"Block1.png"  , 1, TEX_SIZE_32);
	//Draw::LoadImageW(L"Block2.png"  , 4, TEX_SIZE_32);
	Draw::LoadImageW(L"haikei.png"  , 0, TEX_SIZE_1024);
	Draw::LoadImageW(L"おおかみ.png", 2, TEX_SIZE_256);
	Draw::LoadImageW(L"imouto2.png" , 3, TEX_SIZE_512);

	//タイムオブジェクト
	//CObjTime* objt = new CObjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 0);

	//主人公オブジェクト作成
	CObjhero* objh = new CObjhero();
	Objs::InsertObj(objh, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 1);

	//背景作成
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

	//敵作成
	CObjEnemy1* obje = new CObjEnemy1();
	Objs::InsertObj(obje, OBJ_ENEMY1, 2);
}

//実行中メソッド
void CSceneMain::Scene()
{

}