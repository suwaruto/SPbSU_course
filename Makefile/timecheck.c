#include <stdio.h>
#include <time.h>

double timecheck( void (*function_to_execute)(int *, int), int *arg1, int arg2 )
{
    clock_t t1 = clock();
    function_to_execute(arg1, arg2);
    clock_t t2 = clock(); 
    return (t2 - t1) / (double)CLOCKS_PER_SEC;
}

/* //usefulness of such function is doubtful 
char *timecheck_str( void (*function_to_execute)(*int, int), arg1, arg2 )
{
    double f = timecheck(function_to_execute, arg1, arg2);
     
}
*/

void sample( int *arg1, int arg2 )
{
    for (int i = 0; i < 1000000000; i++)
        *arg1 += arg2;
}
