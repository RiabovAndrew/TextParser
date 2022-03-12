#pragma once
#include "Extractor.h"
#include <string>
#include <fstream>

template<typename CharType, typename StrType>
class CommonTxtExtractor : public Extractor<StrType>
{
public:
	CommonTxtExtractor() {}

	explicit CommonTxtExtractor(const StrType& path)
	{
		OpenFile(path);
	}

	~CommonTxtExtractor() {};

	void OpenFile(const StrType& path) override
	{
		if (!this->m_fin.is_open())
		{
			this->m_fin.open(path);
		}
	}

	void ExtractFull(StrType& str) override
	{
		if (this->m_fin.is_open())
		{
			this->m_fin.seekg(0, std::ios::end);
			str.reserve(this->m_fin.tellg());
			this->m_fin.seekg(0, std::ios::beg);

			str.append(
				std::istreambuf_iterator<CharType>(this->m_fin),
				std::istreambuf_iterator<CharType>()
			);
		}
	}

private:
	std::basic_ifstream<CharType, std::char_traits<CharType>> m_fin;
};

