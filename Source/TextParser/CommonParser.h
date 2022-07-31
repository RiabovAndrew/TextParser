#pragma once

#include <string>
#include <sstream>
#include <map>

namespace cmn
{
	class CommonParser
	{
		using CharType = typename std::wstring::value_type;

	public:

		static void ParseWords(const std::wstring& str, std::map<std::wstring, unsigned long long>& map)
		{
			std::basic_istringstream<CharType> stream(str);

			auto first = std::istream_iterator<std::wstring, CharType>(stream);
			auto last = std::istream_iterator<std::wstring, CharType>();
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


