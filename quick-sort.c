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

int main(void) {
    int numbers[] = {3, 6, 8, 10, 1, 2, 1};

    const size_t length = sizeof(numbers) / sizeof(numbers[0]);

    quick_sort(numbers, length);

    printf("=== Sorted Numbers ===\n");

    for (size_t i = 0; i < length; i++) {
        printf("%2zu. %4d\n", i + 1, numbers[i]);
    }

    return 0;
}
