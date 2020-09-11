#include "Magic.hpp"

#include <gtest/gtest.h>

TEST(Magic, get) {
    Magic magic;
    ASSERT_EQ(magic.get(), 7);
}