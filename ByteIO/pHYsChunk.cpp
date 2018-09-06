#include"pHYsChunk.h"
pHYsChunk::pHYsChunk(int length, ChunkType type):Chunk(length,type){}

void pHYsChunk::_ParseData() {
	_mUnit.x = *(int *)&(_mContent[0]);
	ChangeEndian(_mUnit.x);
	_mUnit.y = *(int *)&(_mContent[4]);
	ChangeEndian(_mUnit.y);
	cout << "PixelPerUnit.X:" << _mUnit.x<<endl;
	cout << "PixelPerUnit.y:" << _mUnit.y << endl;
	_mSpecifier = (int) _mContent[5];
	cout << "UnitSpecifier:" << _mSpecifier << endl;
}