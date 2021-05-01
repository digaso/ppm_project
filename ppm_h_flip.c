#include <stdio.h>
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
  IMAGE img = scanImage(argc, argv);
  IMAGE newImg = setImage(img.magicNumber, img.height, img.width, img.maxValue);
  flip(img, newImg);
  printImage(argc, argv, newImg);
  return 0;
}