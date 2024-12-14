#include "Encoder.h"
#include <iostream>

using namespace std;

int main() {
    // test 1
    vector<byte> key1 = {byte(0x01), byte(0x02), byte(0x03)};
    Encoder enc1(key1);
    int result1 = enc1.encode("test_in.txt", "test_output.txt");
    if (result1 == 0) {
        cout << "Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }

    // test 2
    int result2 = enc1.encode("test_output.txt", "test_decoded.txt");
    if (result2 == 0) {
        cout << "Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }

    // test 3
    vector<byte> key2 = {byte(0x04), byte(0x05), byte(0x06)};
    enc1.change_key(key2);
    int result3 = enc1.encode("test_in.txt", "test_output_changed_key.txt");
    if (result3 == 0) {
        cout << "Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }

    // test 4
    int result4 = enc1.encode("test_output_changed_key.txt", "test_decoded_changed_key.txt");
    if (result4 == 0) {
        cout << "Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }
    // test 5
    int result5 = enc1.encode("theory.jpg", "out_theory.jpg");
    if (result5 == 0) {
        cout << "Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }
    // test 6
    int result6 = enc1.encode("out_theory.jpg", "decoded_theory.jpg");
    if (result6 == 0) {
        cout << "Successful" << endl;
    } else {
        cout << "Failed" << endl;
    }

    return 0;
}