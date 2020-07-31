//
// Created by wangzhumo on 2020/7/30.
//

#ifndef LEARN_CPP_FILE_CODEC_H
#define LEARN_CPP_FILE_CODEC_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encodeFile(const char *fileName,const char  *dstFile);

void decodeFile(const char *fileName,const char  *dstFile);

#ifdef __cplusplus
}
#endif // __cplusplus end

#endif //LEARN_CPP_FILE_CODEC_H
