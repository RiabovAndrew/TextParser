#pragma once

#include <iostream>
#include <string>

std::wstring GetFileExtension(const std::wstring& path)
{
	return path.substr(path.find_last_of('.') + 1);
}

std::vector<std::string> ParseStringIntoArgv(const std::string& str)
{
    std::vector<std::string> res{ "" };

    char c = ' ';

    auto start = 0U;
    auto end = str.find(c);
    while (end != std::string::npos)
    {
        res.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(c, start);
    }
    res.push_back(str.substr(start, end));

    return res;
}
