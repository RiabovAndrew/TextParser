#pragma once

#include "pch.h"
#include <map>
#include <string>

#include "IPluginInterface.h"
#include "HInstanceGuard.h"

class PluginManager
{
public:
	PluginManager() {}

	void AddPlugin(std::unique_ptr<IPluginInterface>&& pPlugin, const std::wstring& pluginName, std::unique_ptr<HInstanceGuard>&& pGuard)
	{
		this->m_pluginsMap.emplace(pluginName, std::move(pPlugin));
		this->m_pluginGuardsMap.emplace(pluginName, std::move(pGuard));
	}

	void DeletePlugin(const std::wstring& pluginName)
	{
		this->m_pluginsMap.erase(pluginName);
		this->m_pluginGuardsMap.erase(pluginName);
	}

	auto GetPlugin(const std::wstring& pluginName)
	{
		auto pluginIt = this->m_pluginsMap.find(pluginName);
		if (pluginIt == this->m_pluginsMap.end())
			return static_cast<decltype(pluginIt->second.get())>(nullptr);
		return pluginIt->second.get();
	}

private:
	// map<path, plugin>;
	std::map<std::wstring, std::unique_ptr<IPluginInterface>> m_pluginsMap;
	std::map<std::wstring, std::unique_ptr<HInstanceGuard>> m_pluginGuardsMap;
};


