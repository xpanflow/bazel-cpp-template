# Working in this repository

This is a C++ project template on Bazel 8. Use Bazelisk as `bazel` so it picks up `.bazelversion`. The Ubuntu 24.04 x86-64 devcontainer provides the same tools as CI. [Setup instructions](README.md#quick-start)

## Making changes

- Read the relevant guidelines before editing and keep the diff focused on the request. Check existing callers when changing a public API or Bazel target.
- Start with the affected package's `BUILD` file. For the sample, `//my_lib:my_lib` is the public library and `//my_lib:unit_test` exercises it. Follow the same layout for new packages. [Bazel guidelines](docs/Bazel-Guidelines.md)
- Follow the project's naming, class design and formatting conventions when editing C++. [C++ guidelines](docs/Cpp-Guidelines.md)
- Declare external dependencies in `MODULE.bazel`. When changing a dependency, build the affected target and include Bazel's generated `MODULE.bazel.lock` diff in the change.

## Verifying changes

Run commands from the repository root.

| Change                            | What to run                                                                                                                                                                            |
| --------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Library or BUILD target           | Run the affected test first, for example `bazel test //my_lib:unit_test`. For a full debug build, release build and test run, use `./scripts/build_and_test/build_and_test.sh`. |
| C++, Starlark or shell formatting | Run `./scripts/check_and_fix/check_and_fix.sh`. Use `--fix` to apply edits and review the diff.                                                                                    |
| Developer scripts                 | Run `./scripts/test_workflows.sh`. For coverage changes, also run `./scripts/check_and_fix/code_coverage.sh` and verify `bazel-coverage/index.html`.                             |
| Documentation only                | Check relative links, target labels and command paths against the checkout.                                                                                                            |

Before handing back a change, review the diff and report what changed, which checks ran, their results, and anything that still needs verification.
