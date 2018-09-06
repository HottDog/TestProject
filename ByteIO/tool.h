#pragma once
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
typedef unsigned int uint32;
typedef unsigned char byte;
#define BigtoLittle32(A)   ((( (uint32)(A) & 0xff000000) >> 24) | \
                                       (( (uint32)(A) & 0x00ff0000) >> 8)   | \
                                       (( (uint32)(A) & 0x0000ff00) << 8)   | \
                                       (( (uint32)(A) & 0x000000ff) << 24))
bool CompareBinarys(const unsigned char* A,const unsigned char* B,int length);
bool CompareBinary(unsigned char A, unsigned char B);
bool IsBigEndian();

//´ó¶ËÐò×ª³ÉÐ¡¶ËÐò
void ChangeEndian(int& a);

//×Ö·û±È½Ï
bool Compare(const char * A, const string B,int length);
string Char2String(const char * A,int length);

//¹þ·òÂü±àÂë
int HaffmanDecode(byte *data,int length,byte *result);

//¹þ·òÂü½âÂë
int HaffmanEncode(byte *data, int length, byte *result);