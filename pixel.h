#include <string.h>
typedef struct
{
  int red;
  int green;
  int blue;
} PIXEL;

typedef struct
{
  char *magicNumber;
  int maxValue;
  int height;
  int width;
  PIXEL **matrix;
} IMAGE;



IMAGE setImage(char *magicNumber, int height, int width, int maxValue){
  IMAGE img;
  img.magicNumber = magicNumber;
  img.height = height;
  img.width = width;
  img.maxValue = maxValue;
  img.matrix = malloc(width*sizeof(PIXEL*));
  for (int i = 0; i < width; i++)
  {
    img.matrix[i] = malloc(width*sizeof(PIXEL));
  }
  return img;
}

void printImage(IMAGE img){
  printf("%s\n",img.magicNumber);
  printf("%d %d\n", img.width, img.height);
  printf("%d\n",img.maxValue);
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      printf("%d %d %d\n", img.matrix[j][i].red, img.matrix[j][i].green,img.matrix[j][i].blue);
    }
  }
  

}

PIXEL setPixel(int r, int g, int b){
  PIXEL p;
  p.red = r;
  p.green = g;
  p.blue = b;
  return p;
}
