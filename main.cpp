#include <string>
#include <vector>
#include "bitmap.h"
#include<iostream>
using namespace std;
int main()
{
 Bitmap picture;
 vector <vector <Pixel> > bitmap;
 Pixel dot;
 bool valid = false;
 string file;
do{
 cout<<"Enter the name of a bitmap file you would like to convert."<<endl;
 cin>>file;

 picture.open(file);
 valid = picture.isImage();

  }
while(valid == false);

 bitmap = picture.toPixelMatrix();
 cout<<file<<" has been loaded. It is "<<bitmap[0].size()<<" pixels wide ";
 cout<<"and "<< bitmap.size()<< " pixels high."<<endl;

 for(int i=0;i<bitmap.size();i++)
 {
    for(int j = 0; j<bitmap[i].size(); j++)
    {
        int ave;
        dot = bitmap[i][j];
        ave = ((dot.red + dot.blue + dot.green)/3);
        dot.red =ave;
        dot.blue=ave;
        dot.green=ave;
        bitmap[i][j] = dot;

 }
}
picture.fromPixelMatrix(bitmap);
picture.save("oldTimeyPhoto.bmp");



 /*
-initialize program with correct variables
    -bitmap matrix made of vectors
    -integer for each pixels rgb
    -'magic numbers' should be declared globally with appropriate names
-accept input of file name
-retrieve file for use in program
-Check for file type and size(24 bit depth Windows BMP file)
    -if wrong file type or size, give error message and ask for correction input(return to beginning)
    -if right file type and size, continue
-create a for loop that cycles through each row for the length of the vector
    -create a nested for loop that cycles through each column while each row is being cycled for the length of the row
        -in each pixel location, break the pixel down to its three rgb values
        -use these values to create an average or use the highest value to create a new value
        -use this value to reassign the three values of rgb to shift the color to grey scale.
        -put the pixel back together with the new uniform rgb value. 
-save this new grayscale bitmap as a new file titled oldtimey.bmp
*/
return 0;
}
