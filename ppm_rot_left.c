#include "pixel.h"

void rotate(IMAGE img, IMAGE newImg)
{
  for (int i = 0; i < newImg.height; i++)
  {
    for (int j = 0; j < newImg.width; j++)
    {
      newImg.matrix[j][i] = img.matrix[i][j];
    }
  }
}

int main(int argc, char const *argv[])
{
  IMAGE img = scanImage(0, argc, argv);
  IMAGE newImg = setImage(img.magicNumber, img.width, img.height, img.maxValue);
  rotate(img, newImg);
  printImage(0, argc, argv, newImg);

  return 0;
}
