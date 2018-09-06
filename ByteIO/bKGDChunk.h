#pragma once
#include "chunk.h"
#include"bKGDData.h"
#include"greyscalebKGDData.h"
#include"rgbbKGDData.h"
#include"indexbKGDData.h"
const string bKGD_SIGN = "bKGD";
class bKGDChunk :public Chunk {
public:
	bKGDChunk(int length, ChunkType type,int colorType);
private:
	int _mColorType;
	bKGDData *_mData;

	void virtual _ParseData();
	bKGDData * _CreateDataByColorType(int colorType);
};