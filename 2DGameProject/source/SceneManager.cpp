#include "SceneManager.h"
#include "Scene.h"

std::unique_ptr<Scene>SceneManager::m_scene;

void SceneManager::ChangeScene(Scene* scene)
{
	//unique_ptrに所有権移動
	m_scene.reset(scene);
}

void SceneManager::Update()
{
	//シーンがない場合、更新を行わない
	if (!m_scene)
	{
		return;
	}
	//入力処理
	m_scene->Input();
	//更新処理
	m_scene->Process();

}

void SceneManager::Draw()
{
	//シーンがない場合、描画を行わない
	if (!m_scene)
	{
		return;
	}
	//描画処理
	m_scene->Draw();
}
