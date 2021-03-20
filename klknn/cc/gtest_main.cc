// Main entory point for gtest with glog and gflags.
#include "gtest/gtest.h"
#include "absl/flags/flag.h"
#include "absl/flags/declare.h"

#include "klknn/cc/base.h"

ABSL_DECLARE_FLAG(bool, logtostderr);

int main(int argc, char **argv) {
  // Enable stderr logging by default.
  absl::SetFlag(&FLAGS_logtostderr, true);
  klknn::InitMain(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
