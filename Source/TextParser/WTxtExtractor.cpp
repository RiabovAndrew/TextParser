#include "WTxtExtractor.h"

void WTxtExtractor::OpenFile(const std::string& path)
{
	if (!m_wfin->is_open())
	{
		m_wfin->open(path, std::ios::binary);
	}
	else
	{
		throw std::runtime_error("Stream was already opened!");
	}
}

void WTxtExtractor::OpenFile(const std::wstring& path)
{
	if (!m_wfin->is_open())
	{
		m_wfin->open(path, std::ios::binary);
	}
	else
	{
		throw std::runtime_error("Stream was already opened!");
	}
}

void WTxtExtractor::ExtractFull(std::wstring& str)
{
	if (m_wfin->is_open())
	{
		m_wfin->seekg(0, std::ios::end);
		str.reserve(m_wfin->tellg());
		m_wfin->seekg(0, std::ios::beg);

		str.assign(std::istreambuf_iterator<wchar_t>(*m_wfin), std::istreambuf_iterator<wchar_t>());
	}
	else
	{
		throw std::runtime_error("Stream was not opened!");
	}
}