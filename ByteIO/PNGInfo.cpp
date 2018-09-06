#include"PNGInfo.h"
PNGInfo::PNGInfo(){}

PNGInfo* PNGInfo::GetSingleton() {
	if (!_mSingleton) {
		_mSingleton = new PNGInfo();
	}
	return _mSingleton;
}

PNGInfo::~PNGInfo() {
	if (_mSingleton) {
		delete _mSingleton;
	}
}

PNGInfo* PNGInfo::_mSingleton = nullptr;