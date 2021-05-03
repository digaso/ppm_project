#include "pixel.h"

PIXEL changePixel(PIXEL pixel)
{
  int g = 0.2126 * pixel.red + 0.7152 * pixel.green + 0.0722 * pixel.blue;

  return setPixel(g, g, g);
}
void addGrayColor(IMAGE newImg, IMAGE img)
{
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      newImg.matrix[j][i] = changePixel(img.matrix[j][i]);
    }
  }
}

int main(int argc, char const *argv[])
{
  IMAGE img = scanImage(0, argc, argv);
  IMAGE newImg = copyImage(img);
  addGrayColor(newImg, img);
  printImage(0, argc, argv, newImg);
  return 0;
}
