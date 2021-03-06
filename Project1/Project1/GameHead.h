#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	//OBJ_TIME,
	OBJ_HERO,
	OBJ_HERO2,
	OBJ_BLOCK,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_BACKGROUND,
	OBJ_ENEMY1,
	OBJ_PAUSE,
	OBJ_CLEAR,
	//OBJ_KANBANS,
	//OBJ_KANBANB,
	OBJ_ITEM,
	OBJ_ITEM2,
	OBJ_GATE,
	OBJ_GATEOPENRIGHT,
	OBJ_GOAL,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_SWITCH,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
//#include "objTime.h"
#include "Objhero.h"
#include "Objhero2.h"
#include "ObjBlock.h"
#include "ObjTitle.h"
#include "ObjGameOver.h"
#include "ObjBackground.h"
#include "ObjEnemy1.h"
#include "ObjPause.h"
#include "Objitem.h"
#include "Objitem2.h"
#include "ObjClear.h"
//#include "Objkanbans.h"
//#include "Objkanbanb.h"
//#include "Objgateopenleft.h"
//#include "Objgateopenright.h"
#include "ObjGate.h"
#include "ObjGoal.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "ScenePause.h"
#include "SceneClear.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------