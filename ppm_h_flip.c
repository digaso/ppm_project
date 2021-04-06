#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

int main(int argc, char const *argv[])
{
  int l, c, i, j;
  int maxValue = 0;
  FILE *file;
  file = fopen(argv[1], "r+");
  char header[4];
  fscanf(file, "%s", header);
  int height = 0, width = 0;
  fscanf(file, "%d %d", &width, &height);
  fscanf(file, "%d", &maxValue);
  IMAGE img = setImage(header, height, width, maxValue);
  IMAGE newImg = setImage(header, height, width, maxValue);
  PIXEL newImg1[width][height];
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int r, g, b;
      fscanf(file, "%d %d %d", &r, &g, &b);
      img.matrix[j][i] = setPixel(r, g, b);
    }
  }
  for (int i = 0; i < height; i++)
  {
    for (int j = width; j > 0; j--)
    {
      newImg.matrix[width - j][i] = img.matrix[j - 1][i];
    }
  }
  printImage(newImg);
  fclose(file);
  return 0;
}