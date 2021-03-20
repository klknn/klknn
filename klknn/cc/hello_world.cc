// https://gflags.github.io/gflags/#define
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "absl/strings/str_join.h"
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "plog/Log.h"

#include "klknn/cc/base.h"

ABSL_FLAG(std::string, name, "", "Name to greet.");

int main(int argc, char **argv) {
  klknn::InitMain(argc, argv);
  // absl::ParseCommandLine(argc, argv);
  // plog::init(plog::debug, "/dev/stderr");
  LOG(plog::debug) << "HELLO";
  // gflags::ParseCommandLineFlags(&argc, &argv, true);
  // google::InitGoogleLogging(argv[0]);

  // LOG(INFO) << "NOW LOGGING";
  std::vector<std::string> v = {"foo", "bar", "baz", absl::GetFlag(FLAGS_name)};
  std::string s = absl::StrJoin(v, "-");
  std::cout << "Joined string: " << s << "\n";
  return 0;
}
