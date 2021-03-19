load("@py_deps//:requirements.bzl", "requirement")

py_binary(
    name = "hello",
    srcs = ["hello.py"],
    python_version = "PY3",
    deps = [
        requirement("absl-py"),
    ],
)

py_test(
    name = "absl_test",
    srcs = ["absl_test.py"],
    size = "small",
    python_version = "PY3",
    deps = [
        requirement("absl-py"),
    ],
)
