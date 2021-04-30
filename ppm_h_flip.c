#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

void flip(IMAGE img, IMAGE newImg)
{
  for (int i = 0; i < img.height; i++)
  {
    for (int j = img.width; j > 0; j--)
    {
      newImg.matrix[img.width - j][i] = img.matrix[j - 1][i];
    }
  }
}
int main(int argc, char const *argv[])
{

  int height = 0, width = 0;
  int maxValue = 0;
  char header[4];
  FILE *file;
  file = fopen(argv[1], "r+");
  fscanf(file, "%s", header);
  fscanf(file, "%d %d", &width, &height);
  fscanf(file, "%d", &maxValue);
  IMAGE img = setImage(header, height, width, maxValue);
  IMAGE newImg = setImage(header, height, width, maxValue);
  readImageFile(img, file);
  flip(img, newImg);
  printImage(newImg);
  fclose(file);
  return 0;
}