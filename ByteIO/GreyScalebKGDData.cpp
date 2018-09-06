#include"greyscalebKGDData.h"
#include<string.h>
#include"tool.h"
void GreyScalebKGDData::ParseData(const char * content) {
	memcpy(&_mGrayScale,(char *) content, 2);
	ChangeEndian(_mGrayScale);
	cout << "Greyscale:" << _mGrayScale << endl;
}