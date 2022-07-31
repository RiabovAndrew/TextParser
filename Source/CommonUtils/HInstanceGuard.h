#pragma once

#include <iostream>
#include <windows.h> 
#include <stdio.h>

class HInstanceGuard
{
public:

	HInstanceGuard(const HInstanceGuard&) = delete;

	HInstanceGuard(HINSTANCE hInstance) : m_hInstance(hInstance) {}

	~HInstanceGuard()
	{
		if(this->m_hInstance != nullptr)
			FreeLibrary(this->m_hInstance);
	}

	HINSTANCE release()
	{
		auto temp = this->m_hInstance;
		this->m_hInstance = nullptr;

		return temp;
	}

	const HINSTANCE get() const
	{
		return m_hInstance;
	}

private:
	HINSTANCE m_hInstance;
};