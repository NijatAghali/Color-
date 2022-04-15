#include <stdio.h>
#include "color.h"

void I_print(color *img,int nbpixels);
void I_coef(color *img,int nbpixels, float coef);
void I_negative(color *img,int nbpixels);
void I_permute(color *img,int nbpixels);
void I_grayScale(color *img,int nbpixels);
void I_threshold(color *img,int nbpixels, int th);
void I_compose(color *img1, color *img2, int nb_pixels,color target);
void I_addColor(color *img, int nb_pixels,color c);
void I_gradient(color img_in[],color img_out[], int nb_pixels);
color I_average(color img[], int nb_pixels, int fromhere,int nb_pixels_average);
void I_motionBlur(color img[],color img_out[],int nb_pixels, int strength);