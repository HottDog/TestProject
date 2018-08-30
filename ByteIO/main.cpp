#include<fstream>
#include<iostream>
#include"itask.h"
#include"iotask.h"
#include"testtask.h"
#include"PngAnalyzeTask.h"
#include"testclass.h"
using namespace std;


int main() {
	//ÎÄ±¾¶ÁÐ´
	//BinaryRead();
	//char ch[5] = {'h','a','h','a'};
	//cout << ch;
	ITask *task;
	//task = new IOTask();
	//task = new TestTask();
	task = new PngAnalyzeTask();
	//task = new TestClass(); 
	task->Run();
	delete task;
	system("pause");
}

