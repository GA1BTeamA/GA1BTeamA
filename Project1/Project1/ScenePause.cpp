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
CScenePause::CScenePause()
{

}

//�f�X�g���N�^
CScenePause::~CScenePause()
{

}

//�Q�[�����C�����������\�b�h
void CScenePause::InitScene()
{	
	Font::SetStrTex(L"�Q�[���ɖ߂�");

	Draw::LoadImageW(L"haikei.png", 1, TEX_SIZE_1024);

	//�w�i�쐬
	CObjPause* back1 = new CObjPause();
	Objs::InsertObj(back1, OBJ_PAUSE, 1);
}

//�Q�[�����C�����s�����\�b�h
void CScenePause::Scene()
{

}