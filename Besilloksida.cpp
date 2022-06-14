
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

    float rB_O1x = sin(109.471*pi/180.0) * 1.615;
    float rB_O2x = sin(109.471*pi/180.0) * 1.615;
    float rB_O3x = sin(109.471*pi/180.0) * 1.615;
    float rB_O1y = 0.0;
    float rB_O2y = 0.0;
    float rB_O3y = 0.0;
    float rB_O1z = cos(109.471*pi/180.0) * 1.615;
    float rB_O2z = cos(109.471*pi/180.0) * 1.615;
    float rB_O3z = cos(109.471*pi/180.0) * 1.615;
  
    // hasil iterasi untuk setiap molekul asam klorida
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                
                Fe1x[counter] = rB_Fe1x + (i*3.01);
                Fe2x[counter] = rB_Fe2x + (i*3.01);
                Fe1y[counter] = rB_Fe1y + (j*3.01);
                Fe2y[counter] = rB_Fe2y + (j*3.01);
                Fe1z[counter] = rB_Fe1z + (k*3.01);
                Fe2z[counter] = rB_Fe2z + (k*3.01);

                O1x[counter] = O1x[counter] + rB_O1x;
                O2x[counter] = O2x[counter] + rB_O2x;
                O3z[counter] = O3z[counter] + rB_O3x;
                O1y[counter] = O1y[counter] + rB_O1y;
                O2y[counter] = O2y[counter] + rB_O2y;
                O3y[counter] = O3y[counter] + rB_O3y;
                O1z[counter] = O1z[counter] + rB_O1z;
                O2z[counter] = O2z[counter] + rB_O2z;
                O3z[counter] = O3z[counter] + rB_O3z;

                 counter += 1;
            }
        }
    }

    // hasil iterasi dimasukan ke dalam file xyz
    ofstream file;
    file.open("besillloksida-ruah.xyz");
    int N = 125 * 5;
    file << N << "\n" << endl;

    // iterasi dalam output array
    for(int m = 0; m < 8; m++){
        file << setw(5) << "Fe1" << setw(5) <<" "\
             << fixed << setprecision(5) << Fe1x[m] << setw(5) <<" "\
             << fixed << setprecision(5) << Fe1y[m] << setw(5) <<" "\
             << fixed << setprecision(5) << Fe1z[m] << "\n";
        file << setw(5) << "Fe2" << setw(5) <<" "\
             << fixed << setprecision(5) << Fe2x[m] << setw(5) <<" "\
             << fixed << setprecision(5) << Fe2y[m] << setw(5) <<" "\
             << fixed << setprecision(5) << Fe2z[m] << "\n";

        file << setw(5) << "O1" << setw(5) <<" "\
              << fixed << setprecision(5) << O1x[m] << setw(5) <<" "\
