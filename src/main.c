#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ppm.h"
#include"transformations.h"

int main(int argc,char *argv[])
{
    char *inname,*outname,*opt;
    inname  = argv[1];
    outname = argv[2];
    opt     = argv[3]+4;
    
    printf("%s\n%s\n%s\n",inname,outname,opt);

    PPMimg *img = readPPM(inname);

    if(!strcmp(opt,"interactive"))
    {
        char ch;
        while(1)
        {
            printf("0. Exit\n1. Greyscale\n2. Colour invert\n");
            printf("Enter choice:");
            scanf(" %c",&ch);
            printf("%d\n",(int)ch);
            switch(ch)
            {
                case '1' : printf("Converting...\n");greyscale(img);printf("Writing...\n");writePPM(outname,img);break;
                case '2' : printf("Converting...\n");invert(img);printf("Writing...\n");writePPM(outname,img);break;
                case '0' : exit(0);
                default : printf("Wrong option\n");
            }
        }
    }
    else
    {
        for(int i=0 ; opt[i]!='\0' ; i++)
        {
            switch(opt[i])
            {
                case '1' : greyscale(img);break;
                case '2' : invert(img);break;
                default : printf("Wrong option given, exiting...");exit(0);
            }
        }
        writePPM(outname,img);
    }
    return 0;
}