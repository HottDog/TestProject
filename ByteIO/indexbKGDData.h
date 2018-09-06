#pragma once
#include"bKGDData.h"
#include<iostream>
using namespace std;
class IndexbKGDData :public bKGDData {
public:
	virtual void ParseData(const char * content);
private:
	int index;
};