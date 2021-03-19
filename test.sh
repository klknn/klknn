# bazel clean --expunge
bazel test --test_output=all \
      //klknn/cc:all \
      //klknn/java:all \
      //klknn/python:all
