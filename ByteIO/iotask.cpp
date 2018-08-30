#include"iotask.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
//�ı���д
//�����������ַ���ȡ�ļ�
void fileRead1() {
	fstream f;
	f.open("1.txt", ios::in);
	char ch;
	while (EOF != (ch = f.get())) {
		cout << ch;
	}
	f.close();
}

//���ж�ȡ�ļ�
void fileRead2() {
	fstream f;
	f.open("1.txt", ios::in);
	char line[128];
	int numBytes;
	while (!f.eof()) {
		f.getline(line, 128);
		numBytes = f.gcount();
		cout << line << "    " << "byte num:" << numBytes;
	}
	f.close();
}

//����ʽ��ȡ�ļ�
void fileRead3() {
	fstream f;
	f.open("1.txt", ios::in);
	char ch[3];
	int i;
	double d;
	f >> ch[0] >> ch[1] >> ch[2];
	f >> i >> d;
	cout << ch[0] << ch[1] << ch[2] << endl;
	cout << i << endl;
	cout << d << endl;
	f.close();
}

void fileWrite() {
	fstream f;
	f.open("1.txt", ios::app);
	f << "yjc" << 23 << 20.01;
	f.close();
}

//�����ƶ�д

void BinaryWrite() {
	ofstream f;
	string s1 = "hah";
	int s2 = 120;
	double s3 = 23.22;
	int s4 = 1000;
	f.open("1.dat", ios::binary);
	f.write(s1.c_str(), 3 * sizeof(char));
	f.write((char*)&s2, sizeof(int));
	f.write((char*)&s3, sizeof(double));
	f.write((char*)&s4, sizeof(int));
	f.close();
}

void BinaryRead() {
	ifstream f;
	f.open("1.dat", ios::binary);
	char ch[3] = {0};
	int s2;
	double s3;
	int s4;
	f.read(ch, 3 * sizeof(char));
	f.read((char *)&s2, sizeof(int));
	f.read((char *)&s3, sizeof(double));
	f.read((char *)&s4, sizeof(int));
	cout << "string:" << ch[0]<<ch[1]<<ch[0]<<endl;
	cout << "int:" << s2 << endl;
	cout << "double:" << s3 << endl;
	cout << "int:" << s4 << endl;
	cout << "s2+s4=" << s2+s4 << endl;
	f.close();
}

void ReadDDS(const char * filepath) {
	ifstream f;
	f.open(filepath, ios::binary);

}

bool IOTask::Run() {
	//BinaryWrite();
	BinaryRead();
	return true;
}


