#pragma once
#include <string>
#include <memory>
#include <map>

struct WStrDataContainer
{
	WStrDataContainer()
	{
		m_wstr.reset(new std::wstring);
	}

	explicit WStrDataContainer(const std::wstring& str)
	{
		m_wstr.reset(new std::wstring(str));
	}

	std::unique_ptr<std::wstring> m_wstr;
	std::map<std::wstring, unsigned> m_map;
};
