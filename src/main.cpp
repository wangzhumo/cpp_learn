#include "../includes/advance/file_codec.h"

int main() {
    char *fileName =  "../documents/origin.txt";
    char *outputName = "../documents/encode_file.txt";
    encodeFile(fileName,outputName);
    return 0;
}