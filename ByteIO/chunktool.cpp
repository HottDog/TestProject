#include"chunktool.h"
#include"sRGBChunk.h"
Chunk* CreateChunk(const char * sign, int length) {
	Chunk * result = nullptr;
	if (Compare(sign, IHDR_SIGN, 4)) {
		//创建IHDR
		result = new IHDRChunk(length, IHDR);
	}
	else if (Compare(sign, cHRM_SIGN, 4)) {
		//创建cHRM
		result = new cHRMChunk(length, cHRM);
	}
	else if (Compare(sign, PLTE_SIGN, 4)) {
		//创建PLTE
		result = new PLTEChunk(length, PLTE);
	}
	else if (Compare(sign, gAMA_SIGN, 4)) {
		result = new gAMAChunk(length, gAMA);
	}
	else if (Compare(sign, sRGB_SIGN, 4)) {
		result = new sRGBChunk(length, sRGB);
	}
	else {
		result = new Chunk(length, DEFAULT);
	}
	return result;
}