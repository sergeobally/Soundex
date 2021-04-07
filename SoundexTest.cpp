#include "pch.h"
#include "Soundex.h"
using namespace testing;


class SoundexEncoding : public ::testing::Test
{
public:
	Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) 
{
	ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsithZeroEnsureThreeDigits)
{
	ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

// rule #2 (“replace consonants with digits after the first letter”)
TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
	ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}
TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
	ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
	ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}
TEST_F(SoundexEncoding, EmptyCode) {
	ASSERT_THAT(soundex.encode(""), Eq(""));
}