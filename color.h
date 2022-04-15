#ifndef COLOR_H
#define COLOR_H
#include<stdio.h>
typedef struct color
{
    int red;
    int green;
    int blue;
}color;

void C_print(color c);
color C_new(int red, int green, int blue);
color C_multiply(color c, float coef);
color C_negative(color c);
color C_permute(color c);
int C_intensity(color c);
color C_grayScale(color c);
int C_threshold(color c, int th);
int C_areEqual(color c1,color c2);
color C_addCoef(color c1,color c2, float coef);
#endif