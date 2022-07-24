#pragma once

#include "IPluginInterface.h"

template<typename StrType>
class Plugin : public IPluginInterface<StrType>
{
public:
	Plugin() = default;

	Plugin(
		const std::wstring& path,
		ReadFileFullFunc<StrType> readFileFunc,
		GetFileTextSizeFunc<StrType> getFileTextSizeFunc) :
		m_path(path), m_readFileFunc(readFileFunc), m_getFileTextFunc(getFileTextSizeFunc) {}

	~Plugin() = default;

	pm::PluginErrorType ReadFileFull(IN std::wstring fullPath, OUT std::shared_ptr<StrType> str) override
	{
		return pm::PluginErrorType::UnsuccessfulOperation;
	}

	pm::PluginErrorType GetFileTextSize(IN std::wstring fullPath, OUT size_t bytes) override
	{
		return pm::PluginErrorType::UnsuccessfulOperation;
	}

private:
	std::wstring m_path;
	ReadFileFullFunc<StrType> m_readFileFunc;
	GetFileTextSizeFunc<StrType> m_getFileTextFunc;
};

