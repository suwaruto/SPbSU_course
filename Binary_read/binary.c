#include<stdio.h>

struct Person
{
  char name[40];
  int  age;
};

void read()
{
  // And print!
  FILE *fo = fopen("1.bin", "rb");
  struct Person ps[2];

  fread(ps, sizeof(struct Person), 2, fo);

  fclose(fo);

  for (int i = 0; i < 2; i++)
    printf("Name: %s\nAge: %d\n----------\n", ps[i].name, ps[i].age);
}

void write()
{
  struct Person ps[] = { {"Оля", 25}, {"Катя", 35} };

  FILE *fo = fopen("1.bin", "wb");

  fwrite(ps, sizeof(struct Person), 2, fo);
  fwrite(ps, sizeof(ps), 1, fo);

  fclose(fo);
}

int main(int argc, char *argv[])
{
  switch(argv[1][0])
  {
    case 'w':
      puts("w");
      write();
      break;
    case 'r':
      puts("r");
      read();
      break;
    default:
      puts("Error in command line");
  }

  return 0;
}
