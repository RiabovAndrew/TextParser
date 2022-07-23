// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <windows.h>
#include "CommonUsings.h"

#define EOF (-1)

#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif

    __declspec(dllexport) PluginErrorType __cdecl Func()
    {

        return PluginErrorType::SuccessOperation;
    }

#ifdef __cplusplus
}
#endif
