// Main entory point for gtest with glog and gflags.
#include <gtest/gtest.h>
#include <gflags/gflags.h>

#include "klknn/cc/base.h"

DECLARE_bool(logtostderr); // used in glog

int main(int argc, char **argv) {
  // Enable stderr logging by default.
  FLAGS_logtostderr = true;
  klknn::InitMain(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
