#include"color.h"
void C_print(color c){
    printf("(%d,%d,%d)",c.red,c.green,c.blue);
}
static int clamp(int n){
    if(n>255){
        return 255;
    }
    else if (n<0){
        return 0;
    }
    return n;
}
color C_new(int r, int g, int b){
    color c;
    c.red=clamp(r);
    c.green=clamp(g);
    c.blue=clamp(b);
    return c;
}

color C_multiply(color c, float coef){
    return C_new(coef*c.red,coef*c.green,coef*c.blue);
}
color C_negative(color c){
    return C_new(255-c.red,255-c.green,255-c.blue);
}
color C_permute(color c){
    return C_new(c.green,c.blue,c.red);
}
int C_intensity(color c){
    return (c.red+c.green+c.blue)/3;
}
color C_grayScale(color c){
    int gray=C_intensity(c);
    return C_new(gray,gray,gray);
}
int C_threshold(color c, int th){
    if(C_intensity(c)>th){
        return 255;
    }
    return 0;
}
int C_areEqual(color c1, color c2){
    if((c1.red==c2.red)&&(c1.green==c2.green)&&(c1.blue==c2.blue)){
        return 1;
    }
    return 0;
}
color C_addCoef(color c1,color c2, float coef){
    color coefTimesC2;
    coefTimesC2.red = c2.red*coef;
    coefTimesC2.green = c2.green*coef;
    coefTimesC2.blue = c2.blue*coef;
    return C_new((c1.red+coefTimesC2.red),(c1.green+coefTimesC2.green),(c1.blue+coefTimesC2.blue));
}