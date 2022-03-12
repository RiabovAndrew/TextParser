#pragma once
#include <string>
#include <memory>

template<typename StrType = std::string>
class Extractor
{
public:
	virtual ~Extractor() = default;
	virtual void OpenFile(const StrType&) = 0;
	virtual void ExtractFull(StrType&) = 0;
};

