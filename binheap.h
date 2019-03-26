#pragma once

#ifndef BINHEAP_BINHEAP_H
#define BINHEAP_BINHEAP_H

#include <stdlib.h>

typedef struct {
    int * array; // values are expected to be in range 0..heap_size
    size_t heap_size;
    int * key;
    int * index;
} Heap;

Heap * BuildHeap(
        int * array,
        int * key,
        int * index,
        size_t size);

int ExtractMin(
        Heap * heap);

int DecreaseKey(
        Heap * heap,
        size_t element_value,
        int key);

#endif
