#pragma once

#include <string>
#include <memory>
#include <map>

template<typename StrType = std::string>
struct StrDataContainer
{
	StrDataContainer() {}

	explicit StrDataContainer(const StrType& str)
	{
		this->m_str = str;
	}

	StrType m_str;
	std::map<StrType, unsigned> m_map;
};
