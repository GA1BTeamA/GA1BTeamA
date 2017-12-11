//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GameStart");

	Draw::LoadImageW(L"�^�C�g��.png", 1, TEX_SIZE_1024);

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* objt = new CObjTitle(); //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(objt, OBJ_TITLE, 1); //��l���I�u�W�F�N�g�o�^

	
}

//�Q�[�����C�����s�����\�b�h
void CSceneTitle::Scene()
{

}