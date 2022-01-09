#pragma once
#include <string>
#include <memory>

class Extractor
{
public:
	virtual ~Extractor() {};
	virtual void OpenFile(const std::string&) = 0;
	virtual void OpenFile(const std::wstring&) = 0;
	virtual void ExtractFull(std::wstring&) = 0;
};

