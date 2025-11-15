# Copyright (c) 2022-2024 Xiao Pan

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
