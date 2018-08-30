#include"testtask.h"
#include<string>
#include<iostream>
using namespace std;

void Test1() {
	if (strncmp("yjcyjc", "yjcyjcyc", 5)==0) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
}
bool TestTask::Run() {
	Test1();
	return true;
}

