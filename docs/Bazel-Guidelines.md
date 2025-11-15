# Bazel guidelines for C++ packages

## Package layout

- Give each library a focused responsibility. One class and its implementation are often a good starting point.
- Keep a library's headers, implementation, unit tests, and BUILD file in the same package.
- Give an internal component its own BUILD file when it needs a separate dependency boundary.

```text
parser/
  BUILD.bazel
  parser.h
  parser.cpp
  parser_test.cpp
  internal/
    BUILD.bazel
    tokenizer.h
    tokenizer.cpp
    tokenizer_test.cpp
```

## Sources and dependencies

- List first-party source files explicitly. Put implementations and private headers in `srcs` and public headers in `hdrs`.
- Use narrow `glob()` patterns for test fixtures or vendored files that follow an upstream layout.
- List direct dependencies in `deps`. Use `:parser` for a dependency in the same package.

## Visibility

- Keep implementation targets and test helpers private by default.
- Grant access to one package with `//app:__pkg__` or to that package and its descendants with `//app:__subpackages__`.
- Use `//visibility:public` for libraries intended for any caller.

## Tests

- Group unit cases in a `cc_test` directly below the corresponding `cc_library`.
- Mark helper libraries used only by tests with `testonly = True`.
- Give integration tests their own targets so they can run separately. A `tests/integration/` package works for tests that span several components.

## Example BUILD file

- Expose a library with `cc_library` and test it with GoogleTest. [Working example](../my_lib/BUILD)

```starlark
load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_cc//cc:cc_test.bzl", "cc_test")

cc_library(
    name = "my_lib",
    srcs = ["my_lib.cpp"],
    hdrs = ["my_lib.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "unit_test",
    size = "small",
    srcs = ["my_lib_test.cpp"],
    deps = [
        ":my_lib",
        "@googletest//:gtest_main",
    ],
)
```

- From the repository root, query the test target's dependencies and run the test.

```bash
bazel query 'labels(deps, //my_lib:unit_test)'
bazel test //my_lib:unit_test
```
