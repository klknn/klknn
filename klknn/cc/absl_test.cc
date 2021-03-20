// https://google.github.io/googletest/primer.html
#include "gtest/gtest.h"

#include "klknn/cc/log.h"

namespace klknn {
namespace {

class QueueTest : public ::testing::Test {
 protected:
  void SetUp() override {
    _size = 0;
  }

  void TearDown() override {
  }

  int _size = 1;
};

TEST_F(QueueTest, IsEmptyInitially) {
  EXPECT_EQ(_size, 0);
}


TEST(HelloTest, GetGreet) {
  LOG_INFO << "NOW TESTING!";
  EXPECT_EQ(1 + 1, 2);
}

}  // namespace
}  // namespace klknn
