#include"chunktool.h"
#include"sRGBChunk.h"
#include"tEXtChunk.h"
#include"bKGDChunk.h"
#include"pHYsChunk.h"
Chunk* CreateChunk(const char * sign, int length,IHDRChunk::ChunkData head) {
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
	else if (Compare(sign, tEXt_SIGN, 4)) {
		result = new tEXtChunk(length, tEXt);
	}
	else if (Compare(sign, bKGD_SIGN, 4)) {
		result = new bKGDChunk(length, bKGD, head.colorType);
	}
	else if (Compare(sign, pHYs_SIGN, 4)) {
		result = new pHYsChunk(length, pHYs);
	}
	else {
		result = new Chunk(length, DEFAULT);
	}
	return result;
}