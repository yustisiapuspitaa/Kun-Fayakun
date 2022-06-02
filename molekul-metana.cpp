
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main(){
    // deklarasi variabel
    float pi = 3.14;

    // deklarasi molekul metana
    float Cx, Cy, Cz;
    float H1x, H1y, H1z;
    float H2x, H2y, H2z;
    float H3x, H3y, H3z;
    float H4x, H4y, H4z;

    // masukan nilai untuk setiap variabel CH4
    Cx = Cy = Cz = 0.0;

    H1x = sin(109.5*pi/180) * 1.090;
    H1y = 0.0;
    H1z = - cos(109.5*pi/180) * 1.090;

    H2x = - H1x;
    H2y = H1y;
    H2z = H1z;

    H3x =  0.0;
    H3y = cos(54.75*pi/180) * 1.090;
    H3z = - sin(54.75*pi/180) * 1.090;

    H4x =  H3x;
    H4y = - H3y;
    H4z =  H3z;

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