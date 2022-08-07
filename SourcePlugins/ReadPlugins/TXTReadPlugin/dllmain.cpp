// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <windows.h>
#include "CommonUsings.h"

#include "CommonTxtExtractor.h"

#define EOF (-1)

#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif

    __declspec(dllexport) PluginErrorType __cdecl ReadFileFull(IN const std::wstring& fullPath, OUT std::shared_ptr<std::wstring> str)
    {
        try
        {
            cmn::CommonTxtExtractor extractor;

            if(extractor.OpenStream(fullPath))
            	extractor.Extract(*str.get());
            else
                return PluginErrorType::UnsuccessfulOperation;
        }
        catch (...)
        {
            return PluginErrorType::UnsuccessfulOperation;
        }

        return PluginErrorType::SuccessOperation;
    }

    __declspec(dllexport) PluginErrorType __cdecl GetFileTextSize(IN const std::wstring& fullPath, OUT unsigned long long& bytes)
    {
        try
        {
            cmn::CommonTxtExtractor extractor;

            if (extractor.OpenStream(fullPath))
                bytes = extractor.GetFileSize();
            else
                return PluginErrorType::UnsuccessfulOperation;
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
