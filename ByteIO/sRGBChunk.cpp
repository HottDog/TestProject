#include"sRGBChunk.h"
sRGBChunk::sRGBChunk(int length, ChunkType type):Chunk(length,type) {}

void sRGBChunk::_ParseData() {
	_mRenderIntent = (int)_mContent[0];
	cout << "RenderIntent:" << _mRenderIntent<<endl;
}