# AlgorithmPractice

## Overview

A C++ project implementing a collection of fundamental data structures and algorithms. This repository serves as a practice ground for C++ programming, data structure design, generic programming with templates and concepts (C++20), and software development best practices including testing, containerization, and memory safety.

## Features

*   **Core Container Interfaces**:
    *   `Container`: Basic interface for all data structures.
    *   `TraversableContainer`: For structures that can be traversed (e.g., with iterators or visitor patterns).
    *   `MappableContainer`: For structures whose elements can be modified in place.
    *   `DictionaryContainer`: For key-value type structures.
    *   `LinearContainer`: For sequence-based structures.
    *   `SortableLinearContainer`: For linear structures that can be sorted.
*   **Implemented Data Structures**:
    *   **Vector**: Dynamic array.
        *   `Vector<Data>`
        *   `SortableVector<Data>` (requires `std::totally_ordered<Data>`)
    *   **List**: Doubly linked list.
        *   `List<Data>`
    *   **Stack**: LIFO (Last-In-First-Out) data structure.
        *   `Stack<Data>` (interface)
        *   `StackLst<Data>`: Stack implemented using a `List`.
        *   `StackVec<Data>`: Stack implemented using a `Vector`.
    *   **Queue**: FIFO (First-In-First-Out) data structure.
        *   `Queue<Data>` (interface)
        *   `QueueLst<Data>`: Queue implemented using a `List`.
        *   `QueueVec<Data>`: Queue implemented using a `Vector`.
    *   **Set**: Collection of unique, sorted elements.
        *   `Set<Data>` (interface)
        *   `SetVec<Data>`: Set implemented using a `SortableVector`.
        *   `SetLst<Data>`: Set implemented using a `List`.
    *   **Heap**: Max-heap data structure.
        *   `Heap<Data>` (interface, requires `std::totally_ordered<Data>`)
        *   `HeapVec<Data>`: Heap implemented using a `SortableVector`.
    *   **Priority Queue (PQ)**:
        *   `PQ<Data>` (interface, requires `std::totally_ordered<Data>`)
        *   `PQHeap<Data>`: Priority Queue implemented using `HeapVec`.
*   **Generic Programming**: Extensive use of C++ templates and C++20 concepts for type safety and flexibility.
*   **Testing Suites**:
    *   `zlasdtest`: A provided test suite.
    *   `zmytest`: A custom-developed test suite for more targeted testing.
*   **Build System**: `Makefile` for easy compilation and management.
*   **Development Tools**:
    *   Docker support for a consistent build and run environment.
    *   Valgrind integration for memory leak detection and profiling.
    *   Code coverage generation (lcov, gcovr).

## Directory Structure

```
/
├── container/      # Core container interfaces and implementations
├── heap/           # Heap data structure implementation
│   └── vec/        # Vector-based heap
├── list/           # Linked list implementation
├── pq/             # Priority Queue interface and implementations
│   └── heap/       # Heap-based priority queue
├── set/            # Set interface and implementations
│   ├── lst/        # List-based set
│   └── vec/        # Vector-based set
├── vector/         # Vector (dynamic array) implementation
├── zlasdtest/      # Provided test suite
├── zmytest/        # Custom test suite
├── main.cpp        # Main executable to run tests
├── makefile        # Build script
├── dockerfile      # Docker configuration
├── valgrind.sh     # Script for running Valgrind
└── LICENSE         # Project license (Mozilla Public License 2.0)
```

## Prerequisites

*   A C++ compiler supporting C++20 (e.g., GCC g++ >= 10)
*   `make` build automation tool
*   (Optional) Docker
*   (Optional) Valgrind
*   (Optional) lcov, gcovr (for coverage reports)

## Building the Project

1.  **Clone the repository**:
    ```bash
    git clone <repository-url>
    cd AlgorithmPractice
    ```

2.  **Build using Makefile**:
    To build the main executable:
    ```bash
    make main
    ```
    or simply:
    ```bash
    make
    ```
    This will compile the source files and create an executable named `main` in the root directory.

    To clean the build artifacts:
    ```bash
    make clean
    ```

## Running Tests

The `main` executable provides a menu to run different test suites:

```bash
./main
```

You will be prompted to choose:
```
Lasd Libraries 2025
Seleziona il test da eseguire:
1. zlasdtest
2. zmytest - Entire zmytest suite
3. zmytest Exercise 1
4. zmytest Exercise 2
5. Exit
```
Enter the number corresponding to the test suite you wish to run.

## Using Docker

A `dockerfile` is provided to build the project in a containerized environment.

1.  **Build the Docker image**:
    From the root directory of the project:
    ```bash
    docker build -t algorithm-practice .
    ```
    This command builds the Docker image. During the build process, `make` is executed, compiling the project and creating the `main` executable inside the image.

2.  **Run the tests within a Docker container**:
    To run the `main` executable (which allows you to select tests):
    ```bash
    docker run -it --rm algorithm-practice ./main
    ```
    The `--rm` flag automatically removes the container when it exits.

    Alternatively, to get an interactive shell in the container (e.g., to run `make clean`, `make`, or other commands before running tests):
    ```bash
    docker run -it --rm algorithm-practice /bin/bash
    ```
    Once inside the container's shell, you'll be in the `/app` directory. You can then execute:
    ```bash
    ./main
    ```

## Code Coverage

The Makefile includes targets for generating code coverage reports using `gcov`, `lcov`, and `gcovr`.

1.  **Compile with coverage flags**:
    Ensure the project is compiled with coverage flags enabled. The `makefile` defines `cflagsextra` which includes the necessary flags (`-g -ftest-coverage -fprofile-arcs`). You may need to modify your `cflags` in the `makefile` to include these, or adjust the compilation rules. For example, you could append `$(cflagsextra)` to the `cflags` definition:
    ```makefile
    # In your makefile
    cflags = -Wall -Wno-sequence-point -pedantic -O3 -std=c++20 -fsanitize=address $(cflagsextra)
    ```
    Then, rebuild the project:
    ```bash
    make clean
    make main
    ```

2.  **Run your tests**:
    Execute `./main` and run the desired test suites. This will generate `.gcda` files, which are necessary for coverage reports.

3.  **Generate LCOV report**:
    ```bash
    make lcov-report
    ```
    This will create a report in the `lcov-report` directory. Open `lcov-report/index.html` in a browser.

4.  **Generate GCOVR report**:
    ```bash
    make gcovr-report
    ```
    This will create `gcovr-report/coverage.html`.

## Memory Checking with Valgrind

A script `valgrind.sh` is provided to run the `main` executable under Valgrind for memory checking.

1.  **Ensure `main` is built**.
2.  **Make the script executable** (if needed):
    ```bash
    chmod +x valgrind.sh
    ```
3.  **Run Valgrind**:
    ```bash
    ./valgrind.sh
    ```
    You will need to interact with the test menu in the terminal where you launched the script.
    Output and error logs from Valgrind will be redirected to `combined_output.txt`. Review this file for any memory issues.

## License

This project is licensed under the Mozilla Public License Version 2.0. See the [LICENSE](LICENSE) file for details.
