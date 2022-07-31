// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <windows.h>
#include "CommonUsings.h"

#include "CommonTxtExtractor.h"

#define EOF (-1)

#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif

    __declspec(dllexport) PluginErrorType __cdecl ReadFileFull(IN std::wstring fullPath, OUT std::shared_ptr<std::wstring> str)
    {
        try
        {
            cmn::CommonTxtExtractor extractor;

            if(extractor.OpenStream(L"S:\\Programming\\github\\TextParser\\Source\\1.txt"))
            	extractor.Extract(*str.get());
        }
        catch (...)
        {
            return PluginErrorType::UnsuccessfulOperation;
        }

        return PluginErrorType::SuccessOperation;
    }

    __declspec(dllexport) PluginErrorType __cdecl GetFileTextSize(IN std::wstring fullPath, OUT unsigned long long& bytes)
    {
        try
        {
            bytes = 123456789;
        }
        catch (...)
        {
            return PluginErrorType::UnsuccessfulOperation;
        }

        return PluginErrorType::SuccessOperation;
    }

#ifdef __cplusplus
}
#endif
