//
// Created by Mike Terentyev on 09/05/18.
//
#include <iostream>
#include <vector>
#include <set>
#include <ctime>

#include "preCounter.h"
#include "input_stream.h"
#include "output_stream.h"
#include "huffman_decryptor.h"
#include "huffman_encryptor.h"

using namespace std;

void help() {
    printf("Encode: -e [src] [dst] \nDecode: -d [src] [dst]\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        help();
        return 0;
    }

    string mode = argv[1];
    string src = argv[2];
    string dst = argv[3];

    if (mode != "-e" && mode != "-d") {
        help();
        return 0;
    }
    cout << "Start.." << endl;
    double t = clock();
    try {
        Input_stream reader(src);

        if (mode == "-d") {
            Output_stream writer(dst);
            Decryptor::decrypte(reader, writer);
        } else {
            Output_stream writer(dst);
            Encryptor encoder(Frequency::calc_frequency(reader));
            encoder.encode(reader, writer);
        }
    } catch (std::exception &e) {
        printf("%s ", e.what());
    }
    double t2 = clock();
    printf("Finish\nTaking_time..\n");
    std::cerr << (t2 - t) / CLOCKS_PER_SEC << " sec";
    return 0;
}