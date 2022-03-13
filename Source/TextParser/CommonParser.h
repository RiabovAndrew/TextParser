#pragma once

#include <string>
#include <sstream>

#include "StrDataContainer.h"

namespace cmn
{
	template<typename CharType, typename StrType>
	class CommonParser
	{
	public:

		static void ParseWords(StrDataContainer<StrType>& container)
		{
			std::basic_istringstream<CharType> stream(container.m_str);

			auto first = std::istream_iterator<StrType, CharType>(stream);
			auto last = std::istream_iterator<StrType, CharType>();
			for (; first != last; ++first)
			{
				auto word = container.m_map.find(*first);
				if (word == container.m_map.end())
				{
					container.m_map.emplace(*first, 1u);
				}
				else
				{
					++(word->second);
				}
			}
		}
	};
}


