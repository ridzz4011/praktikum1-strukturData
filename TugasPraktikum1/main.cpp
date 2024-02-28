#include <iostream>

#include "include/clearscreen.hpp"
#include "include/loading.hpp"
#include "include/pauseconsole.hpp"
#include "include/intro.hpp"

#include "include/groupArray.hpp"
#include "include/pointer.hpp"

void deco() {
    for (int i = 0; i < 85; i++) {
        std::cout << "=" ;
    }
}

void deco2() {
    for (int i = 0; i < 85; i++) {
        std::cout << "_" ;
    }
}

int main(int, char**){
    using namespace std;

    Intro();

    Loading();

    int program;

    bool ulang = true;
    do 
    {
        deco();
        cout << "\n" ;

        cout << "\t\t\t" << "|" << "\tList Program:\t    " << "|" << "\n";
        cout << "1. Program Menampilkan Alamat Pointer Suatu Value" << "\n";
        cout << "2. Program Kompres Element di Array" << "\n";
        cout << "3. Exit" << "\n";

        deco();
        cout << "\n";

        cout << "Masukkan pilihan: ";
        cin >> program;

        deco2();
        cout << endl;

        switch (program)
        {
        case 1:
            Pointer();
            break;
        
        case 2:
            groupArray();
            break;

        case 3:
            cout << "Keluar dari program..." << endl;
            ulang = false;
            PauseConsole();
            ClearScreen();
            break;
        
        default:
            cout << "Angka yang anda pilih tidak ada di pilihan!" << endl ;
            PauseConsole();
            ClearScreen();
            break;
        }

    } while (ulang);

    return 0;
}
