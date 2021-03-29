#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  char *src;

  scanf("%s", src);
  FILE *file = fopen(src, "r+");
  if (file == NULL)
  {
    printf("Error! Could not open file\n");
    exit(-1);
  }

  return 0;
}
