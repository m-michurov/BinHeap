#include "binheap.h"

static void sift(
        Heap * heap,
        size_t i)
{
    static size_t min_child;
    static int buff;

    while (i * 2 + 1 < heap->heap_size) {

        if ((i * 2 + 1 == heap->heap_size - 1) || (heap->key[heap->array[i * 2 + 1]] < heap->key[heap->array[i * 2 + 2]]))
            min_child = i * 2 + 1;

        else
            min_child = i * 2 + 2;

        if (heap->key[heap->array[i]] > heap->key[heap->array[min_child]]) {
            buff = heap->array[i];
            heap->array[i] = heap->array[min_child];
            heap->array[min_child] = buff;

            heap->index[heap->array[i]] = i;
            heap->index[heap->array[min_child]] = min_child;

            i = min_child;
        }

        else
            break;
    }
}

Heap * BuildHeap(
        int * array,
        int * key,
        int * index,
        const size_t size)
{
    Heap * new_heap = (Heap *) malloc(sizeof(Heap));

    if (new_heap == NULL || array == NULL || key == NULL || index == NULL)
        return NULL;

    new_heap->key = key;
    new_heap->array = array;
    new_heap->heap_size = size;
    new_heap->index = index;

    for (long long int i = new_heap->heap_size / 2 - 1; i >= 0; i--) {
        sift(new_heap, (unsigned int) i);
    }

    return new_heap;
}


int ExtractMin(
        Heap * heap)
{
    if (heap == NULL)
        return -1;

    int min = heap->array[0];

    heap->array[0] = heap->array[--heap->heap_size];

    heap->index[min] = heap->heap_size;

    sift(heap, 0);

    return min;
}


int DecreaseKey(
        Heap * heap,
        size_t element_value,
        int key)
{
    static int buff;

    if (key >= heap->key[element_value]) {
        return -1;
    }
    heap->key[element_value] = key;

    size_t element_index = (size_t) heap->index[element_value];

    while (element_index > 0 && heap->key[heap->array[(element_index - 1) / 2]] > heap->key[heap->array[element_index]]) {
        buff = heap->array[element_index];
        heap->array[element_index] = heap->array[(element_index - 1) / 2];
        heap->array[(element_index - 1) / 2] = buff;

        heap->index[heap->array[element_index]] = element_index;
        heap->index[heap->array[(element_index - 1) / 2]] = (element_index - 1) / 2;

        element_index = (element_index - 1) / 2;
    }

    return 0;
}