#include <iostream>
#include <windows.h>

#include "WTxtExtractor.h"
#include "WStrDataContainer.h"

int main()
{
	//--------------- main.cpp initialization ---------------//
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//--------------- main.cpp initialization ---------------//

	std::wstring str;

	WTxtExtractor extractor;
	extractor.OpenFile(L"P:\\C++\\TextParser\\1.txt");
	extractor.ExtractFull(str);

	WStrDataContainer dataContainer(str);

	std::wcout << *dataContainer.m_wstr << std::endl;

	system("pause");
	return 0;
}