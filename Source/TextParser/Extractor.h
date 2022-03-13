#pragma once

#include <string>
#include <memory>

#include "StrDataContainer.h"

template<typename StrType = std::string>
class Extractor
{
public:
	virtual ~Extractor() = default;
	virtual bool OpenStream(const StrType&) = 0;
	virtual void CloseStream() = 0;
	virtual void ExtractFull(StrDataContainer<StrType>&) = 0;
};

