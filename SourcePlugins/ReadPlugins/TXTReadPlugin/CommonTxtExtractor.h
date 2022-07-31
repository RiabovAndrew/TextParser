#pragma once

#include <string>
#include <fstream>

#include "Extractor.h"

namespace cmn
{
	class CommonTxtExtractor : public IExtractor
	{
		using CharType = typename std::wstring::value_type;

	public:
		CommonTxtExtractor() {}

		explicit CommonTxtExtractor(const std::wstring& path)
		{
			this->OpenStream(path);
		}

		~CommonTxtExtractor() 
		{
			this->CloseStream();
		}

		bool OpenStream(const std::wstring& path) override
		{
			if (!this->m_fin.is_open())
			{
				this->m_fin.open(path);
				return this->m_fin.is_open();
			}

			return false;
		}

		void CloseStream() override
		{
			if (this->m_fin.is_open())
			{
				this->m_fin.close();
			}
		}

		void Extract(std::wstring& str) override
		{
			str.clear();

			if (!this->m_fin.is_open())
			{
				throw std::runtime_error("Cannot extract data from file");
			}

			this->m_fin.seekg(0, std::ios::end);
			str.reserve(this->m_fin.tellg());
			this->m_fin.seekg(0, std::ios::beg);

			str.append(
				std::istreambuf_iterator<CharType>(this->m_fin),
				std::istreambuf_iterator<CharType>()
			);
		}

		unsigned long long GetFileSize()
		{
			if (!this->m_fin.is_open())
				throw std::runtime_error("Cannot get file size");

			this->m_fin.seekg(0, std::ios::end);
			return this->m_fin.tellg();
		}

	private:
		std::basic_ifstream<CharType> m_fin;
	};
}

