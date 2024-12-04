#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>

using namespace std;
using namespace CryptoPP;

int main () {
    SHA1 hash;
    cout << "Name: " << hash.AlgorithmName() << endl;
    cout << "Diget size: " << hash.DigestSize() << endl;
    cout << "Block size: " << hash.BlockSize() << endl;
    string msg = "";
    string str;
    ifstream f("/home/stud/CryptoProg/hash/files/file");
    while (getline(f, str)) {
        msg += str;
    }
    vector<byte> digest(hash.DigestSize());
    hash.Update((const byte*)msg.data(), msg.size());
    hash.Final(digest.data());
    cout << "Message: " << msg << endl;
    cout << "Digest: ";
    StringSource(digest.data(), digest.size(), true, new HexEncoder(new FileSink(cout)));
    cout << endl;
    return 0;
}
