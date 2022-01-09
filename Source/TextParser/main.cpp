#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

#include "WTxtExtractor.h"
#include "WStrDataContainer.h"

int main()
{
	//--------------- main.cpp initialization ---------------//
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//--------------- main.cpp initialization ---------------//

	auto str = new std::wstring();
	std::unique_ptr<std::wstring> sPtr(str);


	WTxtExtractor extractor;
	extractor.OpenFile(L"P:\\C++\\TextParser\\1.txt");
	extractor.ExtractFull(sPtr);

	WStrDataContainer dataContainer(*sPtr);

	std::wcout << *dataContainer.m_wstr << std::endl;

	system("pause");
	return 0;
}