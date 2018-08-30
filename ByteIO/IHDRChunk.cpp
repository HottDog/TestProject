#include"IHDRChunk.h"
#include"tool.h"

IHDRChunk::IHDRChunk(int length, ChunkType type) :Chunk(length, type) {};

void IHDRChunk::_ParseData() {
	_mData.width = *(int*)&(_mContent[0]);
	ChangeEndian(_mData.width);
	//cout << "width:" << _mData.width<<endl;
	_mData.height = *(int*)&(_mContent[4]);
	ChangeEndian(_mData.height);
	//cout << "height:" << _mData.height << endl;
	_mData.depth = (int)_mContent[8];
	//cout << "depth:" << _mData.depth << endl;
	_mData.colorType = (int)_mContent[9];
	//cout << "colorType:" << _mData.colorType << endl;
	_mData.compression = (int)_mContent[10];
	_mData.filter = (int)_mContent[11];
	_mData.interlace = (int)_mContent[12];
	_mData.print();
}
