#pragma once

using PluginError = unsigned;

enum class PluginErrorType : PluginError
{
	SuccessOperation = 0,
	UnsuccessfulOperation = 1
};