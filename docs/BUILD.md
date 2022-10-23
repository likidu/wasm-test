# Build

## Build `libopus`

1. Download source code from https://opus-codec.org/

1. Extract tarball

    ```bash
    tar zxf ./opus-1.3.1.tar.gz
    ```

1. Build with Emscripten

    ```bash
    mkdir build

    emconfigure ./configure --disable-intrinsics --disable-rtcd --disable-stack-protector --disable-shared --disable-hardening --disable-doc --prefix=${PWD}/build CFLAGS='-O2'

    emmake make -j4

    emmake make install
    ```

1. All built static libs and files are located in the `./build` folder. You need to manually copy everything to `$EMSDK/upstream/emscripten/cache/sysroot`.

## Build `libwavepack`

1. Download source code from https://github.com/dbry/WavPack/releases

1. Extract xzball

    ```bash
    tar xf ./wavpack-5.5.0.tar.xz
    ```

1. Build with Emscripten

    ```bash
    mkdir build

    emconfigure ./configure --disable-intrinsics --disable-rtcd --disable-stack-protector --disable-shared --disable-hardening --disable-doc --prefix=${PWD}/build CFLAGS='-O2'

    emmake make -j4

    emmake make install
    ```

1. All built static libs and files are located in the `./build` folder. You need to manually copy everything to `$EMSDK/upstream/emscripten/cache/sysroot`.
