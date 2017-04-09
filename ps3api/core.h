#pragma once


uint32_t address32;
uint32_t bytes32;
uint32_t address64;
uint32_t bytes64;

uint32_t puCount;
uint32_t* puBuffer;

unsigned char readBytes;

unsigned char nop[] = {0x60, 0x00, 0x00, 0x00};
unsigned char jmp[] = {0x4B, 0xFF, 0xFE, 0xDD};


struct getmem 
{
	int hTarget;
	uint32_t uUnit;
	uint32_t ProcessID;
	uint64_t uThreadID;
	uint64_t uAddress;
	int nCount;
	unsigned char* pBuffer;

};

struct setmem 
{
	int hTarget;
	uint32_t uUnit;
	uint32_t ProcessID;
	uint64_t uThreadID;
	uint64_t uAddress;
	int nCount;
	const unsigned char* pBuffer;

};





