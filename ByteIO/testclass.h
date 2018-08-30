#pragma once
#include"itask.h"
class A {
public :
	int index = 1;
};

class B {
public :
	A a;
};

class TestClass :public ITask {
public :
	bool Run();
protected:
	B *b;
};