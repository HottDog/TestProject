#pragma once
#include"tool.h"
class FileProcessor {
public:
	const static int DEFAULT_FILE_LENGTH;
	const static int DEFAULT_DECODE_LENGTH;
	FileProcessor(char * readFilePath, char * writeFilePath);
	FileProcessor(char * readFilePath,char * writeFilePath,int fileLength, int decodeLength);
	void ReadFileToBuff(int length);
	void WriteBuffToFile(int length);
private :
	//ÎÄ¼þ²Ù×÷
	char * _mReadFile;
	char * _mWriteFile;
	
	//buff
	byte * _mFileReadBuff;
	int _mMaxFileLength;
	int _mFileLength;
	byte * _mHaffmanDecodeBuff;
	int _mMaxDecodeLength;
	int _mDecodeLength;


	void _InitBuff();
};