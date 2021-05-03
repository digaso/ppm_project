#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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

IMAGE setImage(char *magicNumber, int height, int width, int maxValue)
{
  IMAGE img;
  img.magicNumber = malloc(3);
  strcpy(img.magicNumber, magicNumber);
  img.height = height;
  img.width = width;
  img.maxValue = maxValue;
  img.matrix = malloc(width * sizeof(PIXEL *));
  for (int i = 0; i < width; i++)
  {
    img.matrix[i] = malloc(height * sizeof(PIXEL));
  }
  return img;
}

IMAGE copyImage(IMAGE img){
  IMAGE newImg = setImage(img.magicNumber, img.height, img.width, img.maxValue);
  newImg.matrix = img.matrix;
  return newImg;
}

PIXEL setPixel(int r, int g, int b)
{
  PIXEL p;
  p.red = r;
  p.green = g;
  p.blue = b;
  return p;
}

void readImageFile(IMAGE img, FILE *file)
{
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      int r, g, b;
      fscanf(file, "%d %d %d", &r, &g, &b);
      img.matrix[j][i] = setPixel(r, g, b);
    }
  }
}

void readImage(IMAGE img)
{
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      int r, g, b;
      scanf("%d %d %d", &r, &g, &b);
      img.matrix[j][i] = setPixel(r, g, b);
    }
  }
}

IMAGE readIO()
{
  IMAGE img;
  int maxValue, height, width;
  char header[3];
  scanf("%s", header);
  scanf("%d %d", &width, &height);
  scanf("%d", &maxValue);
  img = setImage(header, height, width, maxValue);
  readImage(img);
  return img;
}

IMAGE readFile(FILE *file)
{

  IMAGE img;
  int maxValue, height, width;
  char header[3];
  fscanf(file, "%s", header);
  fscanf(file, "%d %d", &width, &height);
  fscanf(file, "%d", &maxValue);
  img = setImage(header, height, width, maxValue);
  readImageFile(img, file);
  return img;
    
}

IMAGE scanImage(int argn, int argc, char const *argv[])
{
  FILE *file;
  IMAGE img;
  if (argc > argn + 1)
  {
    file = fopen(argv[argn + 1], "r+");
    if(file == NULL){
      perror("Error");
      exit(1);
    }
    img = readFile(file);
    fclose(file);
  }
  else if (argc == 1)
  {
    img = readIO();
  }
  return img;
}

void printToFile(IMAGE img, FILE *file){
  fprintf(file ,"%s\n", img.magicNumber);
  fprintf(file ,"%d %d\n", img.width, img.height);
  fprintf(file ,"%d\n", img.maxValue);
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      fprintf(file,"%d %d %d\n", img.matrix[j][i].red, img.matrix[j][i].green, img.matrix[j][i].blue);
    }
  }
}

void printImageIO(IMAGE img)
{
  printf("%s\n", img.magicNumber);
  printf("%d %d\n", img.width, img.height);
  printf("%d\n", img.maxValue);
  for (int i = 0; i < img.height; i++)
  {
    for (int j = 0; j < img.width; j++)
    {
      printf("%d %d %d\n", img.matrix[j][i].red, img.matrix[j][i].green, img.matrix[j][i].blue);
    }
  }
}

void printImage(int argn, int argc, char const *argv[], IMAGE img){
  FILE *file;
  if(argc > argn + 2){
    file = fopen(argv[argn + 2], "w");
    printToFile(img, file);
    fclose(file);
  }else{
    printImageIO(img);
  }
}
