const std = @import("std");
const raylib = @import("libs/raylib/src/build.zig");

pub fn build(b: *std.Build) void {
    const cnake_flags = &[_][]const u8{
        "-std=gnu99",
        "-D_GNU_SOURCE",
    };

    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "cnake",
        .root_source_file = .{ .path = "src/main.c" },
        .target = target,
        .optimize = optimize,
    });

    // Working in zig 0.11.0
    exe.addIncludePath(.{ .path = "libs/raylib/src" });
    exe.linkLibrary(raylib.addRaylib(b, target, optimize, .{}));
    exe.addCSourceFiles(&.{"src/controls.c"}, cnake_flags);

    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());

    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    const unit_tests = b.addTest(.{
        .root_source_file = .{ .path = "src/main.zig" },
        .target = target,
        .optimize = optimize,
    });

    const run_unit_tests = b.addRunArtifact(unit_tests);

    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&run_unit_tests.step);
}
