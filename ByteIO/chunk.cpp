#include"chunk.h"
Chunk::Chunk(int length, ChunkType type) {
	_mLength = length;
	_mType = type;
}

Chunk::~Chunk() {
	delete _mContent;
}

void Chunk::Process(ifstream& f) {
	//读取数据块内容
	_ReadContent(f);
	//解析内容
	_ParseData();
}

void Chunk::_ReadContent(ifstream& f) {
	//分配内存
	_mContent = new char[_mLength];
	//读取数据块内容
	f.read(_mContent, _mLength);
	//读取CRC
	f.read((char *)&_mCRC, 4);
}

void Chunk::_ParseData() {

}