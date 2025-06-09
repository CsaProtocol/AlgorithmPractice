# Learning About Data Structures and Algorithms in this Repository

This document provides an overview of the fundamental data structures and algorithms implemented in the `AlgorithmPractice` C++ project. For each, we discuss its purpose and the Big O notation for the complexity of its key operations.

## 1. Vector (Dynamic Array)

Represented by `lasd::Vector<Data>` and `lasd::SortableVector<Data>`.

*   **Description**: A dynamic array that stores elements in contiguous memory locations. It can automatically resize itself when elements are added or removed. `SortableVector` is a specialization that can be sorted.
*   **Key Operations & Complexity**:
    *   **Access by Index (`operator[]`)**:
        *   Complexity: O(1)
        *   Explanation: Direct memory access.
    *   **Get Front/Back Element**:
        *   Complexity: O(1)
    *   **Insertion/Deletion at the End (Amortized)**:
        *   Complexity: O(1) amortized.
        *   Worst-Case: O(N) if resizing is required (allocating new memory and copying N elements).
        *   Explanation: If there's space, it's O(1). Resizing happens occasionally, and its cost is distributed over many operations.
    *   **Insertion/Deletion at Arbitrary Position (Beginning/Middle)**:
        *   Complexity: O(N)
        *   Explanation: Requires shifting subsequent elements.
    *   **Search (Unsorted Vector)**:
        *   Complexity: O(N)
        *   Explanation: Linear scan is required.
    *   **Search (Sorted `SortableVector` using Binary Search)**:
        *   Complexity: O(log N)
    *   **Resize (`Resize()`)**:
        *   Complexity: O(N)
        *   Explanation: Allocates new memory and copies existing elements.
    *   **Sort (for `SortableVector<Data>`)**:
        *   Complexity: Typically O(N log N) for efficient algorithms like QuickSort, MergeSort, or HeapSort. The specific `Sort()` method in `HeapVec` uses HeapSort.

## 2. List (Linked List)

Represented by `lasd::List<Data>`.

*   **Description**: A linear collection of data elements (nodes) where each node points to the next and previous node in the sequence.
*   **Key Operations & Complexity**:
    *   **Access by Index (`operator[]`, `GetAt`)**:
        *   Complexity: O(N)
        *   Explanation: Requires traversing the list from the beginning or end.
    *   **Get Front/Back Element**:
        *   Complexity: O(1)
        *   Explanation: Direct access via head/tail pointers.
    *   **Insertion/Deletion at Front/Back**:
        *   Complexity: O(1)
        *   Explanation: Involves updating a few pointers.
    *   **Insertion/Deletion at a Known Position (given pointer/iterator to node)**:
        *   Complexity: O(1)
    *   **Insertion/Deletion at an Arbitrary Index (requires finding the index first)**:
        *   Complexity: O(N)
        *   Explanation: O(N) to find the node, then O(1) to insert/delete.
    *   **Search**:
        *   Complexity: O(N)
        *   Explanation: Linear traversal is required.

## 3. Set

Represented by the interface `lasd::Set<Data>` and implemented by `lasd::SetVec<Data>` (using `SortableVector`) and `lasd::SetLst<Data>` (using `List`). Sets store unique, sorted elements.

### 3.1. `SetVec<Data>` (Set implemented with `SortableVector`)

*   **Description**: Elements are stored in a `SortableVector`, kept in sorted order.
*   **Key Operations & Complexity**:
    *   **Insertion (`Insert`)**:
        *   Complexity: O(N)
        *   Explanation: O(log N) to find the insertion point (binary search) + O(N) to shift elements to make space.
    *   **Deletion (`Remove`)**:
        *   Complexity: O(N)
        *   Explanation: O(log N) to find the element (binary search) + O(N) to shift elements to fill the gap.
    *   **Search (`Exists`)**:
        *   Complexity: O(log N)
        *   Explanation: Uses binary search on the sorted vector.
    *   **Min/Max Element**:
        *   Complexity: O(1)
        *   Explanation: First/last element of the sorted vector.
    *   **Predecessor/Successor**:
        *   Complexity: O(log N)
        *   Explanation: Find the element (or its position) using binary search.

