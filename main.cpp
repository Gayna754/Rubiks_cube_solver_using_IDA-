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
    while (running) {
        std::string userInput;
        std::getline(std::cin, userInput);

        int index = -1;

        if (userInput == "solve") {
            cube.IDAStar(cube.findHeuristicValue() + 1);

            std::cout << "Solution: ";

            for (auto sol: cube.solution) {
                std::cout << sol << " ";
            }
        }
        else if(userInput == "scramble") {
            cube.scramble(5);
        }
        else if(userInput == "solved") {
            std::cout << cube.solved() << "\n";
        }
        // Do something with the input
        if (userInput.substr(0, 1) == "w") {
            index = 0;
        }
        else if (userInput.substr(0, 1) == "o") {
            index = 1;
        }
        else if (userInput.substr(0, 1) == "y") {
            index = 2;
        }
        else if (userInput.substr(0, 1) == "r") {
            index = 3;
        }
        else if (userInput.substr(0, 1) == "b") {
            index = 4;
        }
        else if (userInput.substr(0, 1) == "g") {
            index = 5;
        }
        else {
        }

        if (userInput.substr(userInput.length() - 1, userInput.length()) == "I") {

            if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "UI") {
                cube.UI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "DI") {
                cube.DI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "RI") {
                cube.RI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "LI") {
                cube.LI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "FI") {
                cube.FI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "BI") {
                cube.BI(cube.sides[index]);
            }
            else {
            }
        }

        else {
            if (userInput.substr(userInput.length() - 1, userInput.length()) == "U") {
                cube.U(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "D") {
                cube.D(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "R") {
                cube.R(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "L") {
                cube.L(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "F") {
                cube.F(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "B") {
                cube.B(cube.sides[index]);
            }
            else {
            }
        }
    }
}