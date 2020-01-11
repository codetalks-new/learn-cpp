#include <gmock/gmock.h>
#include "Soundex.hpp"

using testing::Eq;

class SoundexEncoding : public testing::Test {
 public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, CombinesDuplicateEncodingsSeparateByVowels) {
  ASSERT_THAT(soundex.encode("Jbob"), Eq("J110"));
}
TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
  ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));
  ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));
  ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));
  ASSERT_THAT(soundex.encode("Abfcdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourChars) {
  ASSERT_THAT(soundex.encode("Acdlb").length(), Eq(4));
}
TEST_F(SoundexEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicates1st) {
  ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}
TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants) {
  ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}
TEST_F(SoundexEncoding, IngoresVowelLikeLetters) {
  ASSERT_THAT(soundex.encode("Baeiouhycdl"), Eq("B234"));
}
TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
  ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
}
TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits) {
  ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}
TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
  EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
  EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
  EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
  EXPECT_THAT(soundex.encode("Ax"), Eq("A200"));
  EXPECT_THAT(soundex.encode("Al"), Eq("A400"));
  EXPECT_THAT(soundex.encode("Am"), Eq("A500"));
  EXPECT_THAT(soundex.encode("An"), Eq("A500"));
  EXPECT_THAT(soundex.encode("Ar"), Eq("A600"));
}
TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
  ASSERT_THAT(soundex.encode("a"), Eq("A000"));
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}