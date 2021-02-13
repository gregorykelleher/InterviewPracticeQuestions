### Interview Practice Questions

This repository contains a collection of sample questions I've completed in practice for interviews. You can read more about the structuring of this project [here](https://gregorykelleher.com/interview_practice).

#### Prerequisites

* Conan version >=2.0.11

#### How to install dependencies

```bash
conan install . --output-folder=build --build=missing
```

#### How to build

```bash
cd build

cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake

cmake --build . --config Release
```

#### How to install

```bash
cmake --install .
```

#### How to test

```bash
ctest
```