#pragma once

#include <string>
#include <map>

using MapContainer = std::map<std::string, unsigned long long>;
using MapContainerW = std::map<std::wstring, unsigned long long>;

#define OUT
#define IN

namespace pm
{
	using PluginError = unsigned;

	enum class PluginErrorType : PluginError
	{
		SuccessOperation = 0,
		UnsuccessfulOperation = 1
	};

}