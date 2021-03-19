#include <gtest/gtest.h>
#include <glog/logging.h>

TEST(HelloTest, GetGreet) {
  LOG(INFO) << "NOW TESTING!";
  EXPECT_EQ(1 + 1, 2);
}
