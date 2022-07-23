#pragma once

#include "CommonUsings.h"
#include <iostream>

template<typename StrType>
class IPluginInterface
{
public:
	virtual ~IPluginInterface() {}
	virtual pm::PluginError ReadFileFull(IN std::wstring fullPath, OUT std::shared_ptr<StrType> str);
	virtual pm::PluginError ReadFile(IN std::wstring fullPath, IN size_t bytes, OUT std::shared_ptr<StrType> str);
	virtual pm::PluginError GetFileTextsize(IN std::wstring fullPath, OUT size_t bytes);
};