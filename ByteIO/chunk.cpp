#include"chunk.h"
Chunk::Chunk(int length, ChunkType type) {
	_mLength = length;
	_mType = type;
}

Chunk::~Chunk() {
	delete _mContent;
}

void Chunk::Process(ifstream& f) {
	//��ȡ���ݿ�����
	_ReadContent(f);
	//��������
	_ParseData();
}

void Chunk::_ReadContent(ifstream& f) {
	//�����ڴ�
	_mContent = new char[_mLength];
	//��ȡ���ݿ�����
	f.read(_mContent, _mLength);
	//��ȡCRC
	f.read((char *)&_mCRC, 4);
}

void Chunk::_ParseData() {

}