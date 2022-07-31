#pragma once

#include <iostream>
#include "CommonUsingsAndDefines.h"

using ReadFileFullFunc = pm::PluginError(__cdecl*)(IN std::wstring fullPath, OUT std::shared_ptr<std::wstring> str);
using GetFileTextSizeFunc = pm::PluginError(__cdecl*)(IN std::wstring fullPath, OUT unsigned long long& bytes);

class IPluginInterface
{
public:
	virtual ~IPluginInterface() {}
	virtual pm::PluginErrorType ReadFileFull(IN std::wstring fullPath, OUT std::shared_ptr<std::wstring> str)
	{
		return pm::PluginErrorType::UnsuccessfulOperation;
	}

	virtual pm::PluginErrorType GetFileTextSize(IN std::wstring fullPath, OUT unsigned long long& bytes)
	{
		return pm::PluginErrorType::UnsuccessfulOperation;
	}
};
