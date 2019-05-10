# Go Game server [![Build Status](https://travis-ci.org/mine-studio/go-game-server.svg?branch=master)](https://travis-ci.org/mine-studio/go-game-server)

围棋

## Dependencies

- gcc (GCC) 8.2.1 20180831, or clang 8.0.0

- cmake version 3.12.3

- Google Protocol Buffers: [protobuf 3.7](https://www.archlinux.org/packages/extra/x86_64/protobuf/)

- boost 1.69

## Build
```bash
git submodule update --init
mkdir build && cd build
cmake ..
make -j8
```

## Start

```bash
./cmake-build-debug/app/go-server-app 9527
```
