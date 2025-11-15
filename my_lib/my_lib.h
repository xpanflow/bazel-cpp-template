// Copyright (c) 2022-2024 Xiao Pan

#ifndef MY_LIB_MY_LIB_H_
#define MY_LIB_MY_LIB_H_

namespace my_lib
{
class GregorianYear
{
  public:
    explicit GregorianYear(int year);

    // Applies Gregorian rules to positive years. Returns false for year zero and earlier.
    [[nodiscard]] bool IsLeap() const;

  private:
    int year_;
};
}  // namespace my_lib

#endif  // MY_LIB_MY_LIB_H_
