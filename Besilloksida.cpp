
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
