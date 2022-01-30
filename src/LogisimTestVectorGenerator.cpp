//
// Created by mzbroszczyk on 2022-01-30.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>

using std::cout;
using std::endl;

constexpr static unsigned short bit_res    = 4;
constexpr static unsigned short input_size = 7;

int main() {
    std::ofstream test_file("test.txt");
    if (!test_file.is_open()) {
        cout << "! Blad otwarcia pliku" << endl;
        return 1;
    }
    test_file << "# Wektor testowy dla SN o " << input_size << " wejsciach / wyjsciach" << "\n";
    for (int i = 0; i < 2 * input_size; ++i) {
        if (i < input_size)
            test_file << (char) ('a' + i) << "[" << bit_res << "]";
        else
            test_file << (char) (122 - 2 * input_size + i + 1) << "[" << bit_res << "]";
        if (i < 2 * input_size - 2)
            test_file << " ";
    }
    test_file << endl;
    for (unsigned short k = 0; k < 5; ++k) {
        std::vector<unsigned short> vData;
        for (unsigned short i = 0; i < input_size; ++i) {
            vData.push_back(rand() % static_cast<unsigned int>(pow(2, bit_res)));
            test_file << std::bitset<bit_res>(vData[vData.size() - 1]);
            if (i != input_size - 1)
                test_file << " ";
        }
        sort(vData.begin(), vData.end());
        for (unsigned short i = 0; i < input_size; ++i) {
            vData.push_back(rand() % static_cast<unsigned int>(pow(2, bit_res)));
            test_file << std::bitset<bit_res>(vData[i]);
            if (i != input_size - 1)
                test_file << " ";
        }
        test_file << endl;
    }
    test_file.close();
    return 0;
}
