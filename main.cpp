#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>

#include <cstdio>
#define GL_SILENCE_DEPRECATION
#include "include/glew.h"

#include <OpenGL/gl.h>
#include "include/glfw3.h"
#include "GLUT/glut.h"
#include "OpenGL/glu.h"

#include <cstdlib>
#include "Cube.h"
#include <thread>
#include <atomic>
#include <chrono>

#include <random>
#include <ctime>

std::atomic<bool> running(true);

GLfloat T = 0;
Cube cube;
Cube displayCube;

void userInputThread() {
}