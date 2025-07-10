// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: photoshop.cpp
// Last Modification Date: 22/4/2022
// Author1 and ID and Group: Ahmed Mohammed Ahmed   20210029
// Author2 and ID and Group: Yasmina Adel Salem     20210565
// Author3 and ID and Group: Mostafa Ali Hesham     20210394
// Teaching Assistant: Eng. Abdulrahman Abdulmonem
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];
unsigned char pic[SIZE][SIZE];

void loadImage ();
void saveImage ();
void saveImage2 ();
void BlackandWhite ();
void InvertImage();
void MergeImage ();
void loadImageformerge ();
void FlipImage();
void DarkenandLighten ();
void RotateImage ();
void Detect_Image_Edges();
void EnlargeImage();
void ShrinkImage ();
void getpic ();
void returnpic ();
void hlmirror ();
void hrmirror();
void vlmirror();
void vrmirror();
void ShuffleImage();
void BlurImage();
int main(){
    while(true) {
        char choice;
        cout << "\n\nPlease select a filter to apply or 0 to exit:" << endl;
        cout << "1- Black & White Filter" << endl;
        cout << "2- Invert Filter" << endl;
        cout << "3- Merge Filter" << endl;
        cout << "4- Flip Image" << endl;
        cout << "5- Darken and Lighten Image" << endl;
        cout << "6- Rotate Image" << endl;
        cout << "7- Detect Image Edges" << endl;
        cout << "8- Enlarge Image" << endl;
        cout << "9- Shrink Image" << endl;
        cout << "a- Mirror 1/2 Image" << endl;
        cout << "b- Shuffle Image" << endl;
        cout << "c- Blur Image" << endl;
        cout << "0- Exit" << endl;

        cin >> choice;
        if (choice == '1') {
            loadImage();
            BlackandWhite();
            saveImage();
        } else if (choice == '2') {
            loadImage();
            InvertImage();
            saveImage();
        } else if (choice == '3') {
            loadImageformerge();
            MergeImage();
            saveImage();
        } else if (choice == '4') {
            loadImage();
            FlipImage();
            saveImage2();
        } else if (choice == '5') {
            loadImage();
            DarkenandLighten();
            saveImage2();
        } else if (choice == '6') {
            loadImage();
            RotateImage();
            saveImage();
        } else if (choice == '7') {
            loadImage();
            Detect_Image_Edges();
            saveImage2();
        } else if (choice == '8') {
            loadImage();
            EnlargeImage();
            saveImage();
        } else if (choice == '9') {
            loadImage();
            ShrinkImage();
            saveImage();
        } else if (choice == 'a') {
            int choise;
            cout<< " 1-Horizontal right mirror \n 2-Horizontal left mirror \n 3-Vertical up mirror \n 4-Vertical down mirror \n Enter your choice here : ";
            cin >> choise;
            getpic();
            if (choise == 1) {
                hlmirror();
            } else if (choise == 2) {
                hrmirror();
            } else if (choise == 3) {
                vlmirror();
            } else if (choise == 4) {
                vrmirror();
            }
            returnpic();
        } else if (choice == 'b') {
            loadImage();
            ShuffleImage();
            saveImage();
        } else if (choice =='c'){
            loadImage();
            BlurImage();
            saveImage();

        } else if (choice == '0') {
            break;
        }
    }
}
//_
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
//_
void loadImageformerge () {
    char imageFileName[100],imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    cout << "Enter the source image2 file name: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);
}

//_____
void saveImage2 () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//_

