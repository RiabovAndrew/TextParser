#include <iostream>
#include <windows.h>

#include "CommonTxtExtractor.h"
#include "StrDataContainer.h"

int main()
{
	//--------------- main.cpp initialization ---------------//
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//--------------- main.cpp initialization ---------------//

	StrDataContainer<std::wstring> dataContainer;
	CommonTxtExtractor<wchar_t, std::wstring> extractor;

	extractor.OpenFile(L"D:\\github\\TextParser\\Source\\1.txt");
	extractor.ExtractFull(dataContainer.m_wstr);

	std::wcout << dataContainer.m_wstr << std::endl;

	return 0;
}