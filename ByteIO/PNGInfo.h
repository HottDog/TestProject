#pragma once
#include"IHDRChunk.h"
class PNGInfo {
public :
	static PNGInfo* GetSingleton();
	IHDRChunk::ChunkData headData;
	~PNGInfo();
private :
	PNGInfo();
	static PNGInfo* _mSingleton;
};