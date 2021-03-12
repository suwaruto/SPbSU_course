#include <stdio.h>
#include <time.h>

//sqrt(L3 (KiB) * 1024 \ 4) 
#define N 15000
float m[N][N];

int main()
{
  float a = 0.0;

  clock_t s, f;
  s = clock();

  for(int n = 0; n < 100; ++n)
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
        a += m[j][i];

  f = clock();

  printf("%f: %f ms\n", a, ((double)(f - s)) * 1000.0 / CLOCKS_PER_SEC);

  return 0;
}
