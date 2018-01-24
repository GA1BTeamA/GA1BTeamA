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
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//ゲームメイン初期化メソッド
void CSceneClear::InitScene()
{//音楽読み込み
	Audio::LoadAudio(0, L"BGMClear.wav", BACK_MUSIC);

	//ボリュームを戻す
	float v = Audio::VolumeMaster(0.1);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GameClear");

	//Draw::LoadImageW(L"Title.png", 1, TEX_SIZE_1024);

	//タイトルオブジェクト作成
	CObjClear* objt = new CObjClear(); //クリアオブジェクト作成
	Objs::InsertObj(objt, OBJ_CLEAR, 1); //主人公オブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneClear::Scene()
{

}