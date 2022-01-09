#pragma once
#include "Extractor.h"
#include "WIfstreamGuard.h"

class WTxtExtractor : public Extractor
{
public:
	WTxtExtractor() 
	{
		auto wfinGuard = new stream_gurd::WIfstreamGuard();
		m_wfin.reset(static_cast<std::wifstream*>(*wfinGuard));
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

