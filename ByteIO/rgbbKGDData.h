#pragma once
#include"bKGDData.h"
#include<iostream>
using namespace std;
class RgbbKGDData :public bKGDData {
	struct Color
	{
		int red;    //2byte
		int green;  //2byte
		int blue;   //2byte

		void Print() {
			cout << "red:" << red<<endl
				<<"green:"<<green<<endl
				<<"blue:"<<blue<<endl;

		}
	};
public:
	virtual void ParseData(const char * content);
private :
	Color _mData;
};