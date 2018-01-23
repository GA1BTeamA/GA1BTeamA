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
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//�Q�[�����C�����������\�b�h
void CSceneClear::InitScene()
{//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMClear.wav", BACK_MUSIC);

	//�{�����[����߂�
	float v = Audio::VolumeMaster(0.1);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GameClear");

	//Draw::LoadImageW(L"Title.png", 1, TEX_SIZE_1024);

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjClear* objt = new CObjClear(); //�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(objt, OBJ_CLEAR, 1); //��l���I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneClear::Scene()
{

}