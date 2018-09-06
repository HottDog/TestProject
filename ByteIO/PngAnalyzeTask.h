#pragma once

#include"itask.h"
#include<fstream>
#include<iostream>
#include<string>
#include<cstddef>
#include"tool.h"
#include"IHDRChunk.h"
#include"cHRMChunk.h"
#include"chunktool.h"
#include"PNGInfo.h"
#include"haffmancode.h"
using namespace std;

bool ReadPNG(const char * file);

class PngAnalyzeTask :public ITask {
public :
	bool Run();
};