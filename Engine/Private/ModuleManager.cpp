#include "Engine.h"
#include "ModuleManager.h"
#include "Helper.h"

ModuleManager::~ModuleManager()
{
	delete renderer;
	delete createWorld;
}

ModuleManager::ModuleManager()
	: renderer(nullptr)
{

}

Renderer& ModuleManager::getRenderer()
{
	check(renderer);

    return *renderer;
	
}

void ModuleManager::loadModule(const std::string& filename)
{
	
	if (loadedModules.find(filename) == loadedModules.end())
	{
		loadedModules.insert(std::map<std::string, Module>::value_type(filename, Module(filename))).first->second.registerModule(*this);
	}
}

void ModuleManager::addRenderer(Renderer* newRenderer)
{
	
	avaliableRenderers.push_back(newRenderer);

	if (!renderer)
	{
		renderer = newRenderer;
	}
}

void ModuleManager::setWorld(std::function<World*(std::string)> createWorldFun)
{
	
	// copy to the class's version
	createWorld = new std::function<World*(std::string)>(createWorldFun);
}

World* ModuleManager::newWorld(std::string path)
{
	check(createWorld);

	return (*createWorld)(path);
}