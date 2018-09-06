#include"bKGDChunk.h"
bKGDChunk::bKGDChunk(int length, ChunkType type, int colorType) :Chunk(length, type) {
	_mColorType = colorType;	
}

void bKGDChunk::_ParseData() {
	_mData = _CreateDataByColorType(_mColorType);
	_mData->ParseData(_mContent);
}

bKGDData* bKGDChunk::_CreateDataByColorType(int colorType) {
	bKGDData *result = nullptr;
	switch (colorType)
	{
	case 0:
	case 4:
		result = new GreyScalebKGDData();
		break;
	case 2:
	case 6:
		result = new RgbbKGDData();
		break;
	case 3:
		result = new IndexbKGDData();
		break;
	default:
		break;
	}
	return result;
}