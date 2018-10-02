// AFKtion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdint.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdio>

//#using <mscorlib.dll>
//#using <System.dll>

//using namespace System;
//using namespace System::Diagnostics;
//using namespace System::ComponentModel;

int main(int argc, char *argv[])
{
	/*std::cout <<argv[1] << std::endl;*/
	//char process[100];


	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	//std::cout << "Enter the process name: ";
	//std::cin >> process;


	if (Process32First(snapshot, &entry) == TRUE) {
		while (Process32Next(snapshot, &entry) == TRUE) {
			if (_stricmp((char *)entry.szExeFile, argv[1]) == 0) {
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
				std::cout << entry.szExeFile << std::endl;
				CloseHandle(hProcess);
			}
			else
			{
				std::cout << entry.szExeFile << std::endl;

			}
		}
	}

	CloseHandle(snapshot);

	//HINSTANCE huserModule = LoadLibrary(L"User32.dll");
	//if (huserModule == NULL)
	//{
	//	std::cout << "Fatal: huserModule couldn't loaded!" << std::endl;
	//}
	//else
	//{
	//	std::cout << "Successful: huserModule loaded!" << std::endl;
	//}



	return 0;
}

