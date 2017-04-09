// Code Based off Bad Luck Modders YouTube video https://www.youtube.com/watch?v=vbn7REESdEw


// PSN Bypass TMAPI C++ Test Tool

// Part of the Tutorial at:
// http://www.psx-place.com/threads/tutorial-psn-bypass-techniques-and-setting-up-development-debugging-environment.13287/#post-78128 


#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "ps3api.h"
#include "core.h"
#include <stdio.h>
#include <stdint.h>



using namespace std;


void Connect()
{
	SNPS3InitTargetComms();
	SNPS3Connect(0, 0);
}

void GetProcessList()
{
	SNPS3ProcessList(0, &puCount, 0);
	puBuffer = (uint32_t*)malloc(puCount * 4);
	SNPS3ProcessList(0, &puCount, puBuffer);

}

void Attach()
{
	SNPS3ProcessAttach(0, 0, puBuffer[0]);
}

void Continue()
{
	SNPS3ProcessContinue(0, puBuffer[0]);
}


void ReadMemory(uint32_t offset, uint32_t length)
{
	address32 = offset;
	uint32_t results[65536];
	
	for ( int i = 0; i < length; i++ ) {

		address32 = address32 + i;
		uint32_t result = SNPS3ProcessGetMemory(0, 0, puBuffer[0], 0, address32, length, &readBytes);
	
		results[i] = (uint32_t)readBytes;

		if (i == length - 1)
		{
			cout << "Address: " << hex << address32 << " / Hex Offset: " << hex << address32 - 0x10000 << " / Instruction: " << hex << results[0] << results[1] << results[2] << results[3] << "\n\n";
		}
    }

}

void WriteMemory()
{
	SNPS3ProcessSetMemory(0, 0, puBuffer[0], 0, address32, 4, nop);
}


int main(int argc, char** argv)
{

	Connect();

	GetProcessList();

	Attach();

	Continue();
	
	//cout << "Enter Offset and Press ENTER:\n\n";
	//address32 = cin.get();
	
	//cout << "Enter Number of Bytes To Display and Press ENTER:\n\n";
	//bytes32 = cin.get();
	
	//ReadMemory(address32, bytes32);
	ReadMemory((int)0x0006F530, 4);

	printf("\nPS3 NoPSN Memory Patcher Test\n\nCompatible With v3.01\n\nNPEB01229\nNPJB00286\nNPUP10028\n\n\nMake Sure YouTube Is Running On PS3 and Press ENTER\n");
	cin.ignore();

	WriteMemory();
	
	free(puBuffer);

	return 0;
}