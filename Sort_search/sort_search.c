#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int cmp_cnt = 0;

struct Person
{
  char name[40];
  int  age;
};

void print_person(struct Person *p)
{
  printf("%s, %d years old\n", p->name, p->age);
}

void print_persons(struct Person ps[], size_t person_number)
{
  struct Person *p = ps;
  puts("Persons:");
  while(person_number--)
    print_person(p++);
}

int compare_persons(const void *p1v, const void *p2v)
{
  const struct Person *p1 = (const struct Person*) p1v,
                      *p2 = (const struct Person*) p2v;
    cmp_cnt++;
  if(p1->age < p2->age)
    return -1;
  else if(p1-> age > p2->age)
    return 1;
  else
    return 0;

}

int main()
{
  struct Person ps[] = {
    {"Катя", 35},
    {"Оля", 25},
    {"Таня", 37},
    {"Наташа", 20},
    {"Аня", 19},
    {"Петя", 21},
    {"Дима", 40},
    {"Вася", 33},
    {"Олег", 22},
    {"Витя", 27}
  };

  print_persons(ps, 10);
  cmp_cnt = 0;
  insertion_sort(ps, 10, sizeof(struct Person), compare_persons);
  print_persons(ps, 10);
  printf("cmp_cnt == %d\n", cmp_cnt);
  cmp_cnt = 0;

  struct Person query = {"", 35};
  puts("Person of 35 y.o.");
  print_person(
    bsearch(&query, ps, 10, sizeof(struct Person), compare_persons)
  );

  return 0;
}
