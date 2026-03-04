load("@rules_cc//cc:defs.bzl", "cc_test","cc_binary")

cc_binary(
    name = "generate_test_data",
    srcs = ["test_data_generation.cpp"],
    deps = ["//kvstore"],
)

# This runs your generator and produces data.log
genrule(
    name = "generated_logfile",
    srcs = [":generate_test_data"],
    outs = ["data.log"],
    cmd = "$(location :generate_test_data) $@",
)

cc_test(
    name = "restore_test",
    srcs = ["test_kv_restore.cpp"],
    deps = ["//kvstore"],
    data = [
        ":generated_logfile",   # <-- data.log will be placed in runfiles
    ],
)

cc_test(
    name = "read_latency_test",
    srcs = ["test_read_latency.cpp"],
    deps = ["//kvstore"],
    data = [
        ":generated_logfile",
    ],
)