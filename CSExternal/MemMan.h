#pragma once

#include <Windows.h>
#include <vector>
#include <TlHelp32.h>
#include <d3d9.h>
#include <d3dx9.h>

class MemMan
{
public:
	MemMan();
	~MemMan();
	template <class val>
	val readMem(DWORD addr)
	{
		val x;
		ReadProcessMemory(handle, (LPBYTE*)addr, &x, sizeof(x), NULL);
		return x;
	}
	template <class dataType>
	void writeMem(DWORD addr, dataType x)
	{
		WriteProcessMemory(handle, (LPBYTE*)addr, &x, sizeof(x), NULL);
	}
	DWORD getProcess(const char*);
	uintptr_t getModule(DWORD, const char*);
	DWORD getAddress(DWORD, std::vector<DWORD>);
	HANDLE handle;
};
