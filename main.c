#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "binheap.h"


int test(
        void)
{
    unsigned int count;

    srand(time(NULL));

    int * array;
    int * key;
    int * index;

    for (size_t t = 0; t < 255; t++) {
        //printf("Test %u/%d: ", t + 1, 255);

        count = 5000;

        array = malloc(count * sizeof(int));
        key = malloc(count * sizeof(int));
        index = malloc(count * sizeof(int));

        if (key == NULL || array == NULL || index == NULL)
            return -12;

        for (int k = 0; k < count; k++)
            array[k] = index[k] = k;

        for (size_t k = 0; k < count; k++)
            key[k] = rand();

        Heap * heap = BuildHeap(array, key, index, count);

        for (int k = 0; k < count; k++)
            DecreaseKey(heap, (size_t) k, rand());

        int prev = ExtractMin(heap);
        int cur = 0;

        for (int k = 1; k < count; k++) {
            cur = ExtractMin(heap);
            if (heap->key[cur] < heap->key[prev] || heap->index[cur] < heap->heap_size) {
                puts("FAILED");
                printf("count %d  k %d prev %d  cur %d prev_key %d  cur_key %d heap_size %d index %d\n",
                        count, k, prev, cur, heap->key[prev], heap->key[cur], heap->heap_size, heap->index[cur]);
                free(array);
                free(key);
                free(index);
                free(heap);
                return 1;
            } else {
                prev = cur;
            }
        }


        //puts("PASSED");

        free(array);
        free(key);
        free(index);
        free(heap);
    }

    return 0;
}


int main(
        void) {
    size_t fail = 0;
    for (size_t k = 0; k < 9; k++) {
        printf("%d\n", k);
        fail += test();
    }
/*
    unsigned int count = 10;
    int new_key = 0;

    srand(time(NULL));

    int *array;
    int *key;
    int *index;


    //count = 10 + (unsigned int) rand() % 5000;

    array = malloc(count * sizeof(int));
    key = malloc(count * sizeof(int));
    index = malloc(count * sizeof(int));

    if (key == NULL || array == NULL || index == NULL)
        return -12;

    for (int k = 0; k < count; k++)
        array[k] = index[k] = k;

    for (size_t k = 0; k < count; k++)
        key[k] = rand() % 10 + 10;

    Heap * heap = BuildHeap(array, key, index, count);

    for (int k = 0; k < count; k++) {
        printf("Old key for %d : %d, enter new key:\n", k, heap->key[k]);
        scanf("%d", &new_key);
        DecreaseKey(heap, (size_t) k, new_key);
    }

    int prev = INT_MIN;
    int cur = 0;

    for (int k = 0; k < count; k++) {
        cur = ExtractMin(heap);
        printf("%d\t%d\n", cur, heap->key[cur]);
    }
*/
    printf("%s", fail == 0 ? ":-)" : ":-(");

    return 0;
}