#pragma once
#include"chunk.h"
const string sRGB_SIGN = "sRGB";
class sRGBChunk :public Chunk {
public:
	sRGBChunk(int length,ChunkType type);
private:
	int _mRenderIntent;   //渲染方式，0代表 Picture-Perceptual
						//		   1代表 Proof-Relative Colorimetric
						//         2代表 Graphic-Saturation
						//         3代表 Match-Absolute Colorimetric
	virtual void _ParseData();
};