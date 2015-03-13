#pragma once

// worldwide includes. MUST be included first in every cpp file

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef __APPLE__
#include <unistd.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.inl>

#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>
#include <ios>
#include <map>

#include <Logging.h>
#include <Helper.h>