#pragma once

#include <windows.h> 
#include <stdio.h>

#include "IPluginInterface.h"

class Plugin : public IPluginInterface
{
public:
	Plugin() = delete;

	Plugin(
		ReadFileFullFunc readFileFunc,
		GetFileTextSizeFunc getFileTextSizeFunc) :
		m_readFileFunc(readFileFunc), 
		m_getFileTextFunc(getFileTextSizeFunc) {}

	virtual ~Plugin() = default;

	pm::PluginErrorType ReadFileFull(IN const std::wstring& fullPath, OUT std::shared_ptr<std::wstring> str) override
	{
		pm::PluginErrorType res = pm::PluginErrorType::UnsuccessfulOperation;

		try
		{
			res = static_cast<pm::PluginErrorType>((m_readFileFunc)(fullPath, str));
		}
		catch (...)
		{
			return pm::PluginErrorType::UnsuccessfulOperation;
		}

		return res;
	}

	pm::PluginErrorType GetFileTextSize(IN const std::wstring& fullPath, OUT unsigned long long& bytes) override
	{
		pm::PluginErrorType res = pm::PluginErrorType::UnsuccessfulOperation;

		try
		{
			res = static_cast<pm::PluginErrorType>((m_getFileTextFunc)(fullPath, bytes));
		}
		catch (...)
		{
			return pm::PluginErrorType::UnsuccessfulOperation;
		}

		return res;
	}

private:
	ReadFileFullFunc m_readFileFunc;
	GetFileTextSizeFunc m_getFileTextFunc;
};

