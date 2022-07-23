#include <iostream>
#include <windows.h>

#include "CommonUsings.h"
#include "CommonTxtExtractor.h"
#include "CommonParser.h"
#include <map>



int main()
{
	//--------------- main.cpp initialization ---------------//
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//--------------- main.cpp initialization ---------------//

	MapContainerType map;
	cmn::CommonTxtExtractor<StrType> extractor;
	StrType str;

	if(extractor.OpenStream(L"S:\\Programming\\github\\TextParser\\Source\\1.txt"))
		extractor.Extract(str);

	cmn::CommonParser<StrType>::ParseWords(str, map);

	for (const auto& elem: map)
	{
		std::wcout << elem.first << ": " << elem.second << std::endl;
	}

	return 0;
}