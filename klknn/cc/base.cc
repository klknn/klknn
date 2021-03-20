#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

#include "klknn/cc/log.h"

// TODO: more gflags (or abseil-py) compatible flags
ABSL_FLAG(bool, logtostderr, true, "If true, print log to stderr.");
ABSL_FLAG(bool, logutctime, false, "If true, print log with UTC time.");

namespace {

class AbslFormatter {
 public:
  // Returns a header for a new file. In our case it is empty.
  static plog::util::nstring header() {
    return plog::util::nstring();
  }

  // Returns a string from a record.
  static plog::util::nstring format(const plog::Record& record) {
    tm t;
    auto time = record.getTime();
    if (absl::GetFlag(FLAGS_logutctime)) {
      plog::util::gmtime_s(&t, &time.time);
    }
    else {
      plog::util::localtime_s(&t, &time.time);
    }

    // based on abseil-py prefix
    // https://github.com/abseil/abseil-py/blob/9954557f9df0b346a57ff82688438c55202d2188/absl/logging/__init__.py#L731
    return absl::StrFormat(
        "%c%02d%02d %02d:%02d:%02d.%06d %5d %s:%d] %s\n",
        severityToString(record.getSeverity())[0],
        t.tm_mon + 1, t.tm_mday,
        t.tm_hour,
        t.tm_min,
        t.tm_sec,
        time.millitm,
        record.getTid(),
        record.getFile(),
        record.getLine(),
        record.getMessage());
  }
};

}  // namespace plog

namespace klknn {

void InitMain(int argc, char** argv) {
  absl::ParseCommandLine(argc, argv);
  plog::init<::AbslFormatter>(
      plog::debug, absl::GetFlag(FLAGS_logtostderr) ?
      // TODO: gflags or abseil-py compatible log filename
      "/dev/stderr" : "/tmp/klknn.log");
}

}  // namespace klknn
