load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# cc deps
http_archive(
    name = "com_google_absl",
    urls = ["https://github.com/abseil/abseil-cpp/archive/20200923.3.zip"],
    strip_prefix = "abseil-cpp-20200923.3",
    sha256 = "6622893ab117501fc23268a2936e0d46ee6cb0319dcf2275e33a708cd9634ea6",
)
http_archive(
    name = "com_google_googletest",
    urls = ["https://github.com/google/googletest/archive/release-1.10.0.zip"],
    strip_prefix = "googletest-release-1.10.0",
    sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
)
git_repository(
    name = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags.git",
    # tag = "v2.2.2"
    commit = "e171aa2d15ed9eb17054558e0b3a6a413bb01067",
    shallow_since = "1541971260 +0000",
)
http_archive(
    name = "com_github_google_glog",
    sha256 = "62efeb57ff70db9ea2129a16d0f908941e355d09d6d83c9f7b18557c0a7ab59e",
    strip_prefix = "glog-d516278b1cd33cd148e8989aec488b6049a4ca0b",
    urls = ["https://github.com/google/glog/archive/d516278b1cd33cd148e8989aec488b6049a4ca0b.zip"],
)

# java deps
RULES_JVM_EXTERNAL_TAG = "2.5"
RULES_JVM_EXTERNAL_SHA = "249e8129914be6d987ca57754516be35a14ea866c616041ff0cd32ea94d2f3a1"
http_archive(
    name = "rules_jvm_external",
    sha256 = RULES_JVM_EXTERNAL_SHA,
    strip_prefix = "rules_jvm_external-%s" % RULES_JVM_EXTERNAL_TAG,
    url = "https://github.com/bazelbuild/rules_jvm_external/archive/%s.zip" % RULES_JVM_EXTERNAL_TAG,
)
load("@rules_jvm_external//:defs.bzl", "maven_install")
maven_install(
    artifacts = [
        "junit:junit:4.13.2",
        "com.google.guava:guava:30.1-jre",
    ],
    fetch_sources = True,
    repositories = [
        "http://uk.maven.org/maven2",
        "https://jcenter.bintray.com/",
    ],
)


# python deps
git_repository(
    name = "rules_python",
    remote = "https://github.com/bazelbuild/rules_python.git",
    commit = "06672cd470ce513a256c7ef2dbb8497a0f5502f3",
    shallow_since = "1592977862 -0700",
)

load("@rules_python//python:pip.bzl", "pip_import")

pip_import(
    name = "py_deps",
    requirements = "//:requirements.txt",
)

load("@py_deps//:requirements.bzl", "pip_install")

pip_install()
