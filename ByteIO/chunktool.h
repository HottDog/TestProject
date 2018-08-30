#pragma once
#include"chunk.h"
#include"tool.h"
#include"IHDRChunk.h"
#include"cHRMChunk.h"
#include"PLTEChunk.h"
#include"gAMAChunk.h"
Chunk* CreateChunk(const char * sign, int length);