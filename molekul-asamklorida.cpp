
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


    // memasukkan nilai tersebut ke dalam File
    ofstream file;
    file.open("asam klorida.xyz");
    file << "2\n" << endl;
    file << setw(2) << "Cl" << setw(2) << " " \
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
