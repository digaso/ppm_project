#include "pixel.h"

int changePixel(PIXEL pixel)
{
  int g = 0.2126 * pixel.red + 0.7152 * pixel.green + 0.0722 * pixel.blue;

  return g;
}

void blackWhite(IMAGE img, IMAGE newImg, int threshold)
{
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      int g = changePixel(img.matrix[j][i]), color = 0;

      if (g > threshold)
      {
        color = img.maxValue;
      }
      newImg.matrix[j][i] = setPixel(color, color, color);
    }
  }
}

int main(int argc, char const *argv[])
{
  int threshold = atoi(argv[1]);
  IMAGE img = scanImage(1, argc, argv);
  IMAGE newImg = copyImage(img);
  blackWhite(img, newImg, threshold);
  printImage(1, argc, argv, newImg);
  return 0;
}
