#include"PLTEChunk.h"

PLTEChunk::PLTEChunk(int length, ChunkType type) :Chunk(length, type) {}

void PLTEChunk::_ParseData() {
	_mCount = _mLength / 3;
	_mColors = new Color[_mCount];
	for (int i = 0; i < _mCount; i++) {
		_mColors[i].red = (int)_mContent[3*i+0];
		_mColors[i].green = (int)_mContent[3 * i + 1];
		_mColors[i].blue = (int)_mContent[3 * i + 2];
	}
}