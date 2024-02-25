const std = @import("std");
const b = std.build;

pub fn build(builder: *b.Builder) void {
    const target = builder.standardTargetOptions(.{});
    _ = target;
    const lib = builder.addSharedLibrary(.{ .name = "GL" });
    _ = lib;

    const exe = builder.addExecutable(.{
        .name = "02-hello-triangle",
    });
    exe.addCSourceFile("main.c", &[_][]const u8{ "-std=c11", "-Wall" });
}
