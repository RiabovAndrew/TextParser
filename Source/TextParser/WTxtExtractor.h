#pragma once
#include "Extractor.h"
#include <string>
#include <fstream>

class WTxtExtractor : public Extractor
{
public:
	WTxtExtractor() 
	{
		m_wfin.reset(new std::wifstream());
	}

	explicit WTxtExtractor(const std::string& path) : WTxtExtractor()
	{
		OpenFile(path);
	}

	explicit WTxtExtractor(const std::wstring& path) : WTxtExtractor()
	{
		OpenFile(path);
	}

	~WTxtExtractor() {};

	void OpenFile(const std::string& path) override;
	void OpenFile(const std::wstring& path) override;
	void ExtractFull(std::wstring& str) override;

private:
	std::unique_ptr<std::wifstream> m_wfin;
};

