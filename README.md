# C/C++ Programming

*Author: Deva Nayak*

A collection of C/C++ programming notes, examples, and exercises.

## Table of Contents

| Chapter | Topic | Link |
|---|---|---|
| 1 | Introduction & First Program | [chap1/chap1.md](chap1/chap1.md) |
| 2 | Header Files | [chap2/chap2.md](chap2/chap2.md) |
| — | Compilers Overview | [compilers/compilers.md](compilers/compilers.md) |
| — | Optimization Techniques | [Optimization/Optimization.md](Optimization/Optimization.md) |
| — | Multithreading | [Multithreading/Multithreading.md](Multithreading/Multithreading.md) |
| — | Virtual Functions | [virtualFunctions/](virtualFunctions/) |
| — | Python & Virtual Environments | [python/python.md](python/python.md) |

---

## Quick Compile Commands

### Prerequisites

On macOS you already have `clang`/`clang++` via Xcode Command Line Tools. For CMake:

```bash
brew install cmake
```

### Chapter 1 — First Program (C)

```bash
cd chap1/code
gcc firstProgram.cpp -o firstProgram
./firstProgram
```

### Chapter 2 — Header Files Exercise (C)

```bash
cd chap2/code
gcc main.c math_operations.c -o program
./program
```

### Multithreading (C++11)

```bash
cd Multithreading/code
clang++ -std=c++11 -pthread Multithreading.cpp -o multithreading
./multithreading
```

### Optimization — Loop Unrolling (CMake)

```bash
cd Optimization/code
mkdir -p build && cd build
cmake ..
make
./loop_unrolling_example
```

### Virtual Functions Examples (CMake)

Each sub-folder under `virtualFunctions/` has its own `CMakeLists.txt`:

```bash
# Example: build the "code" example
cd virtualFunctions/code
mkdir -p build && cd build
cmake ..
make
./notvirt
```

Available examples:
| Folder | Executable |
|---|---|
| `code/` | `notvirt` |
| `codeV2/` | `notvirt` |
| `statfunc/` | `statfunc` |
| `virtpure/` | `virtpure` |
| `virtpers/` | `virtpers` |
| `graphics/` | `virtshap` |

### Quick one-liner to build any CMake project

```bash
cmake -S <source-dir> -B <source-dir>/build && cmake --build <source-dir>/build
```

Example:

```bash
cmake -S virtualFunctions/code -B virtualFunctions/code/build && cmake --build virtualFunctions/code/build
```
