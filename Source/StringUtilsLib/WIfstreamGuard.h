#pragma once
#include <iostream>
#include <string>
#include <fstream>

namespace stream_gurd
{
	class WIfstreamGuard
	{
	public:
		WIfstreamGuard()
		{
			m_wfin = std::wifstream();
		}

		~WIfstreamGuard()
		{
			m_wfin.close();
		}

		operator std::wifstream* ()
		{
			return &m_wfin;
		}

	private:
		std::wifstream m_wfin;
	};
} // stream_gurd


