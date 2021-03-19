#include "gflags/gflags.h"
#include "glog/logging.h"

namespace klknn {

void InitMain(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
}

}
