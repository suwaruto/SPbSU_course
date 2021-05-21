#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef CMP
    #define CMP(X, Y) ((X) > (Y)? 1: 0)
#endif

// void bubble_sort( int *arr, int arr_size );
void bubble_sort( void *base, size_t num, size_t size, 
    int (*compare)(const void*, const void*) );
//void insertion_sort( int *arr, int arr_size );
void insertion_sort( void *base, size_t num, size_t size, 
    int (*compare)(const void*, const void*) );
// void merge_sort( int *arr, int arr_size );
void merge_sort( void *base, size_t num, size_t size, 
    int (*compare)(const void*, const void*) );
void heap_sort( int *arr, int arr_size );
void quicksort( int *arr, int arr_size );

/*void swap( int *var1, int *var2 )
{
   int temp = *var1;
   *var1 = *var2;
   *var2 = temp;
}*/

void swap( void *var1, void *var2, size_t size )
{
    void *temp = malloc(size);
    memcpy(temp, var1, size);
    memcpy(var1, var2, size);
    memcpy(var2, temp, size);
    free(temp);
}

/*void bubble_sort( int *arr, int arr_size )
{
    for (int unsorted = arr_size; unsorted > 0; unsorted--)
        for (int i = 0; i < unsorted - 1; i++)
            if (CMP(arr[i], arr[i + 1]))
                swap(&arr[i], &arr[i + 1]);
}*/

void bubble_sort( void *base, size_t num, size_t size, 
    int (*compare)(const void*, const void*) )
{
    for (int unsorted = num; unsorted > 0; unsorted--)
        for (int i = 0; i < unsorted - 1; i++)
            if (compare((char *)base + i * size, 
                (char *)base + (i + 1) * size) == 1)
                swap((char *)base + i * size, (char *)base + (i + 1) * size,
                    size);
}

/*void insertion_sort( int *arr, int arr_size )
{
    for (int sorted = 1; sorted < arr_size; sorted++)
    {
        int k = sorted;
        while (k > 0 && !CMP(arr[k], arr[k - 1]))
        {
            swap(&arr[k], &arr[k - 1]);
            k--;
        }
    }
}*/

void insertion_sort( void *base, size_t num, size_t size, 
    int (*compare)(const void*, const void*) )
{
    for (int sorted = 1; sorted < num; sorted++)
    {
        int k = sorted;
        while (k > 0 && compare((char *)base + k * size, 
            (char *)base + (k - 1) * size) != 1)
        {
            swap((char *)base + k * size, (char *)base + (k - 1) * size, size);
            k--;
        }
    }
}

/*void merge( int *arr, int first, int middle, int last, int *aux )
{
    for (int k = first; k <= last; k++)
        aux[k] = arr[k];

    int i = first, j = middle + 1;
    for (int k = first; k <= last; k++)
        if ( i > middle )
            arr[k] = aux[j++];
        else if (j > last)
            arr[k] = aux[i++];
        else if (CMP(aux[i], aux[j]))
            arr[k] = aux[j++];
        else
            arr[k] = aux[i++];
}*/

/*void _merge_sort( int *arr, int first, int last, int *aux )
{
    if (first >= last) return;
    int middle = (first + last) >> 1;
    _merge_sort(arr, first, middle, aux);
    _merge_sort(arr, middle + 1, last, aux);
    merge(arr, first, middle, last, aux);
}*/

/*void merge_sort( int *arr, int arr_size )
{
    const int aux_size = arr_size;
    int aux[aux_size];
    _merge_sort(arr, 0, arr_size - 1, aux);
}*/

void merge( void *base, size_t first, size_t middle, size_t last, size_t size,
    int (*compare)(const void *, const void *), void *aux)
{
    /*for (size_t k = first * size; k <= last * size; k++)
        *(aux + k) = *(base + k);*/

    memcpy((char *)aux + first * size, (char *)base + first * size, (last - first + 1) * size);

    size_t i = first, j = middle + 1;
    for (size_t k = first; k <= last; k++)
        if (i > middle)
            memcpy((char *)base + k * size, (char *)aux + (j++) * size, size);
        else if (j > last)
            memcpy((char *)base + k * size, (char *)aux + (i++) * size, size);
        else if (compare((char *)aux + i * size, (char *)aux + j * size) == 1)
            memcpy((char *)base + k * size, (char *)aux + (j++) * size, size);
        else
            memcpy((char *)base + k * size, (char *)aux + (i++) * size, size);
}

void _merge_sort( void *base, size_t first, size_t last, size_t size,
    int (*compare)(const void *, const void *), void *aux )
{
    if (first >= last) return;
    size_t middle = (first + last) >> 1;
    _merge_sort(base, first, middle, size, compare, aux);
    _merge_sort(base, middle + 1, last, size, compare, aux);
    merge(base, first, middle, last, size, compare, aux);
}

void merge_sort( void *base, size_t num, size_t size, 
    int (*compare)(const void*, const void*) )
{
    const size_t num_aux = size * num;
    char aux[num_aux];
    _merge_sort(base, 0, num - 1, size, compare, aux);
}

/*void _quicksort( int *arr, int first, int last )
{
    if (first >= last)
        return;
    int pivot = (arr[first] + arr[last]) >> 1;
    int i = first, j = last;
    while (1)
    {
        while (CMP(pivot, arr[i]))
            i++;
        while (CMP(arr[j], pivot))
            j--;
        if (i >= j)
            break;
        swap(&arr[i++], &arr[j--]);
    }
    _quicksort(arr, first, j);
    _quicksort(arr, j + 1, last);
}

void quicksort( int *arr, int arr_size )
{
    _quicksort(arr, 0, arr_size - 1);
}

void siftDown( int *arr, int start, int end )
{
    int root = start, left = (root << 1) + 1, right = left + 1;
    while (left <= end)
    {
        int swp = root;
        if (CMP(arr[left], arr[swp]))
            swp = left;
        if (right <= end && CMP(arr[right], arr[swp]))
            swp = right;
        if (swp == root)
            return;
        else
        {
            swap(arr + swp, arr + root);
            root = swp;
            left = (root << 1) + 1;
            right = left + 1;
        }
    }
}

void heapify( int *arr, int arr_size )
{
    for (int heap_border = (arr_size - 1) >> 1; heap_border >= 0; heap_border--)
        siftDown(arr, heap_border, arr_size - 1);
}

void heap_sort( int *arr, int arr_size )
{
    heapify(arr, arr_size);
    for (int unsorted = arr_size - 1; unsorted > 0; unsorted--)
    {  
        swap(&arr[0], &arr[unsorted]);
        siftDown(arr, 0, unsorted - 1);
    }
}*/
