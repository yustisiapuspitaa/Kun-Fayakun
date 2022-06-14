
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"


using namespace std;


Int main(){
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;

    // deklarasi molekul besilllklorida
    float Fe1x[125], Fe2x[125], Fe1y[125], Fe2y[125], Fe1z[125], Fe2z[125];
    float O1x[125], O2x[125], O3X[125], O1y[125], O2y[125], O3y[125], O1z[125], O2z[125], O3z[125]; 
    
       /*           O    O    O
                     \\ / \ //
                      Fe   Fe
                  molekul besillloksida itu bentuk rigid
    */


    float rB_Fe1x = sin(109.471*pi/180.0) * 1.615;
    float rB_Fe2x = sin(109.471*pi/180.0) * 1.615;
    float rB_Fe1y = 0.0;
    float rB_Fe2y = 0.0;
    float rB_Fe1z = cos(109.471*pi/180.0) * 1.615;
    float rB_Fe2z = cos(109.471*pi/180.0) * 1.615;

