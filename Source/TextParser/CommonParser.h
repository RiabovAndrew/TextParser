#pragma once

#include <string>
#include <sstream>
#include <map>

namespace cmn
{
	template<typename StrType>
	class CommonParser
	{
		using CharType = typename StrType::value_type;

	public:

		static void ParseWords(const StrType& str, std::map<StrType, unsigned long long>& map)
		{
			std::basic_istringstream<CharType> stream(str);

			auto first = std::istream_iterator<StrType, CharType>(stream);
			auto last = std::istream_iterator<StrType, CharType>();
			for (; first != last; ++first)
			{
				auto word = map.find(*first);
				if (word == map.end())
				{
					map.emplace(*first, 1u);
				}
				else
				{
					++(word->second);
				}
			}
		}
	};
}


