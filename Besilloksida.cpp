
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
    
    cout << "program menghitung energi potensial dari besillloksida" << endl;
    cout << "Masukkan nilai densitas dari asamklorida (eg. 1.0): ";
    cin >> densitas;

    numb_mol = densitas * (Na / Mr_besillloksida) * cm3_to_A3;
    cout << "Masukkan panjang sel simulasi (eg. 5): ";
    cin >> numb_lat;
    N = (pow(numb_lat,3)) * 3;
    volum = (float)N / numb_mol;

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
