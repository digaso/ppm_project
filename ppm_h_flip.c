#include <stdio.h>
#include "pixel.h"

void flipHorizontal(IMAGE img, IMAGE newImg)
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
  IMAGE img = scanImage(0, argc, argv);
  IMAGE newImg = copyImage(img);
  flipHorizontal(img, newImg);
  printImage(0, argc, argv, newImg);
  return 0;
}