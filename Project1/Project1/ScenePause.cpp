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
CScenePause::CScenePause()
{

}

//デストラクタ
CScenePause::~CScenePause()
{

}

//ゲームメイン初期化メソッド
void CScenePause::InitScene()
{	
	Font::SetStrTex(L"ゲームに戻る");

	Draw::LoadImageW(L"haikei.png", 1, TEX_SIZE_1024);

	//背景作成
	CObjPause* back1 = new CObjPause();
	Objs::InsertObj(back1, OBJ_PAUSE, 1);
}

//ゲームメイン実行中メソッド
void CScenePause::Scene()
{

}