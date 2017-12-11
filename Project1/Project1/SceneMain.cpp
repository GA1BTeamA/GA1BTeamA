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
	Draw::LoadImageW(L"Block1.png", 1, TEX_SIZE_32);
	Draw::LoadImageW(L"haikei.png", 0, TEX_SIZE_1024);
	Draw::LoadImageW(L"��������.png", 2, TEX_SIZE_256);

	//�^�C���I�u�W�F�N�g
	//CObjTime* objt = new CObjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 0);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 1);

	//�w�i�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

	//�G�쐬
	CObjEnemy1* obje = new CObjEnemy1();
	Objs::InsertObj(obje, OBJ_ENEMY1, 2);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}