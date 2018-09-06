#include"tool.h"
#include<vector>
#include"haffmancode.h"
bool CompareBinarys(const unsigned char *A, const unsigned char *B,int length) {
	for (int i = 0; i < length; i++) {
		if (!CompareBinary(A[i],B[i])) {
			return false;
		}
	}
	return true;
}

bool CompareBinary(unsigned char A, unsigned char B) {
	if (A^B == 0) {
		return true;
	}
	else {
		return false;
	}
}

//是否是大端序
bool IsBigEndian() {
	int a = 1;
	if (((char*)&a)[3] == 1) {
		return true;
	}
	else {
		return false;
	}
}

void ChangeEndian(int& a) {
	if (!IsBigEndian()) {
		a = BigtoLittle32(a);
	}
}

bool Compare(const char * A, const string B, int length)
{
	for (int i = 0; i < length; i++) {
		if (A[i] != B[i]) {
			return false;
		}
	}
	return true;
}

string Char2String(const char * A,int length){
	stringstream s;
	for (int i = 0; i < length; i++) {
		s << A[i];
	}
	return s.str();
}

//编码
int HaffmanDecode(byte *data, int length, byte *result) {
	vector<DataItem> input;
	int num = Statistic(data, 97, input);
	Sort(input, num);
	for (int i = 0; i < num; i++) {
		input[i].Print();
	}
	HaffmanCode code;
	code.ProcessData(input, num);
	code.Print();
	code.Decode();
	return 0;
}

//解码
int HaffmanEncode(byte *data, int length, byte *result) {
	return 0;
}
