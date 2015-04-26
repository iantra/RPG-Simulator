// local includes
#include "Engine.h"
#include "MainWindow.h"
#include "Helper.h"
#include "ENGException.h"
#include "Logging.h"

/*************** P R O T O T Y P E S ***************************************************/
void draw(float delta);
int32 init();
void keyboard(GLFWwindow* window, float delta);
void scroll(GLFWwindow* winodw, GLdouble x, GLdouble y);
void resize(GLFWwindow* window, int32 x, int32 y);
int32 exit();


glm::mat4 viewMat;
glm::mat4 projection;


// 1/sclae * 2 is how many units fit vertically
float scale = 0.1f;

static const float minScale = .00625f;
static const float maxScale = 1.f;

cl_int initCL();

#if defined _WIN32 || defined WIN32
void changeDir()
{
	// changes the path so everything we open will be in Resoruce/
	char ownPth[MAX_PATH];

	// Will contain exe path
	HMODULE hModule = GetModuleHandle(nullptr);
	if (hModule == nullptr)
	{
		FATAL_ERR("getModuleHandle failed");
	}
	// When passing NULL to GetModuleHandle, it returns handle of exe itself
	GetModuleFileName(hModule, ownPth, (sizeof(ownPth)));

	std::string path = ownPth;
	//path = path.substr(0, path.size() - 14);

	// remove the exe and the directory
	for (int i = 0; i < 3; i++){


		do {
			path = path.substr(0, path.size() - 1);
		} while (path[path.size() - 1] != '\\');

	}
	int err = _chdir(path.append("Resource\\").c_str());

	if (err)
	{
		FATAL_ERR("chdir failed. Error num: " + err);
	}

}
#endif

#ifdef __linux__

#error "Linux change directory code not implemented"

void changeDir()
{
	//TODO write linux code

	return 0;
}
#endif

#ifdef __APPLE__
void changeDir()
{
	char path[1024];
	uint32_t size = sizeof(path);
	if (_NSGetExecutablePath(path, &size) == 0)
		printf("executable path is %s\n", path);
	else
		printf("buffer too small; need size %u\n", size);

	std::string pathStr = path;
	//path = path.substr(0, path.size() - 14);

	// remove the exe and the directory
	for (int i = 0; i < 3; i++){

		do {
			path = pathStr.substr(0, pathStr.size() - 1);
		} while (pathStr[pathStr.size() - 1] != '\\');

	}


	chdir(pathStr.c_str());

}
#endif

int32 main()
{

	changeDir();


	logging::init();

	auto window = MainWindow("RPG-Simulator", WindowMode::WINDOWED, uvec2(800, 600));

	try{

		// run the window. consumes the thread until it returns
		window.run();
	}
	catch (std::exception&)
	{
		return -1;
	}
	
}


