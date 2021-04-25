#include <stdio.h>

#include "sort.h"
#include "timecheck.h"
#include "arrayio.h"

int main( void )
{
    int _arr_size;
    scanf("%d", &_arr_size);
    const int arr_size = _arr_size;
    int arr[arr_size];

    init_random(arr, arr_size, 500);
    print_random_subarray(arr, arr_size, arr_size); 
    heap_sort(arr, arr_size);
    print_random_subarray(arr, arr_size, arr_size);
}
