
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
int numb_lat;                   // panjang sel simulasi
int N;                          // jumlah molekul
float volum;                    // volume dari molekul besillloksida
float lx, ly, lz;               // panjang sel simulasi terhitung 
float lat;                      // jarak antar molekul besillloksida
int main(){
    

    // deklarasi molekul ferioksida
    float O1x, O1y, O2z;
    float O2x, O2y, O2z;
    float O3x, O3y, O3z;
    float Fe1x, Fe1y, Fe1z;
    float Fe2x, Fe2y, Fe3y;


    // masukan nilai untuk setiap variabel
    O1x = O1y = O1z = 0.0;

    O2x = sin(54,73*pi/180) * 3.515;
    O2y = 0.0;
    O2z = cos(54,73*pi/180) * 3.515;

    O3x = - O2x;
    O3y = O2y;
    O3z = O2z;

    Fe1x = sin(54,73*pi/180) * 1.900;
    Fe1y = 0.0;
    Fe1z = cos(54,73*pi/180) * 1.900;

    Fe2x = - Fe1x;
    Fe2y = Fe1y;
    Fe2z = Fe1z;

    // memasukan nilai tersebut ke dalam file
    ofstream file;
    file.open("ferioksida.xyz");
    file << "5\n" << endl;
    file << setw(5) << "O" << setw(5) << " "\
    << fixed << setprecision(5) << O1x << setw(5) << " "\
    << fixed << setprecision(5) << O1y << setw(5) << " "\
    << fixed << setprecision(5) << O1z << "\n";

    file << setw(5) << "O" << setw(5) << " "\
    << fixed << setprecision(5) << O2x << setw(5) << " "\
    << fixed << setprecision(5) << O2y << setw(5) << " "\
    << fixed << setprecision(5) << O2z << "\n";

    file << setw(5) << "O" << setw(5) << " "\
    << fixed << setprecision(5) << O3x << setw(5) << " "\
    << fixed << setprecision(5) << O3y << setw(5) << " "\
    << fixed << setprecision(5) << O3z << "\n";

    file << setw(5) << "Fe" << setw(5) << " "\
    << fixed << setprecision(5) << Fe1x << setw(5) << " "\
    << fixed << setprecision(5) << Fe1y << setw(5) << " "\
    << fixed << setprecision(5) << Fe1z << "\n";

    file << setw(5) << "Fe" << setw(5) << " "\
    << fixed << setprecision(5) << Fe2x << setw(5) << " "\
    << fixed << setprecision(5) << Fe2y << setw(5) << " "\
    << fixed << setprecision(5) << Fe2z << "\n";

    file.closed();

    cout << "program selesai!";

    return 0;
}
