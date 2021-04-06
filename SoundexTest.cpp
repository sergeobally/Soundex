#include "pch.h"
using namespace std;
using ::testing::Eq;

class Soundex 
{
public :
	string encode(const string& word) const
	{
		return word;
	}
};

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) 
{
	Soundex soundex;
	auto encoded = soundex.encode("A");
	ASSERT_THAT(encoded, Eq("A"));
}