#pragma once

#include <string>
#include <memory>

template<typename StrType>
class IExtractor
{
public:
	virtual ~IExtractor() = default;
	virtual bool OpenStream(const StrType&) = 0;
	virtual void CloseStream() = 0;
	virtual void Extract(StrType&) = 0;
};

