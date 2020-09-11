#include <gtest/gtest.h>
#include "Magic.hpp"

TEST(Magic, get) {
    Magic magic;
    ASSERT_EQ(magic.get(), 7);
}