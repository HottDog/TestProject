#include"cHRMChunk.h"
#include"tool.h"

cHRMChunk::cHRMChunk(int length, ChunkType type) :Chunk(length, type) {}

void cHRMChunk::_ParseData() {	
	_GetValue(_mData.whitePoint, 0);
	_GetValue(_mData.red, 8);
	_GetValue(_mData.green, 16);
	_GetValue(_mData.blue, 24);

	_mData.Prints();
}

void cHRMChunk::_GetValue(Vector2& v, int index) {
	v.x = *(int*)&_mContent[index];
	ChangeEndian(v.x);
	v.y = *(int*)&_mContent[index+4];
	ChangeEndian(v.y);
}