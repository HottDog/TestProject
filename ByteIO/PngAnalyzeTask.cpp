#include"PngAnalyzeTask.h"

const char* MARIAO = "mariao.png";
const char * END_SIGN = "IEND";
const static byte PNG_TITLE[8] = { 0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A };

bool ReadPNG(const char * file) {
	ifstream f;
	f.open(file, ios::binary);
	//读取PNG头部署名域
	byte title[8];
	f.read((char *)&title, 8 * sizeof(byte));
	if (CompareBinarys(title,PNG_TITLE,8)) {
		cout << "This is a png"<<endl;
	}else{
		cout << "It's not a png"<<endl;
		return false;
	}
	//读取IHDR数据块
	int length = 0;
	char sign[4];
	f.read((char *)&length, 4);
	ChangeEndian(length);
	f.read(sign, 4 );
	Chunk * chunk;
	cout << "length:"<< length<<endl;
	if (Compare(sign,IHDR_SIGN,4)) {
		chunk = new IHDRChunk(length, IHDR);
		cout << "--------数据块" << Char2String(sign, 4) << "------length:" << length << "-----------" << endl;
		chunk->Process(f);
		PNGInfo::GetSingleton()->headData =((IHDRChunk*)chunk)->GetData();
	}

	//读取其他数据块
	while (!Compare(sign, END_SIGN, 4)) {
		f.read((char *)&length, 4);
		f.read(sign, 4);
		ChangeEndian(length);
		cout << "--------数据块"<<Char2String(sign,4)<<"------length:"<<length<<"-----------"<<endl;
		//cout << "length:" << length << endl;
		//cout << "sign:" << sign << endl;
		Chunk * chunkTemp = CreateChunk(sign, length, PNGInfo::GetSingleton()->headData);
		chunkTemp->Process(f);
	}	
 	f.close();
	return true;
}


bool PngAnalyzeTask::Run() {
	//ReadPNG(MARIAO);
	/*byte A[2] = {0000,1110};
	byte B[2] = { 0000,1110 };
	cout << CompareBinarys(A, B,2)<<endl;
	cout << "ox2d3 = " << 0x2D3<<endl;
	cout << "0:" << (char)0 << endl;*/
	
	string ss = "we will we will r uSDASdss ae as d...sadasdwrqeqwedsfdsfweqfqqfewgregerdsf fwefw fwf wfe wf]]]]]]";
	vector<DataItem> result;
	int num = Statistic((byte*)(ss.c_str()), 97, result);
	Sort(result,num);
	for (int i = 0; i < num; i++) {
		result[i].Print();
	}
	HaffmanCode code;
	code.ProcessData(result, num);
	code.Print();
	code.Decode();
	return true;
}