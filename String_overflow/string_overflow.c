#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[40] = "Hello, ";
    char name[20];
    puts("What is your name?");

    // scanf %s -- string, %[^\n]s -- string with spaces (multiple words)
    // Fix format string to also avoid overflow.
    // See man 3 scanf or https://www.man7.org/linux/man-pages/man3/scanf.3.html#EXAMPLES

    // bad! 
    // scanf("%[^\n]s", name);

    // better
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0;

    strcat(s, name);
    strcat(s, "!");
    puts(s);
    return 0;
}
