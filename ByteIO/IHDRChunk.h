#pragma once
#include"chunk.h"
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
const static string IHDR_SIGN = "IHDR";
//头部数据块
class IHDRChunk :public Chunk {
public:
	struct ChunkData {
		int width;			//图像宽度，以像素为单位,4byte
		int height;			//图像高度，以像素为单位,4byte
		int depth;          //图像深度,1byte
		int colorType;      //颜色类型,1byte,0代表Greyscale,2代表TrueColor,3代表Indexed-color
							//              4代表Greyscale with alpha,6代表Truecolor with alpha
		int compression;	//压缩方法,1byte
		int filter;			//滤波器方法,1byte
		int interlace;      //隔行扫描方法，1byte
	public:
		string ToString() {
			stringstream s;
			s << "width:" << width << "\n" <<
				"heigth:" << height << "\n" <<
				"depth:" << depth << "\n" <<
				"colorType:" << colorType << "\n" <<
				"compression:" << compression << "\n" <<
				"filter:" << filter << "\n" <<
				"interlace:" << interlace << "\n";
			return s.str();
		}

		void print() {
			cout << ToString();
		}
	};
public:
	IHDRChunk(int length, ChunkType type);
	ChunkData GetData();
private:
	ChunkData _mData;

	virtual void _ParseData();
};