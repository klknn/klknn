#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "plog/Log.h"

// TODO: more gflags (or abseil-py) compatible flags
ABSL_FLAG(bool, logtostderr, true, "If true, print log to stderr.");

namespace klknn {

void InitMain(int argc, char** argv) {
  absl::ParseCommandLine(argc, argv);
  plog::init(plog::debug, absl::GetFlag(FLAGS_logtostderr) ?
             // TODO: gflags or abseil-py compatible log filename
             "/dev/stderr" : "/tmp/klknn.log");
}

}
