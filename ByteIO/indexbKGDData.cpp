#include"indexbKGDData.h"
void IndexbKGDData::ParseData(const char * content) {
	index = *(int *)content[0];
	cout << "index:" << index << endl;
}