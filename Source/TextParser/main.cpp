#include <iostream>
#include <windows.h> 
#include <stdio.h> 

#include "CommonUsingsAndDefines.h"
#include "CommonParser.h"
#include <map>

using MYPROC = int(__cdecl*)();

int f()
{
    HINSTANCE hinstLib;
    MYPROC ProcAdd;
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

    // Get a handle to the DLL module.

    hinstLib = LoadLibrary(TEXT("TXTExtractorPlugin.dll"));

    // If the handle is valid, try to get the function address.

    if (hinstLib != NULL)
    {
        ProcAdd = (MYPROC)GetProcAddress(hinstLib, "myPuts");

        // If the function address is valid, call the function.
        if (NULL != ProcAdd)
        {
            fRunTimeLinkSuccess = TRUE;
            (ProcAdd)();
        }

        // Free the DLL module.
        fFreeResult = FreeLibrary(hinstLib);
    }

    // If unable to call the DLL function, use an alternative.
    if (!fRunTimeLinkSuccess)
        printf("Message printed from executable\n");

    return 0;
}

int main()
{
	//--------------- main.cpp initialization ---------------//
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//--------------- main.cpp initialization ---------------//


    f();

	//MapContainerW map;
	//cmn::CommonTxtExtractor<std::wstring> extractor;
    //std::wstring str;

	//if(extractor.OpenStream(L"S:\\Programming\\github\\TextParser\\Source\\1.txt"))
	//	extractor.Extract(str);

	//cmn::CommonParser<std::wstring>::ParseWords(str, map);

	//for (const auto& elem: map)
	//{
	//	std::wcout << elem.first << ": " << elem.second << std::endl;
	//}

	return 0;
}