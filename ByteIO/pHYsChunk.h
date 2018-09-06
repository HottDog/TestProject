#pragma once
#include"chunk.h"
#include"tool.h"
const string pHYs_SIGN = "pHYs";
class pHYsChunk :public Chunk {
	//ÿ��Unit��XY���Ϸֱ��ɶ�������
	struct PixelPerUnit {
		int x;   //x���ϵ�����
		int y;   //y���ϵ�����
	};
public:
	pHYsChunk(int length, ChunkType type);
private :
	PixelPerUnit _mUnit;
	int _mSpecifier;     //Unit�������ȵ�λ��1byte, 1��ʾ1UnitΪ1�ף�0��ʾ��ȷ��

	virtual void _ParseData();
};