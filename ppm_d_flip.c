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

  IMAGE img = scanImage(0, argc, argv);
  IMAGE newImg = copyImage(img);
  IMAGE aux = copyImage(img);

  flipVertical(img, aux);
  flipHorizontal(aux, newImg);
  printImage(0, argc, argv, newImg);
  return 0;
}
