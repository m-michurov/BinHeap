#pragma once

#ifndef BINHEAP_BINHEAP_H
#define BINHEAP_BINHEAP_H

#include <stdlib.h>

typedef struct {
    int * array;
    size_t heap_size;
    int * key;
} Heap;

Heap * BuildHeap(
        int * array,
        int * key,
        size_t size);

int ExtractMin(
        Heap * heap);

int DecreaseKey(
        Heap * heap,
        size_t i,
        int key);

#endif
