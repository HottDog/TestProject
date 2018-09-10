#include"fileprocessor.h"

const int FileProcessor::DEFAULT_FILE_LENGTH = 1000;
const int FileProcessor::DEFAULT_DECODE_LENGTH = 1000;

FileProcessor::FileProcessor(char * readFilePath, char * writeFilePath) {
	_mReadFile = readFilePath;
	_mWriteFile = writeFilePath;
	_mMaxFileLength = DEFAULT_FILE_LENGTH;
	_mMaxDecodeLength = DEFAULT_DECODE_LENGTH;
	_mFileLength =0;
	_mDecodeLength=0;
	_InitBuff();
}

FileProcessor::FileProcessor(char * readFilePath, char * writeFilePath,int fileLength, int decodeLength) {
	_mReadFile = readFilePath;
	_mWriteFile = writeFilePath;
	_mMaxFileLength = fileLength;
	_mMaxDecodeLength = decodeLength;
	_mFileLength = 0;
	_mDecodeLength = 0;
	_InitBuff();
}

void FileProcessor::ReadFileToBuff(int length) {

}

void FileProcessor::WriteBuffToFile(int length) {

}

void FileProcessor::_InitBuff() {
	_mFileReadBuff = new byte[_mFileLength];
	_mHaffmanDecodeBuff = new byte[_mDecodeLength];
}