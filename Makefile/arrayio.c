#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_random( int *arr, int arr_size, int higher_bound )
{
    srand(time(NULL));
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % higher_bound;
}

int print_random_subarray( int *arr, int arr_size, int subarr_size )
{
    srand(time(NULL));

    if (subarr_size > arr_size)
    {
        fprintf(stderr, "Subarray size exceeds array size!");
        return 1;
    }
        
    int start = rand() % (arr_size - subarr_size + 1);
    for (int i = start; i < start + subarr_size; i++)
        printf("%d ", arr[i]);
    putc('\n', stdout);
    return 0; 
}
