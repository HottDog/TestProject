#pragma once
#include"chunk.h"
const string PLTE_SIGN = "PLTE";
//��ɫ�����ݿ�
class PLTEChunk :public Chunk {
	struct Color {
		int red;   //1byte
		int green; //1byte
		int blue;  //1byte
	};
public:
	PLTEChunk(int length, ChunkType type);
private:
	Color *_mColors;
	int _mCount;
	virtual void _ParseData();
};