#include <stdio.h>
#include <string.h>
#include "schema.h"

int main() {
  struct test a;
  memcpy(a.test, "Hello", 5);
  a.foo = 42;
  a.bar = 0.1234;

  FILE *f;
  f = fopen("test.obj", "w");
  fwrite(&a, sizeof(a), 1, f);
  fclose(f);

  // Read it back
  struct test b;
  f = fopen("test.obj", "r");
  fread(&b, sizeof(b), 1, f);

  printf("test %s, foo %d, bar %f\n", b.test, b.foo, b.bar);
}
