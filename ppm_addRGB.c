#include "pixel.h"

int getAdditive(char s[])
{
  int value = 0;
  char *p = s;
  if (s[0] == '-')
  {
    p++;
    value = atoi(p) * -1;
    return value;
  }
  else if (s[0] == '+')
  {
    p++;
    value = atoi(p);
    return value;
  }
  return 0;
}

int checkValue(int value, int maxValue)
{

  int res = value;
  if (value < 0)
    res = 0;
  else if (value > maxValue)
  {
    res = maxValue;
  }
  return res;
}

PIXEL changePixel(int r, int g, int b, PIXEL pixel, int maxValue)
{
  int newR = checkValue(pixel.red + r, maxValue);
  int newG = checkValue(pixel.green + g, maxValue);
  int newB = checkValue(pixel.blue + b, maxValue);

  return setPixel(newR, newG, newB);
}
void addColor(int r, int g, int b, IMAGE img)
{
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      img.matrix[j][i] = changePixel(r, g, b, img.matrix[j][i], img.maxValue);
    }
  }
}

int main(int argc, char const *argv[])
{
  char r[5], g[5], b[5];
  strcpy(r, argv[1]);
  strcpy(g, argv[2]);
  strcpy(b, argv[3]);

  IMAGE img = scanImage(3, argc, argv);
  IMAGE newImg = copyImage(img);
  addColor(getAdditive(r), getAdditive(g), getAdditive(b), newImg);
  printImage(3, argc, argv, newImg);
  return 0;
}