void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, new_image);
}
//_
void BlackandWhite() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 127)
                new_image[i][j] = 255;
            else
                new_image[i][j] = 0;
        }
    }
}
//_
void InvertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            new_image[i][j]=255-image[i][j];
        }
    }
}
//_
void MergeImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            new_image[i][j]=(image[i][j]+image2[i][j])/2;
        }
    }
}
//_____
void FlipImage() {
    int choice;
    cout << "If you want to flip the image Horizontally choose number 1 , Vertically number 2"<<endl;
    cin >> choice;
    int temp;
    while (true) {
        if (choice == 1) {
            // Switching columns
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp = image[i][j];
                    image[i][j] = image[255 - i][j];
                    image[255 - i][j] = temp;
                }
            }
            break;
        }
        else if (choice == 2) {
            // Switching columns either
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp = image[i][j];
                    image[i][j] = image[255 - i][j];
                    image[255 - i][j] = temp;
                }
            }//Then rotate 90 degree
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    int temp = image[i][j];
                    image[i][j] = image[255 - 1 - j][i];
                    image[255 - 1 - j][i] = image[255 - 1 - i][255 - 1 - j];
                    image[255 - 1 - i][255 - 1 - j] = image[j][255 - 1 - i];
                    image[j][255 - 1 - i] = temp;
                }
            }// Rotating 90 degree again
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    int temp = image[i][j];
                    image[i][j] = image[255 - 1 - j][i];
                    image[255 - 1 - j][i] = image[255 - 1 - i][255 - 1 - j];
                    image[255 - 1 - i][255 - 1 - j] = image[j][255 - 1 - i];
                    image[j][255 - 1 - i] = temp;
                }
            }
            break;
        }
    }
}
void BlurImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {


            new_image[i][j] = (image[i][j]+image[i+1][j]+image[i-1][j]+image[i+1][j+1]+image[i-1][j-1]+image[i][j+1]+image[i][j-1]+image[i+1][j-1]+image[i-1][j+1]+image[i+2][j+2]+image[i+2][j]+image[i][j+2]+image[i-2][j]+image[i][j-2]+image[i+2][j-2]+image[i-2][j+2])/16;

        }
    }
}
//_____
void DarkenandLighten() {
    int filter;
    cout << "If you want darker filter enter 1 \nIf you want lighter filter enter 2:  \n";
    cin >>filter;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            if(filter==1 ){
                image[i][j]=(image[i][j])/2;
            }
            else if(filter==2){
                image[i][j]=(image[i][j]+255)/2;
            }
        }
    }
}
//_____
void RotateImage () {
    int operation, num;
    bool check = true;
    cout << "please choose what you want" << endl;
    cout << "1-Rotate the image clockwise by 90 degree enter 1" << endl;
    cout << "2-Rotate the image clockwise by 180 degree enter 2" << endl;
    cout << "3-Rotate the image clockwise by 270 degree enter 3" << endl;
    cin >> operation;

    if (operation == 1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[255 - j][i];

            }
        }
    } else if (operation == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[j][i] = image[255 - j][255 - i];

            }
        }
    } else if (operation == 3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[j][255 - i];
            }
        }
    }
}
//____
void Detect_Image_Edges() {
    char ImageFileName[100];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int A = (image[i][j] * -1 +
                     image[i][j + 1] * 0 +
                     image[i][j + 2] * 1 +
                     image[i + 1][j] * -2 +
                     image[i + 1][j + 1] * 0 +
                     image[i + 1][j + 2] * 2 +
                     image[i + 2][j] * -1 +
                     image[i + 2][j + 1] * 0 +
                     image[i + 2][j + 2] * 1);

            int B = (image[i][j] * -1 +
                     image[i][j + 1] * -2 +
                     image[i][j + 2] * -1 +
                     image[i + 1][j] * 0 +
                     image[i + 1][j + 1] * 0 +
                     image[i + 1][j + 2] * 0 +
                     image[i + 2][j] * 1 +
                     image[i + 2][j + 1] * 2 +
                     image[i + 2][j + 2] * 1);

            int res = pow(A, 2) + pow(B, 2);
            image[i][j] = abs(sqrt(res));
            if (image[i][j] < 255 / 5) {
                image[i][j] = 255;
            }
        }
    }

}
//___
void EnlargeImage() {
    int Quarte_number;
    bool check = true;
    cout <<"Please enter the quarter number you want to choose " << endl;
    cout<<"please choose what you want"<<endl;
    cout<<"\n\nenter 1 to Enlarge Image to foto1"<<endl;
    cout<<"enter 2 to Enlarge Image to foto2"<<endl;
    cout<<"enter 3 to Enlarge Image to foto3"<<endl;
    cout<<"enter 4 to Enlarge Image to foto4\n\n"<<endl;
    cin >> Quarte_number;
    if (Quarte_number == 1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[i/2][j/2];
            }
        }
    }

    else if (Quarte_number == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[i/2 ][(j/2) + 127];
            }
        }
    }
    else if (Quarte_number == 3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[(i / 2) + 127][j / 2];
            }
        }
    }
    else if (Quarte_number == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[(i / 2) + 127][(j / 2) + 127];
            }
        }
    }
    else{
        cin.clear();
        cin.ignore();
        cout << "Enter agian the correct number 1 or 2 or 3 or 4 " << endl;
        EnlargeImage();
    }
}
//_____
void ShrinkImage () {
    int operation;
    cout<<"please choose what you want"<<endl;
    cout<<"enter 1 to shrink the image to 1/2"<<endl;
    cout<<"enter 2 to shrink the image to 1/3"<<endl;
    cout<<"enter 3 to shrink the image to 1/4"<<endl;
    cin>>operation;

    if(operation==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                new_image[i/2][j/2]=image[i][j];
            }
        }
    }
    else if(operation==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                new_image[i/3][j/3]=image[i][j];
            }
        }
    }
    else if(operation==3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                new_image[i/4][j/4]=image[i][j];
            }
        }
    }
    else{
        cin.clear();
        cin.ignore();
        cout<<"\nenter agian and correct 1 or 2 or 3 : \n\n ";
        ShrinkImage ();
    }
}
void getpic () {
    char userpic[100];

    cout << "Enter the source image file name: ";
    cin >> userpic;

    strcat (userpic, ".bmp");
    readGSBMP(userpic, pic);
}

