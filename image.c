#include"image.h"
void I_print(color *img,int nbpixels){
    printf("[");
    for(int i=0;i<nbpixels-1;i++){
        C_print(img[i]);
        printf(",");
    }
    C_print(img[nbpixels-1]);
    printf("]");
}
void I_coef(color *img,int nbpixels, float coef){
    for(int i=0;i<nbpixels;i++){
        img[i]=C_multiply(img[i],coef);
    }
}
void I_negative(color *img,int nbpixels){
    for(int i=0;i<nbpixels;i++){
        img[i]=C_negative(img[i]);
    }
}
void I_permute(color *img,int nbpixels){
    for(int i=0;i<nbpixels;i++){
        img[i]=C_permute(img[i]);
    }
}
void I_grayScale(color *img,int nbpixels){
    for(int i=0;i<nbpixels;i++){
        img[i]=C_grayScale(img[i]);
    }
}
void I_threshold(color *img,int nbpixels, int th){
    for(int i=0;i<nbpixels;i++){
            int c= C_threshold(img[i],th);
            img[i]=C_new(c,c,c);
    }
}
void I_compose(color img1[], struct color img2[], int nb_pixels,color target){
    for(int i=0;i<nb_pixels;i++){
        if(C_areEqual(img1[i],target)){
            img1[i]=img2[i];
        }
    }
}
void I_addColor(color *img, int nb_pixels,color c){
    for (int i = 0; i < nb_pixels; i++){
        img[i]=C_addCoef(img[i],c,1);
    }
    
}
void I_gradient(color img_in[],color img_out[], int nb_pixels){
     struct color gray = C_new(127,127,127);
    img_out[0]=C_new(127,127,127);
    for(int i=1;i<nb_pixels;i++){
        img_out[i].red = img_in[i].red-img_in[i-1].red;
        img_out[i].green = img_in[i].green-img_in[i-1].green;
        img_out[i].blue = img_in[i].blue-img_in[i-1].blue;
        img_out[i]=C_addCoef(img_out[i],gray,1);
    }
 
}
color I_average(color img[], int nb_pixels, int fromhere,int nb_pixels_average){
    color res=C_new(0,0,0);
    for (int i = fromhere; i <fromhere+nb_pixels_average; i++){
        res.red +=img[i].red;
        res.green +=img[i].green;
        res.blue +=img[i].blue;
    }
    res.red =res.red/nb_pixels_average;
    res.green =res.green/nb_pixels_average;
    res.blue =res.blue/nb_pixels_average;
    return res;
}
void I_motionBlur(color img[],color img_out[],int nb_pixels, int strength){
    for (int i = 0; i < nb_pixels; i++){
        if(i+strength<=nb_pixels){
            img_out[i]=I_average(img,nb_pixels,i,strength);
        }
        else{
            int pa=nb_pixels-i;
            img_out[i]=I_average(img,nb_pixels,i,pa);
        }
    }
    
}
