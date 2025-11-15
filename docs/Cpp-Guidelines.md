# C++ guidelines

## Formatting

- Write C++17 and use the repository formatter for layout. [Formatter settings](../.clang-format)
- Use the public style and design guides for additional examples. [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) · [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

## Naming

- Use `PascalCase` for types and ordinary functions. Examples include `GregorianYear` and `IsLeap()`.
- Use `snake_case` for files, namespaces, variables, parameters, and struct fields. End class data members with an underscore, as in `year_`.
- Start program-wide constants with `k`, as in `kMonthsPerYear`.
- Prefer familiar words and abbreviations. Use names such as `IsLeap()` or `CanRetry()` for Boolean queries and a `Try` prefix for operations that report success.
- Use `snake_case` for Bazel targets, such as `parser_test` and `parser_integration_test`. [Bazel guidelines](Bazel-Guidelines.md#tests)

## Functions, classes, and ownership

- Give each function one job. At around 40 lines, consider extracting a step you can name and test separately. [Google guidance on short functions](https://google.github.io/styleguide/cppguide.html#Write_Short_Functions)
- Initialize members in constructors. Mark single-argument constructors `explicit` when conversion should be deliberate. Mark read-only queries `const`.
- Use classes to carry state or enforce invariants. Use a free function when the operation needs no object state.
- Put ordinary implementations in `.cpp` files. Keep templates and short inline definitions in headers where needed.
- Prefer values and containers for ownership. Use `std::unique_ptr` for one owner and `std::shared_ptr` for shared ownership. Document the lifetime of borrowed objects.

## Headers, namespaces, and comments

- Make public headers self-contained and derive include guards from their paths. [Example header](../my_lib/my_lib.h)
- Include the matching header first. Use quoted repository-relative includes for local headers and angle brackets for standard and external headers.
- Keep namespaces shallow and file-local details in the implementation. Use C++17 nested namespace syntax where it reads clearly.
- Describe inputs, results, edge cases, and failures at the declaration as needed. Use Doxygen tags where the project generates API docs.
- Use implementation comments to explain intent.

## Tests

- Use GoogleTest. Use `TEST` for a self-contained case and `TEST_F` when cases share setup.
- Name each case `Given<condition>_When<action>_Then<outcome>`. Write the body in the same order and give distinct scenarios their own cases.
- Test through the public interface. Prefer real collaborators that are easy to use in tests. Use a test double when a dependency needs controlled behavior.
- Set the Bazel test size and timeout to reflect the workload. Use tags when the project filters test groups by tag. [Example BUILD file](../my_lib/BUILD)

## Example GoogleTest

- Check that a century year such as 1900 is a common year when it is indivisible by 400. [Working example](../my_lib/my_lib_test.cpp)

```cpp
TEST(LeapYear, GivenYear1900_WhenCheckingIsLeap_ThenReturnsFalse)
{
    const my_lib::GregorianYear year{1900};
    const bool is_leap = year.IsLeap();
    EXPECT_FALSE(is_leap);
}
```

## Errors and logging

- Follow the project's error-handling model and document how callers receive or recover from failures.
- Use assertions for programmer invariants. Where the project uses exceptions, reserve them for failures and give custom types specific names.
- Use error and warning logs for actionable problems, info for meaningful events, and debug or trace for execution details.
- Explain what happened and give the reader a next action when one exists.

## Standard library and performance

- Use `std::chrono` for time and `std::filesystem` for paths and filesystem operations.
- Prefer typed C++ constructs to macros. Reuse existing domain types and aliases for geometry when the project needs them.
- Profile hot paths before optimizing. Use measurements to decide whether recurring allocations or logging need attention.
