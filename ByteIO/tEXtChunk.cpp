#include"tEXtChunk.h"
#include<sstream>
using namespace std;
tEXtChunk::tEXtChunk(int length, ChunkType type) :Chunk(length,type) {};

void tEXtChunk::_ParseData() {
	bool isKey = true;
	stringstream keyss;
	stringstream valuess;
	
	for (int i = 0; i < _mLength; i++) {
		if (_mContent[i] == nullchar) {
			isKey = false;
		}
		else if (isKey) {
			keyss << _mContent[i];
		}
		else {
			valuess << _mContent[i];
		}
	}
	_mData.key = keyss.str();
	_mData.value = valuess.str();

	_mData.print();
}