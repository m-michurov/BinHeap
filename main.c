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

    for (size_t t = 0; t < 42; t++) {
        printf("Test %u/%d: ", t + 1, 42);

        count = 10 + (unsigned int) rand() % 990;

        array = malloc(count * sizeof(int));
        key = malloc(count * sizeof(int));

        if (key == NULL || array == NULL)
            return -12;

        for (int k = 0; k < count; k++)
            array[k] = k;

        for (size_t k = 0; k < count; k++)
            key[k] = rand();

        Heap * heap = BuildHeap(array, key, count);

        for (int k = 0; k < count; k++)
            DecreaseKey(heap, (size_t) k, k);

        int prev = INT_MIN;
        int cur = 0;

        for (int k = 0; k < count; k++) {
            cur = heap->key[ExtractMin(heap)];
            if (cur < prev) {
                puts("FAILED");
                printf("count %d  k %d prev %d  cur %d\n", count, k, prev, cur);
                free(array);
                free(key);
                free(heap);
                return 0;
            } else {
                prev = cur;
            }
        }


        puts("PASSED");

        free(array);
        free(key);
        free(heap);
    }

    return 0;
}


int main(
        void)
{
    test();

    return 0;
}