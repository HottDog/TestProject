#pragma once
#include"chunk.h"
#include"DataTool.h"
#include<string>
const string cHRM_SIGN = "cHRM";
class cHRMChunk :public Chunk {

	struct Chromaticity {
		Vector2 whitePoint;
		Vector2 red;
		Vector2 green;
		Vector2 blue;
		void Prints() {
			_Print(whitePoint, "WhitePoint");
			_Print(red, "Red");
			_Print(green, "Green");
			_Print(blue, "Blue");
		}
		void _Print(Vector2 v, string s) {
			cout << s << ":(" << v.x <<","<< v.y << ")" << endl;
		}
	};
public:
	cHRMChunk(int length, ChunkType type);
private:
	Chromaticity _mData;
	void virtual _ParseData();
	void _GetValue(Vector2& v, int index);
};