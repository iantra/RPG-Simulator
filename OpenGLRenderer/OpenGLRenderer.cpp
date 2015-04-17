#define OpenGLRendererSource 1

#include "OpenGLRendererConfig.h"
#include <OpenGLRenderer.h>
#include <Renderer.h>
#include <ModuleManager.h>
#include <Helper.h>

Model* OpenGLRenderer::newModel(float* locations, float* UVs, int numVerts, int numElems)
{
	return new OpenGLModel(locations, UVs, numVerts, numElems);
}

void OpenGLRenderer::init()
{
	
}

void OpenGLRenderer::update()
{
}

void OpenGLRenderer::setCurrentCamera(Camera* newCamera)
{
	check(newCamera);

	currentCamera = newCamera;

}

void OpenGLRenderer::loadTextures(std::vector<std::string> /*textures*/)
{

}

OpenGLRenderer::~OpenGLRenderer()
{

}

Camera* OpenGLRenderer::getCurrentCamera()
{
	return currentCamera;
}

extern "C" OpenGLRendererPlugin_API void registerModule(ModuleManager& mm)
{
	mm.addRenderer(new OpenGLRenderer());
}
