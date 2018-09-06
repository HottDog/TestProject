#include"haffmancode.h"

int Statistic(const byte * data, int length, vector<DataItem> &result) {
	int count = 0;
	bool isNew = true;
	for (int i = 0; i < length; i++) {
		isNew = true;
		for (int j = 0; j < count; j++) {
			if (result[j].value == data[i]) {
				isNew = false;
				result[j].weight++;
				break;
			}
		}
		if (isNew) {
			result.push_back(DataItem(data[i], 1));
			count++;
		}
	}
	return count;
}

//从大到小
void Sort(vector<DataItem> &data, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i+1; j < length; j++) {
			if (data[i].weight < data[j].weight) {
				DataItem temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
}

HaffmanCode::HaffmanCode() {
	_InitData();
}

HaffmanCode::~HaffmanCode() {
	SAFE_DELETE(root);
}

void HaffmanCode::Decode() {
	if(root!=nullptr)
		_Decode(root);
}

void HaffmanCode::_Decode(Node<DataItem> *node) {
	stringstream ss;	
	if (node->type == ITEM) {
		//cout <<node->value.value<<":"<<node->code<< endl;
		node->PrintCode();
		return;
	}
	if (node->left != nullptr) {
		ss << node->code;
		ss << '0';

		node->left->code_int = node->code_int;
		node->left->code_int.push_back(0);
		node->left->codeLenght = node->codeLenght;
		node->left->codeLenght++;

		node->left->code = ss.str();
		
		_Decode(node->left);
	}
	ss.str("");
	if (node->right != nullptr) {
		ss << node->code;
		ss << '1';
		node->right->code_int = node->code_int;
		node->right->code_int.push_back(1);
		node->right->codeLenght = node->codeLenght;
		node->right->codeLenght++;

		node->right->code = ss.str();
		_Decode(node->right);
	}
}

void HaffmanCode::Print() {
	vector<Node<DataItem>*> tempContainer;
	int tempcount = 0;
	tempContainer.push_back(root);
	tempcount++;
	int index = 0;
	int depth = 0;
	while (index < tempcount) {
		Node<DataItem>* node = tempContainer[index];
		if (node->depth != depth) {
			depth = node->depth;
			cout << endl;
		}
		node->Print();		
		if (node->left != nullptr) {
			tempContainer.push_back(node->left);
			tempcount++;
		}
		if (node->right != nullptr) {
			tempContainer.push_back(node->right);
			tempcount++;
		}
		index++;
	}
	cout << endl;
}

void HaffmanCode::ProcessData(vector<DataItem> datas,int length) {
	//把所有的数据处理成node节点
	for (int i = length-1; i>=0; i--) {
		nodes.push_back(new Node<DataItem>(datas[i], datas[i].weight, ITEM));
		nodecount++;
	}
	//然后再处理所有的node节点	
	_CombineNode(nodes, 0);
}

void HaffmanCode::_CombineNode(vector<Node<DataItem>*> nodes,int begin) {
	if (nodecount - begin <= 1) {
		root = nodes[begin];
		return;
	}
	Node<DataItem>* left = nodes[begin];
	begin++;
	Node<DataItem>* right = nodes[begin];
	Node<DataItem>* parent = new Node<DataItem>(COMBINE,left,right);
	_ResortNodes(nodes, parent, begin);
	_CombineNode(nodes, begin);
}

void HaffmanCode::_ResortNodes(vector<Node<DataItem>*>& nodes, Node<DataItem>* node,int begin) {
	nodes[begin] = node;
	for (int i = begin; i < (nodecount-1); i++) {
		int next = i + 1;
		if (nodes[i]->weight > nodes[next]->weight) {
			Node<DataItem>* temp = nodes[i];
			nodes[i] = nodes[next];
			nodes[next] = temp;
		}
		else {
			break;
		}
	}
}

void HaffmanCode::_InitData() {
	datas.push_back(DataItem(' ', 5));
	datas.push_back(DataItem('w', 4));
	datas.push_back(DataItem('l', 4));
	datas.push_back(DataItem('e', 2));
	datas.push_back(DataItem('i', 2));
	datas.push_back(DataItem('r', 1));
	datas.push_back(DataItem('u', 1));
	count = 7;
}