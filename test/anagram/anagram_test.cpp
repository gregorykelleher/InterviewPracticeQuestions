#include <gtest/gtest.h>

#include "anagram.hpp"

TEST(ExtractWordsTest, HandlesEmptyString) {
    
    // Act
    auto const actual {extract_words("")};

    // Assert
    EXPECT_TRUE(actual.empty());
}

TEST(ExtractWordsTest, HandlesSingleWord) {

    // Arrange
    std::vector<std::string> const expected{"abc"};

    // Act
    auto const actual {extract_words("cab")};

    // Assert
    EXPECT_EQ(actual, expected);
}

TEST(ExtractWordsTest, HandlesMultipleWords) {

    // Arrange
    std::vector<std::string> const expected{"abc", "efh", "ikl"};

    // Act
    auto const actual{extract_words("cab hef kil")};

    // Assert
    EXPECT_EQ(actual, expected);
}

TEST(ExtractWordsTest, HandlesRepeatedLetters) {

    // Arrange
    std::vector<std::string> const expected{"aabb", "ccdd"};

    // Act
    auto const actual{extract_words("abab cdcd")};

    // Assert
    EXPECT_EQ(actual, expected);
}

TEST(FindAnagramTest, HandlesEmptyInputs) {

    // Arrange
    std::vector<std::string> const word_vec{};

    // Act
    auto const actual{findAnagram("", word_vec)};

    // Assert
    EXPECT_TRUE(actual.empty());
}

TEST(FindAnagramTest, NoAnagramsInEmptyVector) {

    // Arrange
    std::vector<std::string> const word_vec{};

    // Act
    auto const actual{findAnagram("test", word_vec)};

    // Assert
    EXPECT_TRUE(actual.empty());
}

TEST(FindAnagramTest, NoAnagramsInVector) {

    // Arrange
    std::vector<std::string> const word_vec{"abcd", "efgh", "ijkl"};

    // Act
    auto const actual {findAnagram("mnop", word_vec)};

    // Assert
    EXPECT_TRUE(actual.empty());
}

TEST(FindAnagramTest, OneAnagramInVector) {

    // Arrange
    std::vector<std::string> const word_vec{"abcd", "dcba", "ijkl"};

    // Act
    auto const actual {findAnagram("dcba", word_vec)};

    // Assert
    std::vector<std::string> const expected{"dcba"};
    EXPECT_EQ(actual, expected);
}
