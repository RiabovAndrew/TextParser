#include "gtest/gtest.h"
#include "CommonParser.h"


TEST(TestCommonParser, Empty)
{
    std::wstring str;
    std::map<std::wstring, unsigned long long> map;
    std::map<std::wstring, unsigned long long> map2;
    cmn::CommonParser::ParseWords(str, map2);
    EXPECT_EQ(map, map2);
}

TEST(TestCommonParser, Easy)
{
    std::wstring str(L"1 2 11\n 1 1-1 ");
    std::map<std::wstring, unsigned long long> map{
        {L"1", 2}, {L"2", 1}, {L"11", 1}, {L"1-1", 1}
    };
    std::map<std::wstring, unsigned long long> map2;
    cmn::CommonParser::ParseWords(str, map2);
    EXPECT_EQ(map, map2);
}

