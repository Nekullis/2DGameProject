#pragma once
#include <memory>

class Scene;

class SceneManager
{
public:
	//シーン切り替え
	static void ChangeScene(Scene* scene);
	//更新
	static void Update();
	//描画
	static void Draw();

private:
	static std::unique_ptr<Scene> m_scene;
};

