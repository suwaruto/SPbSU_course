#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    // ....
    int tot = 0; // ...really calculate total length or args + spaces between using strlen fnuction
    for (int i = 0; i < argc; i++)
       tot += strlen(argv[i]) + 1; 
    printf("%d\n", tot); 
    // ....
    char a[tot];
    a[0] = 0;

    // "./a.out" "1" "2" "3" "456" -- strcat --> "./a.out 1 2 3 456"
    for (int i = 0; i < argc; i++)
    {
        strcat(a, argv[i]);
        strcat(a, " ");
    }
    puts(a);
    return 0;
}
