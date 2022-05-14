#pragma once

#include <string>
#include <memory>
#include <map>

template<typename StrType = std::string>
struct StrDataContainer
{
	StrDataContainer() {}

	explicit StrDataContainer(const StrType& str) : m_str(str) {}

	StrDataContainer(const StrDataContainer& other)
	{
		this->m_str = other.m_str;
		this->m_map = other.m_map;
	}

	StrDataContainer& operator=(const StrDataContainer& other)
	{
		StrDataContainer res;

		res.m_str = other.m_str;
		res.m_map = other.m_map;

		return res;
	}

	StrType m_str;
	std::map<StrType, unsigned> m_map;
};
