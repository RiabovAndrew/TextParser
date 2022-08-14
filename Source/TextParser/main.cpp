#include "argparse/argparse.hpp"
#include <iostream>
#include <windows.h> 
#include <stdio.h> 
#include <map>

#include "CommonUsingsAndDefines.h"
#include "CommonParser.h"
#include "Plugin.h"
#include "PluginManager.h"
#include "StringUtils.h"

void Load(PluginManager& pluginManager, const std::wstring& name)
{
	// Get a handle to the DLL module
	HINSTANCE hinstLib = LoadLibraryW(name.c_str());
	auto guard(std::make_unique<HInstanceGuard>(hinstLib));

	// If the handle is valid, try to get the function address
	if (hinstLib == nullptr)
		throw std::runtime_error(__FUNCTION__ ": Handle is not valid");

	auto readFileFullFunc = reinterpret_cast<ReadFileFullFunc>(GetProcAddress(guard->get(), "ReadFileFull"));
	if (readFileFullFunc == nullptr)
		throw std::runtime_error(__FUNCTION__ ": ReadFileFullFunc was not loaded");

	auto getFileTextSizeFunc = reinterpret_cast<GetFileTextSizeFunc>(GetProcAddress(guard->get(), "GetFileTextSize"));
	if (readFileFullFunc == nullptr)
		throw std::runtime_error(__FUNCTION__ ": GetFileTextSizeFunc was not loaded");

	auto plugin = std::make_unique<Plugin>(readFileFullFunc, getFileTextSizeFunc);
	pluginManager.AddPlugin(std::move(plugin), name, std::move(guard));
}

void DispatchException(pm::PluginErrorType error)
{
	if (error == pm::PluginErrorType::UnsuccessfulOperation)
	{
		throw std::runtime_error(__FUNCTION__ ": pm::PluginErrorType::UnsuccessfulOperation");
	}
}

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	argparse::ArgumentParser program("TextParser.exe");
	program.add_argument("-p", "--FullFilePath")
		.help("specify the path to file you going to read from.")
		.required();

	PluginManager pluginManager;

	try
	{
		program.parse_args(argc, argv);
		auto path = program.get<std::string>("-p");
		std::wstring wpath(path.cbegin(), path.cend());

		if (GetFileExtension(wpath) == L"txt")
		{
			// Let's load plugin.
			auto plugin = pluginManager.GetPlugin(L"TXTReadPlugin.dll");
			if (!plugin)
				Load(pluginManager, L"TXTReadPlugin.dll");
				plugin = pluginManager.GetPlugin(L"TXTReadPlugin.dll");

			// Just do some stuff to show how parse works.
			unsigned long long bytes = 0;
			auto res = plugin->GetFileTextSize(wpath, bytes);
			DispatchException(res);

			std::wcout << "File size: " << bytes << std::endl << std::endl;

			auto str = std::make_shared<std::wstring>();
			res = plugin->ReadFileFull(wpath, str);
			DispatchException(res);

			MapContainerW map;
			cmn::CommonParser::ParseWords(*str.get(), map);
			for (const auto& elem : map)
			{
				std::wcout << elem.first << ": " << elem.second << std::endl;
			}
		}
		else
		{
			std::wcout << "These is no appropriative plugin for this type of file" << std::endl;
		}
	}
	catch (const std::runtime_error& e)
	{
		std::wcout << e.what() << std::endl;
	}
	catch (...)
	{
		std::wcout << "Unrecognized exception" << std::endl;
	}

	return 0;
}