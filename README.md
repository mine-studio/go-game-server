# Go Game(围棋) Server [![Build Status](https://travis-ci.org/mine-studio/go-game-server.svg?branch=master)](https://travis-ci.org/mine-studio/go-game-server)


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

## Run

* Server

```bash
./cmake-build-debug/app/go-game-server 9527
```

* Client

```bash
./cmake-build-debug/app/go-game-client localhost 9527
```
