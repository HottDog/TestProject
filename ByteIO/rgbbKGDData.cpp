#include"rgbbKGDData.h"
#include<string.h>
#include"tool.h"
void RgbbKGDData::ParseData(const char * content) {
	memcpy(&_mData.red, (char *)content, 2);
	ChangeEndian(_mData.red);
	content += 2;
	memcpy(&_mData.green, (char *)content, 2);
	ChangeEndian(_mData.green);
	content += 2;
	memcpy(&_mData.blue, (char *)content, 2);
	ChangeEndian(_mData.blue);
	_mData.Print();
}