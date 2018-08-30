#pragma once
#include"chunk.h"
const string gAMA_SIGN = "gAMA";
class gAMAChunk :public Chunk {
public:
	gAMAChunk(int length, ChunkType type);
private :
	int _mGama;
	virtual void _ParseData();
};