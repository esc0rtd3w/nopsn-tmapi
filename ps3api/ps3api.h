#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdint.h>

HINSTANCE hlib = LoadLibrary("ps3tmapi.dll");
typedef int HTARGET;

typedef long (*SNPS3AddTarget_t)(const char*, const char*, uint32_t, unsigned char*, HTARGET*);
typedef long (*SNPS3BDEject_t)(HTARGET, const char*);
typedef long (*SNPS3BDFormat_t)(HTARGET, const char*, uint32_t);
typedef long (*SNPS3BDInsert_t)(HTARGET, const char*);
typedef long (*SNPS3InitTargetComms_t)(void);
typedef long (*SNPS3Connect_t)(int, const char*);
typedef long (*SNPS3ProcessList_t)(int, uint32_t*, uint32_t*);
typedef long (*SNPS3ProcessAttach_t)(int, uint32_t, uint32_t);
typedef long (*SNPS3ProcessContinue_t)(int, uint32_t);
typedef long (*SNPS3ProcessGetMemory_t)(int, uint32_t, uint32_t, uint64_t, uint64_t, int, unsigned char*);
typedef long (*SNPS3ProcessSetMemory_t)(int, uint32_t, uint32_t, uint64_t, uint64_t, int, const unsigned char*);


SNPS3AddTarget_t SNPS3AddTarget = (SNPS3AddTarget_t)GetProcAddress(hlib, "SNPS3AddTarget");
SNPS3BDEject_t SNPS3BDEject = (SNPS3BDEject_t)GetProcAddress(hlib, "SNPS3BDEject");
SNPS3BDFormat_t SNPS3BDFormat = (SNPS3BDFormat_t)GetProcAddress(hlib, "SNPS3BDFormat");
SNPS3BDInsert_t SNPS3BDInsert = (SNPS3BDInsert_t)GetProcAddress(hlib, "SNPS3BDInsert");
SNPS3Connect_t SNPS3Connect = (SNPS3Connect_t)GetProcAddress(hlib, "SNPS3Connect");
SNPS3InitTargetComms_t SNPS3InitTargetComms = (SNPS3InitTargetComms_t)GetProcAddress(hlib, "SNPS3InitTargetComms");
SNPS3ProcessList_t SNPS3ProcessList = (SNPS3ProcessList_t)GetProcAddress(hlib, "SNPS3ProcessList");
SNPS3ProcessAttach_t SNPS3ProcessAttach = (SNPS3ProcessAttach_t)GetProcAddress(hlib, "SNPS3ProcessAttach");
SNPS3ProcessContinue_t SNPS3ProcessContinue = (SNPS3ProcessContinue_t)GetProcAddress(hlib, "SNPS3ProcessContinue");
SNPS3ProcessGetMemory_t SNPS3ProcessGetMemory = (SNPS3ProcessGetMemory_t)GetProcAddress(hlib, "SNPS3ProcessGetMemory");
SNPS3ProcessSetMemory_t SNPS3ProcessSetMemory = (SNPS3ProcessSetMemory_t)GetProcAddress(hlib, "SNPS3ProcessSetMemory");




