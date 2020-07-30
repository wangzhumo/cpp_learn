#include "../includes/advance/file_codec.h"
#include <string>

int main() {
    std::string fileName = "../documents/origin.txt";
    std::string outputName = "../documents/encode_file.txt";
    encodeFile(fileName.c_str(),outputName.c_str());
    return 0;
}