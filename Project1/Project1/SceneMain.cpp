//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "Objhero.h"

CObjBlock* g_objb;

CObjhero* objh;

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
	//音楽読み込み
	Audio::LoadAudio(0, L"BGMGameMain.wav", BACK_MUSIC);

	//ボリューム調整
	float v = Audio::VolumeMaster(0.1);

	//音楽スタート
	Audio::Start(0);

	//グラフィック読み込み
	Draw::LoadImageW(L"block0.png"  , 1, TEX_SIZE_512);
	//Draw::LoadImageW(L"Block1.png"  , 1, TEX_SIZE_32);
	//Draw::LoadImageW(L"Block2.png"  , 4, TEX_SIZE_32);
	Draw::LoadImageW(L"haikei.png"  , 0, TEX_SIZE_1024);
	Draw::LoadImageW(L"ookami.png", 2, TEX_SIZE_256);
	Draw::LoadImageW(L"kanban sis.png", 5, TEX_SIZE_32);
	Draw::LoadImageW(L"kanban bro.png", 6, TEX_SIZE_32);
	Draw::LoadImageW(L"kanban sis.png", 4, TEX_SIZE_32);
	Draw::LoadImageW(L"imouto1.png" , 10, TEX_SIZE_512);
	Draw::LoadImageW(L"ani1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"waku.png", 4, TEX_SIZE_64);
	Draw::LoadImageW(L"Gate.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"GateOpenRight.png", 9, TEX_SIZE_64);
	Draw::LoadImageW(L"switchsis.png", 12, TEX_SIZE_32);
	Draw::LoadImageW(L"switchbro.png", 13, TEX_SIZE_32);

	//タイムオブジェクト
	//CObjTime* objt = new CObjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 0);

	//主人公兄オブジェクト作成
	objh = new CObjhero();
	//主人公オブジェクト作成
	objh = new CObjhero();
	Objs::InsertObj(objh, OBJ_HERO, 10);

	//主人公妹オブジェクト作成
	CObjhero2* objh2 = new CObjhero2();
	Objs::InsertObj(objh2, OBJ_HERO2, 10);

	//blockオブジェクト作成
	g_objb = new CObjBlock();
	Objs::InsertObj(g_objb, OBJ_BLOCK, 1);

	//背景作成
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

	////敵作成
	//CObjEnemy1* obje = new CObjEnemy1(100,0);
	//Objs::InsertObj(obje, OBJ_ENEMY1, 2);

	//看板オブジェクト(妹)作成
	CObjkanbans* objks = new CObjkanbans();
	Objs::InsertObj(objks, OBJ_KANBANS, 5);

	//看板オブジェクト(兄)作成
	CObjkanbanb* objkb = new CObjkanbanb();
	Objs::InsertObj(objkb, OBJ_KANBANB, 6);

	//アイテム作成
	CObjitem* obji = new CObjitem();
	Objs::InsertObj(obji, OBJ_ITEM, 4);

	//アイテム作成
	CObjitem2* obji2 = new CObjitem2();
	Objs::InsertObj(obji2, OBJ_ITEM2, 4);

	//門オブジェクト作成
	CObjGate* objgate = new CObjGate();
	Objs::InsertObj(objgate, OBJ_GATE, 1);

	//開門オブジェクト(右)作成
	CObjGateOpenRight* objgor = new CObjGateOpenRight();
	Objs::InsertObj(objgor, OBJ_GATEOPENRIGHT, 11);

	//スイッチ(妹)作成
	CObjswitchsis* objss = new CObjswitchsis();
	Objs::InsertObj(objss, OBJ_SWITCHS, 12);

	//スイッチ(兄)作成
	CObjswitchbro* objsb = new CObjswitchbro();
	Objs::InsertObj(objsb, OBJ_SWITCHB, 13);

}

//実行中メソッド
void CSceneMain::Scene()
{

}