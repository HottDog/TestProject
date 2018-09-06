#pragma once
#include"bKGDData.h"
class GreyScalebKGDData :public bKGDData {
public:
	virtual void ParseData(const char * content);
private :
	int _mGrayScale;
};