# Quick Sort in C

A simple implementation of the **Quick Sort** algorithm in C, using the Lomuto partition scheme and recursion to efficiently sort an array of integers in ascending order.

## Overview

Quick Sort is a comparison-based sorting algorithm that follows the **divide-and-conquer** approach.

It selects an element as a pivot, partitions the array around it, and recursively sorts the resulting subarrays.

Unlike Bubble Sort, which repeatedly compares adjacent elements, Quick Sort divides the problem into smaller parts.

### Partitioning

This implementation uses the **Lomuto partition scheme**, selecting the last element of each subarray as the pivot.

During partitioning:

1. Elements less than or equal to the pivot are moved to its left.
2. Elements greater than the pivot remain on its right.
3. The pivot is placed in its final sorted position.

The algorithm then recursively sorts the left and right partitions until the entire array is sorted.

## Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best | `O(n log n)` |
| Average | `O(n log n)` |
| Worst | `O(n²)` |
| Auxiliary space (average) | `O(log n)` |
| Auxiliary space (worst) | `O(n)` |

Quick Sort achieves an average time complexity of `O(n log n)` when partitions are reasonably balanced.

However, choosing the last element as the pivot can lead to unbalanced partitions, particularly when the array is already sorted or reverse-sorted.

In these cases, the time complexity can degrade to `O(n²)`.

Although partitioning is performed **in-place**, recursive function calls require additional stack memory.

## Implementation

```c
#include <stdio.h>
#include <stddef.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

size_t partition(int numbers[], size_t low, size_t high) {
    int pivot = numbers[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (numbers[j] <= pivot) {
            swap(&numbers[i], &numbers[j]);
            i++;
        }
    }

    swap(&numbers[i], &numbers[high]);

    return i;
}

void quick_sort_recursive(int numbers[], size_t low, size_t high) {
    if (low > high) {
        return;
    }

    size_t pivot_index = partition(numbers, low, high);

    if (pivot_index > low) {
        quick_sort_recursive(numbers, low, pivot_index - 1);
    }

    if (pivot_index < high) {
        quick_sort_recursive(numbers, pivot_index + 1, high);
    }
}

void quick_sort(int numbers[], size_t length) {
    if (length < 2) {
        return;
    }

    quick_sort_recursive(numbers, 0, length - 1);
}
```

## Getting Started

Make sure you have a C compiler installed, such as Clang or GCC.

**Compile:**

```bash
clang -std=c17 -Wall -Wextra -Wpedantic -Wconversion -g \
  -o quick-sort quick-sort.c
```

**Run:**

```bash
./quick-sort
```

### Example Output

Given the input array:

```c
int numbers[] = {3, 6, 8, 10, 1, 2, 1};
```

The program produces:

```text
=== Sorted Numbers ===
 1.    1
 2.    1
 3.    2
 4.    3
 5.    6
 6.    8
 7.   10
```

## Concepts Covered

- Arrays and pointer manipulation
- Functions and modular programming
- Recursion and divide-and-conquer
- Partitioning and pivot selection
- Comparison and swapping
- `size_t` and array indexing
- Time and space complexity
- In-place sorting algorithms

---

Built as a practical exercise in **Algorithms and C Programming**.
