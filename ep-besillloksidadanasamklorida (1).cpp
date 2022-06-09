
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

float densitas;         /*densitas ini memiliki satuan g cm^-3
                          dan ini harus diinput dari user */
// converter dari nilai cm^-3 ke A^3
float cm3_to_A3 = 1.0E-24;
float numb_mol;
float Na = 6.022E23;            // bilangan avogadro
float Mr_besillloksida = 160.0;  // massa relatif dari besillloksida
float Mr_asamklorida = 36.46;  // massa relatif dari asam klorida
int numb_lat;                   // panjang sel simulasi
int N;                          // jumlah molekul
float volum;                    // volume dari molekul besillloksida
float lx, ly, lz;               // panjang sel simulasi terhitung 
float lat;                      // jarak antar molekul besillloksida

// variabel perhitungan energi potensial
float sigma = 2.725;            // satuan (A)
float epsilon = 3.725;          // satuan (kj/mol)
float rij, rcut, rcut2;
float Ep, Ep_LJ, A12, B6;
float rij6, rij12;
float dx, dy, dz;

int main(){
    
    rcut = 3 * sigma;
    rcut2 = pow(rcut,2);
    
    cout << "program menghitung energi potensial dari besillloksidadanasamklorida" << endl;
    cout << "Masukkan nilai densitas dari besillloksidadanasamklorida (eg. 1.0): ";
    cin >> densitas;

    numb_mol = densitas * (Na / Mr_besillloksida) * cm3_to_A3;
    cout << "Masukkan panjang sel simulasi (eg. 5): ";
    cin >> numb_lat;
    N = (pow(numb_lat,3)) * 3;
    volum = (float)N / numb_mol;
  
        numb_mol = densitas * (Na / Mr_asamklorida) * cm3_to_A3;
    cout << "Masukkan panjang sel simulasi (eg. 5): ";
    cin >> numb_lat;
    N = (pow(numb_lat,3)) * 3;
    volum = (float)N / numb_mol;

    // panjang sel simulasi secara perhitungan
    lx = pow(volum,(1.0/3.0));
    ly = lx;
    lz = lx;
    if(lx < (2*rcut)){
        cout << "sorry mazeh, sel simulasi kamu besar";
        exit(0);
    } else{
        cout << "panjang sek simulasi baru: " << lx << endl;
    }
    lat = lx / (float)numb_lat;

    // deklarasi variabel
    float pi = 3.14;
    
    // deklarasi molekul besillloksida
    float Fe1x[8], Fe2x[8], Fe1y[8], Fe2y[8], Fe1z[8], Fe2z[8];
    float O1x[8], O2x[8], O3X[8], O1y[8], O2y[8], O3y[8], O1z[8], O2z[8], O3z [8];
    float Clx[8], Cly[8], Clz[8];
    float Hx[8], Hy[8], Hz[8];


    /*            O   O   O
                   \ / \ /
                    F   F
                  Cl - H  
     molekul besillloksida dan asam klorida itu bentuk rigid
   */

    float rB_Fe1x = sin(180.0*pi/180.0) * 1.900;;
    float rB_Fe2x = sin(180.0*pi/180.0) * 1.900;;
    float rB_Fe1y = 0.0;
    float rB_Fe2y = 0.0;
    float rB_Fe1z = cos(180.0*pi/180.0) * 1.900;
    float rB_Fe2z = cos(180.0*pi/180.0) * 1.900;

    float rB_O1x = sin(180.0*pi/180.0) * 1.900;
    float rB_O2x = sin(180.0*pi/180.0) * 1.900;
    float rB_O3x = sin(180.0*pi/180.0) * 1.900;
    float rB_O1y = 0.0;
    float rB_O2y = 0.0;
    float rB_O3y = 0.0;
    float rB_O1z = cos(180.0*pi/180.0) * 1.900;
    float rB_O2z = cos(180.0*pi/180.0) * 1.900;
    float rB_O3z = cos(180.0*pi/180.0) * 1.900;

    float rB_Clx = 0.0;
    float rB_Cly = 0.0;
    float rB_Clz = 0.0;

    float rB_Hx = sin(0.0*pi/180.0) * 1.310;
    float rB_Hy = 0.0;
    float rB_Hz = cos (0.0*pi/180.0) * 1.310;
   
    ;int counter = 0;
        for(int i = 0; i < numb_lat; i++){ //x
           for(int j = 0; j < numb_lat; j++){ //y
               for(int k = 0; k < numb_lat; k++){ //z 
                
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
    // main hitung energi potensial
    A12 = 4.0 * epsilon * pow(sigma,12);
    B6 = 4.0 * epsilon * pow(sigma, 6);

    Ep = 0.0;
    for(int a = 0; a < (N-1); a++){
        for(int b = (0+1); b < N; b++){
            
            dx = Fe2x[a] - Fe2x[b];
            dy = Fe2y[a] - Fe2y[b];
            dz = Fe2z[a] - Fe2z[b];
             
            dx = Clx[a] - Clx[b];
            dy = Cly[a] - Cly[b];
            dz = Clz[a] - Clz[b];

            dx = dx - round(dx/lx) * lx;
            dy = dy - round(dy/ly) * ly;
            dz = dz - round(dz/lz) * lz;



            rij = pow(dx,2) + pow(dy,2) + pow(dz,2);
            if(rij < rcut2){
                rij6 = pow(rij,3);
                rij12 = pow(rij6,2);
                Ep = (A12/rij12) - (B6/rij6);
                Ep_LJ = (A12/rij12) - (B6/rij6);
                Ep += Ep_LJ;
            }
        }
    }

    cout << "Energi potensial dari molekul besillloksidadanasamklorida ruah: " \
         << Ep/(float)N << "kJ/mol";

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("besillloksidadanasamklorida-hitung_ep.xyz");
    file << N << "\n" << endl;

    int Nw = N/5;

    // iterasi dalam output array
    for(int m = 0; m < Nw; m++){
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
              << fixed << setprecision(5) << O1y[m] << setw(5) <<" "\
              << fixed << setprecision(5) << O1z[m] << "\n";

         file << setw(5) << "O2" << setw(5) <<" "\
              << fixed << setprecision(5) << O2x[m] << setw(5) <<" "\
              << fixed << setprecision(5) << O2y[m] << setw(5) <<" "\
              << fixed << setprecision(5) << O2z[m] << "\n";

          file << setw(5) << "O3" << setw(5) <<" "\
              << fixed << setprecision(5) << O3z[m] << setw(5) <<" "\
              << fixed << setprecision(5) << O3y[m] << setw(5) <<" "\
              << fixed << setprecision(5) << O3z[m] << "\n";
    
         int Nw = N/2;

         // iterasi dalam output array
    for(int m = 0; m < Nw; m++){
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

    return 0;
    
    }
