#ifndef LAB5_ENCODER_H
#define LAB5_ENCODER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>
#include <string>

class Encoder {
public:
    Encoder(const std::vector<std::byte> &key) : key(key) {}

    void encode(const std::string &inputFile, const std::string &outputFile, bool encrypt) {
        std::ifstream inFile(inputFile, std::ios::binary);
        std::ofstream outFile(outputFile, std::ios::binary);

        if (!inFile) {
            std::cerr << "Ошибка открытия входного файла: " << inputFile << std::endl;
            return;
        }

        if (!outFile) {
            std::cerr << "Ошибка открытия выходного файла: " << outputFile << std::endl;
            return;
        }

        std::vector<std::byte> S(256);
        for (int i = 0; i < 256; ++i) {
            S[i] = static_cast<std::byte>(i);
        }

        int j = 0;
        for (int i = 0; i < 256; ++i) {
            j = (j + std::to_integer<int>(S[i]) + std::to_integer<int>(key[i % key.size()])) % 256;
            std::swap(S[i], S[j]);
        }

        // Шифрование/дешифрование файла
        int i = 0;
        j = 0;
        std::byte byte;
        while (inFile.read(reinterpret_cast<char *>(&byte), 1)) {
            i = (i + 1) % 256;
            j = (j + std::to_integer<int>(S[i])) % 256;
            std::swap(S[i], S[j]);
            std::byte k = S[(std::to_integer<int>(S[i]) + std::to_integer<int>(S[j])) % 256];
            std::byte result = byte ^ k;
            outFile.write(reinterpret_cast<char *>(&result), 1);
        }

        inFile.close();
        outFile.close();
    }

    // Mutator для ключа
    void setKey(const std::vector<std::byte> &newKey) {
        key = newKey;
    }

private:
    std::vector<std::byte> key;
};

#endif //LAB5_ENCODER_H
