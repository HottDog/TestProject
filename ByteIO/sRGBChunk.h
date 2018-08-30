#pragma once
#include"chunk.h"
const string sRGB_SIGN = "sRGB";
class sRGBChunk :public Chunk {
public:
	sRGBChunk(int length,ChunkType type);
private:
	int _mRenderIntent;   //��Ⱦ��ʽ��0���� Picture-Perceptual
						//		   1���� Proof-Relative Colorimetric
						//         2���� Graphic-Saturation
						//         3���� Match-Absolute Colorimetric
	virtual void _ParseData();
};