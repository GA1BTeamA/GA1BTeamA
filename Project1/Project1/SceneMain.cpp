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
	Draw::LoadImageW(L"imouto2.png", 0, TEX_SIZE_512);


	//�^�C���I�u�W�F�N�g
	//CObjTime* objt = new CObjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 0);

	//��l���I�u�W�F�N�g�쐬
	CObjhero* objh = new CObjhero();
	Objs::InsertObj(objh, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	//CObjBlock* obj = new CObjBlock();
	//Objs::InsertObj(obj, OBJ_BLOCK,0);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}