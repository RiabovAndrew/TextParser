#pragma once

#include "CommonUsingsAndDefines.h"
#include <iostream>

template<typename StrType>
using ReadFileFullFunc = pm::PluginError(__cdecl*)(IN std::wstring fullPath, OUT std::shared_ptr<StrType> str);
template<typename StrType>
using GetFileTextSizeFunc = pm::PluginError(__cdecl*)(IN std::wstring fullPath, OUT size_t bytes);


template<typename StrType>
class IPluginInterface
{
public:
	virtual ~IPluginInterface() {}
	virtual pm::PluginErrorType ReadFileFull(IN std::wstring fullPath, OUT std::shared_ptr<StrType> str);
	virtual pm::PluginErrorType GetFileTextSize(IN std::wstring fullPath, OUT size_t bytes);
};