void returnpic () {
    char userpic[100];

    cout << "Enter the target image file name: ";
    cin >> userpic;

    strcat (userpic, ".bmp");
    writeGSBMP(userpic, pic);
}

void hlmirror() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< (SIZE+1)/2; j++) {
            pic[i][j]=pic[i][-j];
        }
    }
}

void hrmirror() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< (SIZE+1)/2; j++) {
            pic[i][-j]=pic[i][j];
        }
    }
}

void vlmirror() {
    for (int i = 0; i < (SIZE+1)/2; i++) {
        for (int j = 0; j< SIZE; j++) {
            pic[255-i][j]=pic[i][j];
        }
    }
}

void vrmirror() {
    for (int i = 0; i < (SIZE+1)/2; i++) {
        for (int j = 0; j< SIZE; j++) {
            pic[i][j]=pic[255-i][j];
        }
    }
}
//____
void ShuffleImage() {
    string q1, q2, q3, q4;
    cout << "Please enter the order you want" << endl;
    cin >> q1;
    if (q1 == "1") {
        for (int r = 0; r < 127; r++) {
            for (int c = 0; c < 127; c++) {
                new_image[r][c] = image[r][c];
            }
        }
    }

    else if (q1 == "2" ) {
        for (int r = 0; r < 127; r++) {
            for (int c = 127; c < SIZE; c++) {
                new_image[r][c - 127] = image[r][c];
            }
        }
    } else if (q1 == "3" ) {
        for (int r = 127; r < SIZE; r++) {
            for (int c = 0; c < 127; c++) {
                new_image[r - 127][c] = image[r][c];
            }
        }
    } else if (q1 == "4" ) {
        for (int r = 127; r < SIZE; r++) {
            for (int c = 127; c < SIZE; c++) {
                new_image[r - 127][c - 127] = image[r][c];
            }
        }
    }

    cin >> q2;
    if (q2 == "1" ) {
        for (int r = 0; r < 127; r++) {
            for (int c = 0; c < 127; c++) {
                new_image[r][c + 127] = image[r][c];
            }
        }
    } else if (q2 == "2" ) {
        for (int r = 0; r < 127; r++) {
            for (int c = 127; c < SIZE; c++) {
                new_image[r][c] = image[r][c];
            }
        }
    } else if (q2 == "3") {
        for (int r = 127; r < SIZE; r++) {
            for (int c = 0; c < 127; c++) {
                new_image[r - 127][c + 127] = image[r][c];
            }
        }
    } else if (q2 == "4" ) {
        for (int r = 127; r < SIZE; r++) {
            for (int c = 127; c < SIZE; c++) {
                new_image[r - 127][c] = image[r][c];
            }
        }
    }
    cin >> q3;
    if (q3 == "1" ) {
        for (int r = 0; r < 127; r++) {
            for (int c = 0; c < 127; c++) {
                new_image[r + 127][c] = image[r][c];
            }
        }
    } else if (q3 == "2" ) {
        for (int r = 0; r < 127; r++) {
            for (int c = 127; c < SIZE; c++) {
                new_image[r + 127][c - 127] = image[r][c];
            }
        }
    } else if (q3 == "3" ) {
        for (int r = 127; r < SIZE; r++) {
            for (int c = 0; c < 127; c++) {
                new_image[r][c] = image[r][c];
            }
        }
    } else if (q3 == "4" ) {
        for (int r = 127; r < SIZE; r++) {
            for (int c = 127; c < SIZE; c++) {
                new_image[r][c - 127] = image[r][c];
            }
        }
    }
    cin >> q4;
    if (q4 == "1") {
        for (int r = 0; r < 127; r++) {
            for (int c = 0; c < 127; c++) {
                new_image[r + 127][c + 127] = image[r][c];
            }
        }
    } else if (q4 == "2" ) {
        for (int r = 0; r < 127; r++) {
            for (int c = 127; c < SIZE; c++) {
                new_image[r + 127][c] = image[r][c];
            }
        }
    } else if (q4 == "3") {
        for (int r = 127; r < SIZE; r++) {
            for (int c = 0; c < 127; c++) {
                new_image[r][c + 127] = image[r][c];
            }
        }
    } else if (q4 == "4" ) {
        for (int r = 127; r < SIZE; r++) {
            for (int c = 127; c < SIZE; c++) {
                new_image[r][c] = image[r][c];
            }
        }
    } else {
        cin.clear();
        cin.ignore();
        cout << "Please enter the numbers available to you from 1 to 4" << endl;

        ShuffleImage();

    }
}