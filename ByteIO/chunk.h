#pragma once
#include<fstream>
#include<iostream>
#include"tool.h"
using namespace std;
enum ChunkType {
	DEFAULT,IHDR, IDAT,cHRM,PLTE,gAMA,sRGB,tEXt
};
class Chunk {
public :
	Chunk(int length,ChunkType type);
	virtual ~Chunk();
	virtual void Process(ifstream& f);
	
protected:
	int _mLength;
	ChunkType _mType ;
	unsigned char _mCRC[4];
	char *_mContent;	

	virtual void _ReadContent(ifstream& f);
	void virtual _ParseData();
};