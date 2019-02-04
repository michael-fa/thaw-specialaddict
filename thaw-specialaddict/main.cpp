#include <windows.h>

//Taken from thmp/utils.cpp - Thanks to th-mp!
void UnFuck(DWORD addr, int size)
{
	DWORD d;
	VirtualProtect((PVOID)addr, size, PAGE_EXECUTE_READWRITE, &d);
}




BOOL WINAPI DllMain(HINSTANCE module_handle, DWORD reason_for_call, LPVOID reserved)
{
	if (reason_for_call == DLL_PROCESS_ATTACH)
	{
		UnFuck(0x56BEE3, 3);
		memset((LPVOID)0x56BEE3, 0x90, 3);

		UnFuck(0x56CE06, 3);
		memset((LPVOID)0x56CE06, 0x90, 3);
	}
	if (reason_for_call == DLL_PROCESS_DETACH)
	{
	}
}
