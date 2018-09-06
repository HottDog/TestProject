#pragma once
#include"chunk.h"
#include"tool.h"
const string pHYs_SIGN = "pHYs";
class pHYsChunk :public Chunk {
	//每个Unit的XY轴上分别由多少像素
	struct PixelPerUnit {
		int x;   //x轴上的像素
		int y;   //y轴上的像素
	};
public:
	pHYsChunk(int length, ChunkType type);
private :
	PixelPerUnit _mUnit;
	int _mSpecifier;     //Unit的物理长度单位，1byte, 1表示1Unit为1米，0表示不确定

	virtual void _ParseData();
};