### 3.2. `SetLst<Data>` (Set implemented with `List`)

*   **Description**: Elements are stored in a `List`, kept in sorted order.
*   **Key Operations & Complexity**:
    *   **Insertion (`Insert`)**:
        *   Complexity: O(N)
        *   Explanation: Traverse the list to find the correct sorted position (O(N)), then O(1) to insert.
    *   **Deletion (`Remove`)**:
        *   Complexity: O(N)
        *   Explanation: Traverse the list to find the element (O(N)), then O(1) to remove.
    *   **Search (`Exists`)**:
        *   Complexity: O(N)
        *   Explanation: Linear traversal.
    *   **Min/Max Element**:
        *   Complexity: O(1)
        *   Explanation: Head/tail of the sorted list.
    *   **Predecessor/Successor**:
        *   Complexity: O(N)
        *   Explanation: Traverse to find the element or its position.

## 4. Heap (Max-Heap)

Represented by the interface `lasd::Heap<Data>` and implemented by `lasd::HeapVec<Data>` (using `SortableVector`).

*   **Description**: A specialized tree-based data structure that satisfies the heap property. In a max-heap, for any given node C, if P is a parent node of C, then the value of P is greater than or equal to the value of C. This implementation uses a vector to represent the tree.
*   **Key Operations & Complexity (for `HeapVec<Data>`)**:
    *   **Build Heap (`Heapify()` from an unsorted array/vector)**:
        *   Complexity: O(N)
        *   Explanation: Efficiently arranges N elements into heap order.
    *   **Check if Heap (`IsHeap()`)**:
        *   Complexity: O(N)
        *   Explanation: Must check the heap property for potentially all relevant nodes.
    *   **Heapify Up (used after insertion)**:
        *   Complexity: O(log N)
        *   Explanation: Restores heap property by moving an element up the tree.
    *   **Heapify Down (used after deletion of max or in `Heapify()`)**:
        *   Complexity: O(log N)
        *   Explanation: Restores heap property by moving an element down the tree.
    *   **Sort (`Sort()` using HeapSort)**:
        *   Complexity: O(N log N)
        *   Explanation: Builds a heap (O(N)) and then extracts N elements (N * O(log N)).

## 5. Priority Queue (PQ)

Represented by the interface `lasd::PQ<Data>` and implemented by `lasd::PQHeap<Data>` (using `HeapVec`).

*   **Description**: An abstract data type where each element has an associated "priority". Elements with higher priority are served before elements with lower priority. This implementation uses a max-heap.
*   **Key Operations & Complexity (for `PQHeap<Data>`)**:
    *   **Insertion (`Insert`)**:
        *   Complexity: O(log N) (amortized, can be O(N) if vector resize occurs, but typically dominated by heap operation)
        *   Explanation: Adds an element and then performs `HeapifyUp`.
    *   **Get Highest Priority Element (`Tip`)**:
        *   Complexity: O(1)
        *   Explanation: The root of the heap.
    *   **Remove Highest Priority Element (`RemoveTip`)**:
        *   Complexity: O(log N) (amortized, can be O(N) if vector resize occurs)
        *   Explanation: Replaces the root with the last element, removes the last, and then performs `HeapifyDown`.
    *   **Get and Remove Highest Priority (`TipNRemove`)**:
        *   Complexity: O(log N) (amortized)
    *   **Change Priority (`Change`)**:
        *   Complexity: O(log N)
        *   Explanation: Modifies an element's priority and then performs `HeapifyUp` or `HeapifyDown` as needed.

---

This document provides a general guide. The exact performance can sometimes depend on the nature of the data being processed. Refer to the source code for the most precise understanding.

