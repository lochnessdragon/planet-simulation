{ pkgs }: {
    deps = [
        pkgs.wget
        pkgs.cmake
        pkgs.clang
        pkgs.raylib
    ];
    hardware.opengl.enable = true;
    env = {     
    };
}