#ifndef FUNDAMENTAL_ALGORITHMS_MAIN_H
#define FUNDAMENTAL_ALGORITHMS_MAIN_H


#include <vector>
#include <fstream>
#include <cstddef>
#include <filesystem>


class Encoder {
private:
    std::vector<std::byte> encoding_key;
    std::vector<std::byte> s_block;

    Encoder &KSA();

    std::byte &PRGA(int i, int j);

public:

    Encoder(std::vector<std::byte> &key);

    void change_key(std::vector<std::byte> &new_key);

    int encode(const std::string &in_path, const std::string &out_path);


};

#endif //FUNDAMENTAL_ALGORITHMS_MAIN_H