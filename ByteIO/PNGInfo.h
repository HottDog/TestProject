#pragma once
class PNGInfo {
public :
	static PNGInfo GetSingleton();
	int colorType;
private :
	PNGInfo();
	static PNGInfo _mSingleton;
};