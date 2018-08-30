#include"PngAnalyzeTask.h"
#include<fstream>
#include<iostream>
#include<string>
#include<cstddef>
#include"tool.h"
#include"IHDRChunk.h"
#include"cHRMChunk.h"
#include"chunktool.h"
using namespace std;
const char* MARIAO = "mariao.png";
const char * END_SIGN = "IEND";
typedef unsigned char byte;
const static byte PNG_TITLE[8] = { 0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A };
bool ReadPNG(const char * file) {
	ifstream f;
	f.open(file, ios::binary);
	//读取PNG头部署名域
	byte title[8];
	f.read((char *)&title, 8 * sizeof(byte));
	if (CompareBinarys(title,PNG_TITLE,8)) {
		cout << "This is a png"<<endl;
	}else{
		cout << "It's not a png"<<endl;
		return false;
	}
	//读取IHDR数据块
	int length = 0;
	char sign[4];
	f.read((char *)&length, 4);
	ChangeEndian(length);
	f.read(sign, 4 );
	Chunk * chunk;
	cout << "length:"<< length<<endl;
	if (Compare(sign,IHDR_SIGN,4)) {
		chunk = new IHDRChunk(length, IHDR);
		cout << "It is IHDR," << "length:" << length << endl;
		chunk->Process(f);
	}
	//读取其他数据块
	while (!Compare(sign, END_SIGN, 4)) {
		f.read((char *)&length, 4);
		f.read(sign, 4);
		ChangeEndian(length);
		cout << "--------数据块"<<Char2String(sign,4)<<"------length:"<<length<<"-----------"<<endl;
		//cout << "length:" << length << endl;
		//cout << "sign:" << sign << endl;
		Chunk * chunkTemp = CreateChunk(sign, length);
		chunkTemp->Process(f);
	}	
 	f.close();
	return true;
}


bool PngAnalyzeTask::Run() {
	ReadPNG(MARIAO);
	byte A[2] = {0000,1110};
	byte B[2] = { 0000,1110 };
	cout << CompareBinarys(A, B,2)<<endl;
	cout << "ox2d3 = " << 0x2D3<<endl;
	cout << "0:" << (char)0 << endl;
	return true;
}