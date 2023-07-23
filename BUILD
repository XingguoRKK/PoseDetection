load(
    "@build_bazel_rules_apple//apple:ios.bzl",
    "ios_framework",
)
# load(
#     "//mediapipe/examples/ios:bundle_id.bzl",
#     "BUNDLE_ID_PREFIX",
#     "a42f4aa1-6697-41a9-a10d-970c600ba26f.mobileprovision",
# )

# licenses(["notice"])

MIN_IOS_VERSION = "12.0"
FRAMEWORK_HEADERS = [
    "PoseTrackingViewController.h",
    "PoseDetectorLib.h",
]

# alias(
#     name = "posetrackinggpu",
#     actual = "PoseTrackingGpuApp",
# )

ios_framework(
    name = "PoseTrackingGpuAppLib",
    # app_icons = ["//mediapipe/examples/ios/common:AppIcon"],
    bundle_id =  "com.rokoko.care.pose-tracking-gpu",
    hdrs = FRAMEWORK_HEADERS,
    families = [
        "iphone",
        "ipad",
    ],
    infoplists = [
        "//mediapipe/examples/ios/common:Info.plist",
        "Info.plist",
    ],
    minimum_os_version = MIN_IOS_VERSION,
    # provisioning_profile = example_provisioning(),
    visibility = ["//visibility:public"],
    deps = [
        ":PoseTrackingGpuAppLibrary",
        "@ios_opencv//:OpencvFramework",
    ],
)

objc_library(
    name = "PoseTrackingGpuAppLibrary",
    srcs = [
        "PoseTrackingViewController.mm",
    ],
    hdrs = FRAMEWORK_HEADERS,
    copts = ["-std=c++17"],
    data = [
        "//mediapipe/graphs/pose_tracking:pose_tracking_gpu.binarypb",
        "//mediapipe/modules/pose_detection:pose_detection.tflite",
        "//mediapipe/modules/pose_landmark:pose_landmark_full.tflite",
    ],
    deps = [
        "//mediapipe/examples/ios/common:CommonMediaPipeAppLibrary",
        "//mediapipe/framework/formats:landmark_cc_proto",
    ] + select({
        "//mediapipe:ios_i386": [],
        "//mediapipe:ios_x86_64": [],
        "//conditions:default": [
            "//mediapipe/graphs/pose_tracking:pose_tracking_gpu_deps",
        ],
    }),
)
