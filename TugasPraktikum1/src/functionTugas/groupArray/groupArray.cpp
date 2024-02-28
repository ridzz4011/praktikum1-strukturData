#include <iostream>
#include <unordered_map> // Untuk mengkompres element-element di Array
#include <vector> // Untuk menggunakan push_back
#include <limits>

#include "../../../include/groupArray.hpp"

#include "../../../include/clearscreen.hpp"

#include "../../../include/pauseconsole.hpp"

void groupArray() {
    int size;
    bool valid = true;

    ClearScreen();

    std::cout << "==========================================\n\n";

    while (valid) {
        std::cout << "Masukkan Batas Array (Maks. 25) : " ;
        std::cin >> size;

        // Cek apakah nilai yang dimasukkan melebihi 25 atau tidak
        if (size > 25) {
            std::cout << "Array yang anda masukkan terlalu besar!\n\n" ;
            PauseConsole();
            ClearScreen();
        } else {
            valid = false; // Jika tidak maka akan keluar dari loop
        }
        
    }
    
    std::vector<char> input(size); // Untuk menyimpan nilai/element ke array
    for(int i = 0; i < size; i++) {
        char x; // Variable sementara yang digunakan untuk membaca input nantinya
        std::cout << "Masukkan Nilai Array ke-" << i + 1 << " : ";
        std::cin >> x;

        // Untuk mengecheck apakah nilai yang kita masukan berjumlah lebih dari 1 atau bukan.
        // Jika berjumlah lebih dari 1 maka program akan mengembalikan error dan menyuruh user untuk
        // memasukkan input kembali.
        if(std::cin.peek() != '\n') { // Kita pakai peek() untuk melihat apa yang ada didalam input buffer
            std::cout << "Masukkan hanya 1 karakter dalam 1 waktu saja!!!\n\n" ;
            // Menghapus input yang tadi dimasukkan. Tanpa ada ini nanti proses loopnya akan terskip
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i--; // Menghapus input tersebut di array agar bisa dimasukkan nilai ulang
            continue; // Melanjutkan loop
        }

        input[i] = x; // Jika hanya 1 karakter saja yang dimasukkan maka kita hanya tinggal masukan ke array
    }

    std::cout << "\n\n==========================================\n\n";

    // Mengurutkan element didalam array menggunakan Insertion Sort
    for (int i = 1; i < size; ++i) {
        char z = input[i];
        int j = i - 1;
        while (j >= 0 && input[j] > z) {
            input[j + 1] = input[j];
            --j;
        }
        input[j + 1] = z;
    }

    // Untuk menghitung setiap element yang berulang di dalam Array menggunakan countMap
    std::unordered_map<char, int> countMap;
    for(char &c : input) {
        countMap[c]++;
    }

    // Ketika element-element yang berulang sudah terhitung, maka akan digabungkan dengan kode dibawah
    std::vector<char> output;
    for(auto &element : countMap) {
        output.push_back(element.first);
        output.push_back('0' + element.second); // Mengubah int menjadi char
    }

    // Print input yang sudah tersortir
    std::cout << "\nInput : " ;
    for(char f : input) {
        std::cout << "'" << f << "'" << "," << " ";
    }

    // Print output yang sudah di group
    std::cout << "\nOutput : [" ;
    for(char c : output) {
        std::cout << "'" << c << "'" << "," << " ";
    }
    std::cout << "] ";

    std::cout << "\n" ;
    std::cout << "\nProgram ini dibuat oleh: Farid Noer Hakim\n\n";

    PauseConsole();
    ClearScreen();
}