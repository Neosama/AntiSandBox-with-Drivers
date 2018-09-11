
#include <iostream>

#include <Windows.h>
#include <iphlpapi.h>

#include <windows.h>
#include <psapi.h>
#include <tchar.h>
#include <stdio.h>

#pragma comment(lib, "IPHLPAPI.lib")

#include "lib.h"

int main()
{
	printf("SCORE = %i\n", AntiSandbox_Drivers());

	getchar();
	return 0;
}
