//Author: Frederick Alvarez

#include <string>
#include <vector>
#include "bitmap.h"
#include<iostream>

using namespace std;

int main()
{
//Variable Declaration
Bitmap picture;
vector <vector <Pixel> > bitmap;
Pixel dot;
bool valid = false;
string file;

//do..while statment makes the program repeatedly ask for usable input file. 
    do{
        cout<<"Enter the name of a bitmap file you would like to make old timey."<<endl;
        cin>>file;

        picture.open(file);
        valid = picture.isImage();

      }
    while(valid == false);

//converts bitmap to a pixel matrix
bitmap = picture.toPixelMatrix();

//for loops will cycle through each column for every row. 

    for(int i = 0; i < bitmap.size(); i++)
    {
        for(int j = 0; j < bitmap[i].size(); j++)
        {   //ave is the average of the rgb values for each pixel
            int ave;
            dot = bitmap[i][j];
            ave = ((dot.red + dot.blue + dot.green)/3);
            //each pixel is converted grey using this average
            dot.red = ave;
            dot.blue = ave;
            dot.green = ave;
            bitmap[i][j] = dot;

        }
    }


picture.fromPixelMatrix(bitmap);
//I wanted to use camelcase for oldTimey.bmp, but the instructions had oldtimey.bmp
picture.save("oldtimey.bmp");



return 0;
}
