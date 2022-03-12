#pragma once
#include <string>
#include <memory>

template<typename StrType = std::string>
class Extractor
{
public:
	virtual ~Extractor() {};
	virtual void OpenFile(const std::string&) = 0;
	virtual void OpenFile(const std::wstring&) = 0;
	virtual void ExtractFull(StrType&) = 0;
};

