cc_library(
    name = "base",
    hdrs = ["base.h"],
    srcs = ["base.cc"],
    deps = [
        "@com_github_google_glog//:glog",
        "@com_github_gflags_gflags//:gflags",
    ],
)

cc_library(
    name = "gtest_main",
    srcs = ["gtest_main.cc"],
    deps = [
        ":base",
        "@com_google_googletest//:gtest",
        "@com_github_gflags_gflags//:gflags",
    ]
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [
        ":base",
        "@com_google_absl//absl/strings",
        "@com_github_google_glog//:glog",
        "@com_github_gflags_gflags//:gflags",
    ],
)

cc_test(
    name = "absl_test",
    srcs = ["absl_test.cc"],
    size = "small",
    deps = [
        ":gtest_main",
        "@com_google_googletest//:gtest",
        "@com_github_google_glog//:glog",
    ],
)
