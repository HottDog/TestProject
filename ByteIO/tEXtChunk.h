#pragma once
#include"chunk.h"
const string tEXt_SIGN = "tEXt";
class tEXtChunk :public Chunk {
public:
	const char nullchar = (char)0;   //约定好的key和value的分隔符
	struct Content {
		string key;
		string value;

		void print() {
			cout << key << ":" << value << endl;
		}
	};

	tEXtChunk(int length, ChunkType type);
private:
	Content _mData;

	virtual void _ParseData();
};