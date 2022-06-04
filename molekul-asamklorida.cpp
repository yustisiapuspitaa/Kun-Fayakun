
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main(){
    // deklarasi variabel
    float pi = 3.14;

    // deklarasi molekul asamklorida
    float Clx;
    float Hx;

    // masukan nilai untuk setiap variabel HCl
    Clx = 0.0;

    Hx = 0.0;
    Hy = 0.0;
    Hz = 0.0;

    // memasukkan nilai tersebut ke dalam File
    ofstream file;
    file.open("asam klorida.xyz");
    file << "2\n" << endl;
    file << setw(2) << "O" << setw(2) << " " \
    << fixed << setprecision(2) << Clx << setw(2) << " "\
    << fixed << setprecision(2) << Cly << setw(2) << " "\
    << fixed << setprecision(2) << Clz << "\n";

    file << setw(2) << "H" << setw(2) << " " \
    << fixed << setprecision(2) << Hx << setw(2) << " "\
    << fixed << setprecision(2) << Hy << setw(2) << " "\
    << fixed << setprecision(2) << Hz << "\n";

    file.close(); 

    cout << "program selesai!";

    return 0;
}
