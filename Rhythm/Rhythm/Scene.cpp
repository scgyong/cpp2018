#include "Scene.h"


Scene *Scene::currentScene = NULL;

Scene::Scene(RenderWindow &window) : window{ window }
{
}


Scene::~Scene()
{
}

void Scene::changeScene(Scene * scene)
{
	if (currentScene != NULL) {
		delete currentScene;
	}
	currentScene = scene;
}
