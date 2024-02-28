#include <iostream>

#include "../../../include/pointer.hpp"

#include "../../../include/clearscreen.hpp"
#include "../../../include/pauseconsole.hpp"

void Pointer() {

    ClearScreen();

    for (int i = 0; i < 76; i++) {
        std::cout << "=" ;
    }

    std::cout << "\n\n";

    std::cout << "Masukkan jumlah siswa : " ;
    int maxSt; // Kita siapkan variable untuk menampung jumlah siswa dulu
    std::cin >> maxSt;

    std::string arrSt[maxSt]; // Array untuk menyimpan data dengan size sesuai dengan yang kita input sebelumnya
    std::string *pSt; // Pointer

    pSt = arrSt; // Pointer yang menunjuk ke Array

    for(int i = 0; i < maxSt; i++) {
        std::cout << "Masukkan nama siswa ke-" << i + 1 << " : ";
        std::cin >> arrSt[i];
        std::cout << "\n";
    }

    std::cout << "\nNAMA SISWA\t\t\t\t\t\t\tALAMAT SISWA\n";
    for (int i = 0; i < 76; i++) {
        std::cout << "=" ;
    }
    std::cout << "\n";

    // Print Output menggunakan loop
    for (int i = 0; i < maxSt; i++) {
        std::cout << *pSt << "\t\t\t\t\t\t\t\t" << pSt << "\n";
        pSt++;
    }

    std::cout << "\n";
    std::cout << "\nProgram ini dibuat oleh: Farid Noer Hakim\n\n";

    PauseConsole();
    ClearScreen();
    
}