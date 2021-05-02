#include <stdio.h>
#include "pixel.h"

void flipVertical(IMAGE img, IMAGE newImg)
{
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      newImg.matrix[j][i] = img.matrix[j][img.height - i];
    }
  }
}

int main(int argc, char const *argv[])
{
  IMAGE img = scanImage(argc, argv);
  IMAGE newImg = setImage(img.magicNumber, img.height, img.width, img.maxValue);
  flipVertical(img, newImg);
  printImage(argc, argv, newImg);
  return 0;
}
