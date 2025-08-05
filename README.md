# Emscripten-CMake-Libraries-Minimal
Minimal project with multiple dependent libraries, buildable as both WASM and regular old C++ libraries. Designed to test polymorphism and other such native assumptions inside emscripten, as well as document how to build multi-library emscripten projects.

## Dependencies
- Emscripten 3.1.6
- Cmake 3.30.3

## Build instructions

All commands assume you are in the root directory.

### Regular Application
```
mkdir build
cd build
cmake ..
cmake --build .
cd app
./app
```
### WASM/Emscripten
```
mkdir build
cd build
emcmake cmake ..
cmake -- build .
cd ..
python3 -m http.server 8000
Navigate to `http://localhost:8000/index.html` in a web browser, open browser console to see results.
```
## Description
This project is a single CMake project that can build both native applications and WASM applications.
Notably, the project is setup to build several libraries, with an attempt to keep the emscripten part
of it isolated from the rest of the codebase, for good project hygeine.

When compiled normally, the project produces an `app`, which is a regular C++ application that calls functions from the libraries, and instantiates and passes a polymorphic interface.
When compiled for WASM, the project instead compiled an `emscriptenbindings` project, which bundles the other libraries into a single static `.wasm`.
An `index.html` file is provided at the root, to exercise this wasm, and demonstrate polymorphic behaviour across module boundarys functions as you would expect.

This project is designed to serve as a jumping off point for quick experimentation, which I find myself needing to do quite regularly when maintaining larger emscripten applications, as not all assumptions from C++-land hold.

### Structure
- `commonlib` -> A library with no dependencies. Exposes `IAbstractInterface.h`
- `liba` -> Dependent on `commonlib`. Exposes `ConcreteInterfaceImplementation` which inherits `IAbstractInterface`
- `libb` -> Dependent on `commonlib`. Exposes a method that takes an `IAbstractInterface` pointer as an argument and calls its polymorphic function.
- `app` -> C++ application exercising the above libraries, dependent on all
- `emscriptenbindings` -> Emscripten module that uses emscriptens `bind.h` to explicitly bind all library functionality. Dependent on all, bundles all the object files of the dependent libraries into a single "statically linked" `.wasm`, with an emscripten generated `.js` module loader
- `index.html` -> Exercises the emscripten module, demonstrating polymorphic behaviour. Must be served via a web server and loaded in a browser. Output is in the browser console.
