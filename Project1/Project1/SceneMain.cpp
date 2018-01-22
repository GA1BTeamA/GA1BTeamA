//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "Objhero.h"

CObjhero* objh;

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������\�b�h
void CSceneMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"block0.png"  , 1, TEX_SIZE_512);
	//Draw::LoadImageW(L"Block1.png"  , 1, TEX_SIZE_32);
	//Draw::LoadImageW(L"Block2.png"  , 4, TEX_SIZE_32);
	Draw::LoadImageW(L"haikei.png"  , 0, TEX_SIZE_1024);
	Draw::LoadImageW(L"ookami.png", 2, TEX_SIZE_256);
	Draw::LoadImageW(L"kanban sis.png", 4, TEX_SIZE_32);
	//Draw::LoadImageW(L"imouto1.png" , 3, TEX_SIZE_512);
	Draw::LoadImageW(L"ani1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"waku.png", 4, TEX_SIZE_64);
	//Draw::LoadImageW(L"goal.png", 7, TEX_SIZE_64);

	//�^�C���I�u�W�F�N�g
	//CObjTime* objt = new CObjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 0);

	//��l���I�u�W�F�N�g�쐬
	objh = new CObjhero();
	Objs::InsertObj(objh, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 1);

	//�w�i�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

	////�G�쐬
	//CObjEnemy1* obje = new CObjEnemy1(100,0);
	//Objs::InsertObj(obje, OBJ_ENEMY1, 2);

	//�ŔI�u�W�F�N�g�쐬
	CObjkanban* objk = new CObjkanban();
	Objs::InsertObj(objk, OBJ_KANBAN, 4);

	//�A�C�e���쐬
	CObjitem* obji = new CObjitem();
	Objs::InsertObj(obji, OBJ_ITEM, 4);

	//�A�C�e���쐬
	CObjitem2* obji2 = new CObjitem2();
	Objs::InsertObj(obji2, OBJ_ITEM2, 4);

	//�S�[���I�u�W�F�N�g�쐬
	//CObjGoal* objg = new CObjGoal();
	//Objs::InsertObj(objg, OBJ_GOAL, 7);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}