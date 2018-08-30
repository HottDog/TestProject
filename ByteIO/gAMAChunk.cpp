#include"gAMAChunk.h"
gAMAChunk::gAMAChunk(int length, ChunkType type) :Chunk(length,type){}

void gAMAChunk::_ParseData() {
	_mGama = *(int *)&_mContent[0];
	ChangeEndian(_mGama);
	cout << "gama:" << _mGama << endl;
}