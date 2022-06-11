
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

    file.close(); 

    cout << "program selesai!";

    return 0;
}
