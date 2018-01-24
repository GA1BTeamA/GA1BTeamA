//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "Objhero.h"

CObjBlock* g_objb;

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
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMGameMain.wav", BACK_MUSIC);

	//�{�����[������
	float v = Audio::VolumeMaster(0.1);

	//���y�X�^�[�g
	Audio::Start(0);

	//�O���t�B�b�N�ǂݍ���
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

	//�^�C���I�u�W�F�N�g
	//CObjTime* objt = new CObjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 0);

	//��l���Z�I�u�W�F�N�g�쐬
	objh = new CObjhero();
	//��l���I�u�W�F�N�g�쐬
	objh = new CObjhero();
	Objs::InsertObj(objh, OBJ_HERO, 10);

	//��l�����I�u�W�F�N�g�쐬
	CObjhero2* objh2 = new CObjhero2();
	Objs::InsertObj(objh2, OBJ_HERO2, 10);

	//block�I�u�W�F�N�g�쐬
	g_objb = new CObjBlock();
	Objs::InsertObj(g_objb, OBJ_BLOCK, 1);

	//�w�i�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

	////�G�쐬
	//CObjEnemy1* obje = new CObjEnemy1(100,0);
	//Objs::InsertObj(obje, OBJ_ENEMY1, 2);

	//�ŔI�u�W�F�N�g(��)�쐬
	CObjkanbans* objks = new CObjkanbans();
	Objs::InsertObj(objks, OBJ_KANBANS, 5);

	//�ŔI�u�W�F�N�g(�Z)�쐬
	CObjkanbanb* objkb = new CObjkanbanb();
	Objs::InsertObj(objkb, OBJ_KANBANB, 6);

	//�A�C�e���쐬
	CObjitem* obji = new CObjitem();
	Objs::InsertObj(obji, OBJ_ITEM, 4);

	//�A�C�e���쐬
	CObjitem2* obji2 = new CObjitem2();
	Objs::InsertObj(obji2, OBJ_ITEM2, 4);

	//��I�u�W�F�N�g�쐬
	CObjGate* objgate = new CObjGate();
	Objs::InsertObj(objgate, OBJ_GATE, 1);

	//�J��I�u�W�F�N�g(�E)�쐬
	CObjGateOpenRight* objgor = new CObjGateOpenRight();
	Objs::InsertObj(objgor, OBJ_GATEOPENRIGHT, 11);

	//�X�C�b�`(��)�쐬
	CObjswitchsis* objss = new CObjswitchsis();
	Objs::InsertObj(objss, OBJ_SWITCHS, 12);

	//�X�C�b�`(�Z)�쐬
	CObjswitchbro* objsb = new CObjswitchbro();
	Objs::InsertObj(objsb, OBJ_SWITCHB, 13);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}