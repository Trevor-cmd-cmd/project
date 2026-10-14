#pragma once

// Engine core types
#include "component.h"
#include "transform.h"
#include "vector.h"
#include "object.h"
#include "sprite.h"

// Graphics and rendering types
#include "camera.h"
#include "mesh.h"
#include "shaders.h"
#include "texture.h"



void tgeInit();
void tgeMakewindow(int width, int height, const char* title);
void tgeCreateWindow(int width, int height, const char* title);
bool tgeTick();
void tgeShutDown();
