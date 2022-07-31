#include <iostream>
#include <windows.h> 
#include <stdio.h> 
#include <map>

#include "CommonUsingsAndDefines.h"
#include "CommonParser.h"
#include "Plugin.h"
#include "PluginManager.h"

void Load(PluginManager& pluginManager, const std::wstring& name)
{
	// Get a handle to the DLL module
	HINSTANCE hinstLib = LoadLibraryW(name.c_str());
	auto guard(std::make_unique<HInstanceGuard>(hinstLib));

	// If the handle is valid, try to get the function address
	if (hinstLib == nullptr)
		throw std::runtime_error("Handle is not valid");

	auto readFileFullFunc = reinterpret_cast<ReadFileFullFunc>(GetProcAddress(guard->get(), "ReadFileFull"));
	if (readFileFullFunc == nullptr)
		throw std::runtime_error("ReadFileFullFunc was not loaded");

	auto getFileTextSizeFunc = reinterpret_cast<GetFileTextSizeFunc>(GetProcAddress(guard->get(), "GetFileTextSize"));
	if (readFileFullFunc == nullptr)
		throw std::runtime_error("GetFileTextSizeFunc was not loaded");

	auto plugin = std::make_unique<Plugin>(readFileFullFunc, getFileTextSizeFunc);
	pluginManager.AddPlugin(std::move(plugin), name, std::move(guard));
}

void DispatchException(pm::PluginErrorType error)
{
	if (error == pm::PluginErrorType::UnsuccessfulOperation)
	{
		throw std::runtime_error("pm::PluginErrorType::UnsuccessfulOperation");
	}
}

int main()
{
	//--------------- main.cpp initialization ---------------//
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//--------------- main.cpp initialization ---------------//

	PluginManager pluginManager;
	Load(pluginManager, L"TXTReadPlugin.dll");

	auto plugin = pluginManager.GetPlugin(L"TXTReadPlugin.dll");
	unsigned long long bytes = 0;
	auto res = plugin->GetFileTextSize(L"S:\\Programming\\github\\TextParser\\Source\\1.txt", bytes);
	DispatchException(res);

	auto str = std::make_shared<std::wstring>();
	res = plugin->ReadFileFull(L"S:\\Programming\\github\\TextParser\\Source\\1.txt", str);
	DispatchException(res);

	MapContainerW map;
	cmn::CommonParser::ParseWords(*str.get(), map);
	for (const auto& elem: map)
	{
		std::wcout << elem.first << ": " << elem.second << std::endl;
	}

	return 0;
}