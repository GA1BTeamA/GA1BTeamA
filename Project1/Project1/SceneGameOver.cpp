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
#include "SceneGameOver.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//ゲームメイン初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GameOver");

	//タイトルオブジェクト作成
	CObjGameOver* obj = new CObjGameOver(); //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAME_OVER, 1); //主人公オブジェクト登録


}

//ゲームメイン実行中メソッド
void CSceneGameOver::Scene()
{

}