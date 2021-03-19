#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_join.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

#include "klknn/cc/base.h"

int main(int argc, char **argv) {
  klknn::InitMain(argc, argv);
  // gflags::ParseCommandLineFlags(&argc, &argv, true);
  // google::InitGoogleLogging(argv[0]);

  LOG(INFO) << "NOW LOGGING";
  std::vector<std::string> v = {"foo", "bar", "baz"};
  std::string s = absl::StrJoin(v, "-");
  std::cout << "Joined string: " << s << "\n";
  return 0;
}
