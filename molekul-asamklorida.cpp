
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main(){
    // deklarasi variabel
    float pi = 3.14;

    // deklarasi molekul asamklorida
    float Clx, Cly, Clz;
    float Hx, Hy, Hz;

    // masukan nilai untuk setiap variabel HCl
    Clx = Cly = Clz = 0.0;

    Hx = 0.0;
    Hy = 0.0;
    Hz = 0.0;

    // memasukkan nilai tersebut ke dalam File
    ofstream file;
    file.open("metana.xyz");
    file << "5\n" << endl;
    file << setw(5) << "C" << setw(5) << " " \
    << fixed << setprecision(5) << Cx << setw(5) << " "\
    << fixed << setprecision(5) << Cy << setw(5) << " "\
    << fixed << setprecision(5) << Cz << "\n";

    file << setw(5) << "H" << setw(5) << " " \
    << fixed << setprecision(5) << H1x << setw(5) << " "\
    << fixed << setprecision(5) << H1y << setw(5) << " "\
    << fixed << setprecision(5) << H1z << "\n";

    file << setw(5) << "H" << setw(5) << " " \
    << fixed << setprecision(5) << H2x << setw(5) << " "\
    << fixed << setprecision(5) << H2y << setw(5) << " "\
    << fixed << setprecision(5) << H2z << "\n";

    file << setw(5) << "H" << setw(5) << " " \
    << fixed << setprecision(5) << H3x << setw(5) << " "\
    << fixed << setprecision(5) << H3y << setw(5) << " "\
    << fixed << setprecision(5) << H3z << "\n";

    file << setw(5) << "H" << setw(5) << " " \
    << fixed << setprecision(5) << H4x << setw(5) << " "\
    << fixed << setprecision(5) << H4y << setw(5) << " "\
    << fixed << setprecision(5) << H4z << "\n";

    file.close(); 

    cout << "program selesai!";

    return 0;
}
