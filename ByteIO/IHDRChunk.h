#pragma once
#include"chunk.h"
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
const static string IHDR_SIGN = "IHDR";
//ͷ�����ݿ�
class IHDRChunk :public Chunk {
public:
	struct ChunkData {
		int width;			//ͼ���ȣ�������Ϊ��λ,4byte
		int height;			//ͼ��߶ȣ�������Ϊ��λ,4byte
		int depth;          //ͼ�����,1byte
		int colorType;      //��ɫ����,1byte,0����Greyscale,2����TrueColor,3����Indexed-color
							//              4����Greyscale with alpha,6����Truecolor with alpha
		int compression;	//ѹ������,1byte
		int filter;			//�˲�������,1byte
		int interlace;      //����ɨ�跽����1byte
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