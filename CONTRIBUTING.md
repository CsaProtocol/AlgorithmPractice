# Contributing to AlgorithmPractice

First off, thank you for considering contributing to AlgorithmPractice! Your help is appreciated.

This document provides guidelines for contributing to this project. Please read it carefully to ensure a smooth and effective contribution process.

## How to Contribute

We welcome contributions in various forms, including:
*   Reporting bugs
*   Suggesting new features or enhancements
*   Writing or improving documentation
*   Adding new data structures or algorithms
*   Improving existing implementations
*   Adding new test cases

### Reporting Bugs or Suggesting Features

*   Use the GitHub Issues section of the repository.
*   **For Bugs**:
    *   Check if the bug has already been reported.
    *   Provide a clear and descriptive title.
    *   Include steps to reproduce the bug.
    *   Describe the expected behavior and what actually happened.
    *   Include your environment details (OS, compiler version).
*   **For Features/Enhancements**:
    *   Provide a clear and descriptive title.
    *   Explain the proposed feature and its benefits.
    *   Provide examples or use cases if possible.

### Making Code Contributions

1.  **Fork the Repository**: Click the "Fork" button at the top right of the repository page.
2.  **Clone Your Fork**: `git clone https://github.com/YOUR_USERNAME/AlgorithmPractice.git`
3.  **Create a Branch**: Create a new branch for your changes: `git checkout -b feature/your-feature-name` or `git checkout -b fix/your-bug-fix-name`.
4.  **Set Up Environment**: Ensure you have a C++20 compatible compiler (like GCC g++ >= 10) and `make`.
5.  **Make Your Changes**:
    *   Follow the existing coding style. Try to be consistent with the surrounding code.
    *   Write clear, concise, and well-commented code.
    *   Ensure your changes are covered by tests. Add new tests to the `zmytest` suite for any new functionality or bug fixes.
6.  **Test Your Changes**:
    *   Compile the project: `make` or `make main`.
    *   Run all tests using the main executable: `./main` and select the relevant test suites (especially `zmytest`).
    *   Run Valgrind to check for memory leaks: `./valgrind.sh` (after building `main`).
7.  **Commit Your Changes**:
    *   Use clear and descriptive commit messages. A good commit message summarizes the changes and why they were made.
    *   Example: `feat: Add AVL Tree implementation` or `fix: Correct off-by-one error in Vector::Resize`.
8.  **Push to Your Fork**: `git push origin feature/your-feature-name`.
9.  **Submit a Pull Request (PR)**:
    *   Go to the original `AlgorithmPractice` repository on GitHub.
    *   Click on "Pull requests" and then "New pull request".
    *   Choose your fork and branch to compare with the main branch of the original repository.
    *   Provide a clear title and description for your PR, explaining the changes and referencing any related issues.
    *   Be prepared for discussion and feedback on your PR.

### Coding Style and Conventions

*   **Language**: C++20. Make use of modern C++ features where appropriate (concepts, ranges, etc.).
*   **Formatting**:
    *   Follow the style of the existing codebase (indentation, spacing, bracing).
    *   Use consistent naming conventions (e.g., `ClassName`, `methodNameOrVariableName`, `CONSTANT_NAME`).
*   **Comments**: Write clear comments to explain complex logic or non-obvious parts of the code. Doxygen-style comments for public APIs are encouraged.
*   **Templates and Concepts**: Utilize templates for generic programming and C++20 concepts to constrain template parameters for better type safety and clearer error messages.
*   **Error Handling**: Use exceptions for error reporting where appropriate (e.g., `std::out_of_range`, `std::length_error`).
*   **Memory Management**: Be mindful of memory allocation and deallocation. Use smart pointers if they simplify resource management, though the current project primarily uses raw pointers with manual management. Ensure Valgrind runs clean.

## Roadmap: Future Directions

This project aims to be a comprehensive practice ground for C++ and DSA. Here are some areas for future development:

### New Data Structures

*   **Trees**:
    *   Binary Search Tree (BST)
        *   Implementation as a specialization of the `BinaryTree` interface
        *   Specific operations (insert, delete, search, min, max, predecessor, successor)
    *   Self-Balancing Trees:
        *   AVL Tree
        *   Red-Black Tree
    *   B-Trees / B+ Trees (for understanding disk-based data structures)
*   **Hash Tables**:
    *   Implementations with different collision resolution strategies:
        *   Separate Chaining (using `lasd::List`)
        *   Open Addressing (Linear Probing, Quadratic Probing, Double Hashing)
*   **Graphs**:
    *   Representations:
        *   Adjacency List
        *   Adjacency Matrix
    *   Algorithms:
        *   Traversal: Breadth-First Search (BFS), Depth-First Search (DFS)
        *   Shortest Path: Dijkstra's Algorithm, Bellman-Ford Algorithm
        *   Minimum Spanning Tree: Prim's Algorithm, Kruskal's Algorithm
        *   Topological Sort

### Enhancements to Existing Structures

*   **Binary Trees**:
    *   Additional traversal methods
    *   Search operations
    *   More specialized tree implementations (BST, AVL, etc.)
*   **Iterators**:
    *   Implement more comprehensive iterator support for all containers (e.g., reverse iterators, const iterators where missing).
    *   Ensure compliance with C++ iterator concepts.
*   **More Operations**:
    *   Add other useful utility functions to existing containers as appropriate.

### Additional Sorting Algorithms

For `SortableLinearContainer` or specialized sortable structures:
*   **Merge Sort**: (A robust O(N log N) algorithm)
*   **Quick Sort**: (Often faster in practice, O(N log N) average)
    *   Different pivot selection strategies.
    *   Tail call optimization or iterative versions.
*   **Insertion Sort**: (Efficient for small or nearly sorted datasets)
*   **Selection Sort**: (Simple, but O(N^2))
*   **Bubble Sort**: (Primarily for educational purposes, O(N^2))

### Advanced Algorithms

*   String searching algorithms (e.g., KMP, Boyer-Moore).
*   Dynamic Programming examples.
*   Greedy algorithms examples.

### Testing and Benchmarking

*   **Expand `zmytest`**: Add more comprehensive test cases, including edge cases and stress tests for all data structures and algorithms.
*   **Performance Benchmarking**:
    *   Set up a simple benchmarking framework to compare the performance of different implementations or algorithms (e.g., `SetVec` vs `SetLst`, different sorting algorithms).

### Build System and Tooling

*   **CMake**: Consider migrating to CMake for better cross-platform compatibility and project management, especially if the project grows significantly.
*   **Static Analysis**: Integrate tools like Clang-Tidy for deeper static analysis.

### Documentation

*   **Tutorials**: Add simple tutorial files or examples in the `learn.md` or separate files demonstrating how to use the various library components.

We are excited to see your contributions and grow this library together!
