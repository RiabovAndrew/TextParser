#pragma once

#include <string>
#include <memory>

class IExtractor
{
public:
	virtual ~IExtractor() = default;
	virtual bool OpenStream(const std::wstring&) = 0;
	virtual void CloseStream() = 0;
	virtual void Extract(std::wstring&) = 0;
};

