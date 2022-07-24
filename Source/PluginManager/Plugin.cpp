#include "pch.h"
#include "Plugin.h"

template<typename StrType>
inline pm::PluginErrorType Plugin<StrType>::ReadFileFull(IN std::wstring fullPath, OUT std::shared_ptr<StrType> str)
{
	return pm::PluginErrorType::UnsuccessfulOperation;
}

template<typename StrType>
pm::PluginErrorType Plugin<StrType>::GetFileTextSize(IN std::wstring fullPath, OUT size_t bytes)
{
	return pm::PluginErrorType::UnsuccessfulOperation;
}