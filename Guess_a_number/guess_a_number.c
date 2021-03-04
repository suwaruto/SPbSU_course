#include <stdio.h>

int main( void )
{
    int lower_bound = 0;
    int upper_bound = 1000;
    int avg = (lower_bound + upper_bound) >> 1;
    char c;
    puts("Come up with a number in range [0..1000] and this little program will try to guess it.");
    while (lower_bound < upper_bound)
    {
        avg = (lower_bound + upper_bound) >> 1;
        printf("Is your number greater than %d?[Y/N]", avg);
        c = getchar();
        getchar();
        switch (c)
        {
            case 'Y':
            case 'y':
                lower_bound = avg + 1;
                break;
            case 'N':
            case 'n':
                upper_bound = avg;
                break;
            default:
                puts("Command not understood. Repeat.");
        }
    }
    if (lower_bound == upper_bound)
        printf("Your number is %d\n", lower_bound);
    else
        puts("You are contradictory! This makes the program sad (-_-)");
    return 0;
}
