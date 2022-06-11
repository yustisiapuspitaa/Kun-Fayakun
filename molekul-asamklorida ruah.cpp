
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main(){
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;

    // deklarasi molekul asam klorida
    float Clx[125], Cly[125], Clz[125];
    float Hx[125], Hy[125], Hz[125];
    
       /*               Cl - H 
            molekul asamklorida itu bentuk rigid
    */


    float rB_Clx = 0.0;
    float rB_Cly = 0.0;
    float rB_Clz = 0.0;
    
    float rB_Hx = -sin(0.0*pi/180.0)*1.310
    float rB_Hy = 0.0;
    float rB_Hz = cos(0.0*pi/180.0)*1.310;
    
    // iterasi untuk setiap molekul asam klorida
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
 
                Clx[counter] = rB_Clx + (i*3.01);
                Cly[counter] = rB_Cly + (j*3.01);
                Clz[counter] = rB_Clz + (k*3.01);

                Hx[counter] = Clx[counter] + rB_Hx;
                Hy[counter] = Cly[counter] + rB_Hy;
                Hz[counter] = Clz[counter] + rB_Hz;

                 counter += 1;
            }
        }
    }

    // hasil iterasi dimasukan ke dalam file xyz
    ofstream file;
    file.open("asamklorida-ruah.xyz");
    int N = 125 * 2;
    file << N << "\n" << endl;

        // iterasi dalam output array
    for(int m = 0; m < 125; m++){
        file << setw(2) << "Cl" << setw(2) <<" "\
             << fixed << setprecision(2) << Clx[m] << setw(2) <<" "\
             << fixed << setprecision(2) << Cly[m] << setw(2) <<" "\
             << fixed << setprecision(2) << Clz[m] << "\n";

        file << setw(2) << "H" << setw(2) <<" "\
              << fixed << setprecision(2) << Hx[m] << setw(2) <<" "\
              << fixed << setprecision(2) << Hy[m] << setw(2) <<" "\
              << fixed << setprecision(2) << Hz[m] << "\n";
}


file.close();

cout << "program telah selesai";

return 0;

}
