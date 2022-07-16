#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE blue= image[i][j].rgbtBlue;
            BYTE green= image[i][j].rgbtGreen;
            BYTE red= image[i][j].rgbtRed;
            BYTE avg= (BYTE)((blue+green+red)/3);
            image[i][j].rgbtBlue=avg;
            image[i][j].rgbtGreen=avg;
            image[i][j].rgbtRed=avg;
        }
        
    }
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            RGBTRIPLE temp;
            temp=image[i][j];
            image[i][j]=image[i][width-j];
            image[i][width-j]=temp;
        }
        
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // for the inner rectangle
    for (int i = 1; i < (height-1); i++)
    {
        for (int j = 1; j < (width-1); i++)
        {
            BYTE sumr=0;
            BYTE sumg=0;
            BYTE sumb=0;
            for (int k = i-1; k < (i+2); k++)
            {
                for (int l = j-1; l < (j+2); l++)
                {
                    sumr=sumr+(image[k][l].rgbtRed);
                    sumg=sumg+(image[k][l].rgbtGreen);
                    sumb=sumb+(image[k][l].rgbtBlue);
                }
                
            }
            image[i][j].rgbtBlue=(BYTE)(sumb/9);
            image[i][j].rgbtGreen=(BYTE)(sumg/9);
            image[i][j].rgbtRed=(BYTE)(sumr/9);
        }
        
    }
    //for the first row.
    /*void edgeblur(int side);
    void edgeblur(int side){
        int master;
        int oinvalue;
        if(side==1){master=width-2;oinvalue=0;}
        if(side==2){master=width-2;oinvalue=height-2;}
        if(side==3){master=height-2;oinvalue=0;}
        if(side==4){master=height-2;oinvalue=width-2;}

    for (int m = 1; m < master; m++)
    {
        BYTE sumr=0;
        BYTE sumg=0;
        BYTE sumb=0;
        for (int n = m-1; n < m+2; n++)
        {
            for (int o = oinvalue; o < oinvalue+2; o++)
            {
                if (side==1 || side==2){
                sumr=sumr+image[o][n].rgbtRed;
                sumg=sumg+image[o][n].rgbtGreen;
                sumb=sumb+image[o][n].rgbtBlue;
                }
                else{
                    sumr=sumr+image[n][o].rgbtRed;
                    sumg=sumg+image[n][o].rgbtGreen;
                    sumb=sumb+image[n][o].rgbtBlue;
                }
            }
            
        }
        RGBTRIPLE temp={(BYTE)(sumb/6),(BYTE)(sumg/6),(BYTE)(sumr/6)};
        if (side==1){image[0][m]=temp;}
        if (side==2){image[height-1][m]=temp;}
        if (side==3){image[m][0]=temp;}
        if (side==4){image[m][width-1]=temp;}
        
        return;

    }}
    edgeblur(1);
    edgeblur(2);
    edgeblur(3);
    edgeblur(4);
    
    return;*/
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
