#include <iostream>
#include <windows.h>

#include "CommonTxtExtractor.h"
#include "StrDataContainer.h"
#include "CommonParser.h"

using CommonParser = cmn::CommonParser<wchar_t, std::wstring>;

int main()
{
	//--------------- main.cpp initialization ---------------//
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//--------------- main.cpp initialization ---------------//

	StrDataContainer<std::wstring> dataContainer;
	cmn::CommonTxtExtractor<wchar_t, std::wstring> extractor;

	if(extractor.OpenStream(L"D:\\github\\TextParser\\Source\\1.txt"))
		extractor.ExtractFull(dataContainer);

	CommonParser::ParseWords(dataContainer);

	for (const auto &elem: dataContainer.m_map)
	{
		std::wcout << elem.first << ": " << elem.second << std::endl;
	}

	return 0;
}