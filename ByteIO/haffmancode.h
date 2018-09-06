#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include"tool.h"
using namespace std;

#define SAFE_DELETE(p) {\
			if(p!=nullptr)\
			{\
				delete p;\
				p=nullptr;\
			}\
}
enum NodeType {ITEM,COMBINE};
template<class T >
struct Node {
	double weight;
	T value;
	NodeType type;
	Node * left;
	Node * right;
	int depth;
	string code;
	vector<int > code_int;
	int codeLenght;
	Node() {
		weight = 0;
		left = nullptr;
		right = nullptr;
		type = ITEM;
		depth = 0;
		codeLenght = 0;
	}
	Node(T v, double w, NodeType t) {
		value = v;
		weight = w;
		type = t;
		left = nullptr;
		right = nullptr;
		depth = 0;
		codeLenght = 0;
	}
	Node(NodeType t,Node* l,Node*  r) {
		type = t;
		left = l;
		right = r;
		weight = left->weight + right->weight;
		codeLenght = 0;
		if (l->depth > r->depth) {
			depth = l->depth;
		}
		else {
			depth = r->depth;
		}
		l->InscreaseDepth();
		r->InscreaseDepth();
	}
	~Node(){
		SAFE_DELETE(left);
		SAFE_DELETE(right);
	}
	void InscreaseDepth() {
		depth++;
		if (left != nullptr)
			left->InscreaseDepth();
		if (right != nullptr)
			right->InscreaseDepth();
	}
	void Print() {
		if (type == ITEM) {
			cout<<"("<<value.value<<","<<weight<<","<<depth<<")"<<"  ";
		}
		else {
			cout << "(," << weight << "," << depth << ")" << "  ";
		}
	}
	void PrintCode() {
		cout << value.value << ":";
		for (int i = 0; i < codeLenght; i++) {
			cout << code_int[i];
		}
		cout << endl;
	}
};

struct DataItem {
	DataItem(){}
	DataItem(byte v, double w) {
		value = v;
		weight = w;
	}
	byte value;
	double weight;
	void Print() {
		cout << value << "("<<int(value)<<"):" << weight << endl;
	}
};

int Statistic(const byte * data, int length, vector<DataItem> &result);

//从大到小排序
void Sort(vector<DataItem>&result, int length);

class HaffmanCode {
public:
	vector<DataItem> datas;
	int count = 0;

	HaffmanCode();
	~HaffmanCode();
	//权重从大到小排好序的数据
	void ProcessData(vector<DataItem> datas, int length);
	void Print();
	void Decode();
private :
	Node<DataItem> * root = nullptr;
	
	vector<Node<DataItem>*> nodes;
	int nodecount = 0;
	//初始化数据，数据已经是排好序的了,从大到小
	void _InitData();
	void _CombineNode(vector<Node<DataItem>*> nodes,int begin);
	void _ResortNodes(vector<Node<DataItem>*>& nodes,Node<DataItem>* node,int begin);
	void _Decode(Node<DataItem>* node);
};