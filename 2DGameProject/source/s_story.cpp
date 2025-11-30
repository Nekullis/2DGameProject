#include "DxLib.h"
#include "gamemain.h"
#include "s_story.h"

SceneStory::SceneStory() {
	_cgStory = LoadGraph("res/");		// ストーリ画像
}

SceneStory::~SceneStory() {
	DeleteGraph(_cgStory);		// ストーリ画像をメモリから削除
}

void SceneStory::Input() {

}

void SceneStory::Process() {

}

void SceneStory::Draw() {
	
}