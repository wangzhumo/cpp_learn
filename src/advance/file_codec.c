//
// Created by wangzhumo on 2020/7/30.
//

#include "../../includes/advance/file_codec.h"

void encodeFile(const char *fileName,const char  *dstFile){
    // 打开源文件
    FILE *inputFile = fopen(fileName,"r");
    // 打开目标文件
    FILE *outputFile = fopen(dstFile,"w");
    if (!inputFile || !outputFile){
        printf("Open File Error.");
        return;
    }

    // 循环加密
    char item;
    // 判断读出来的元素，不是结尾
    while ((item = fgetc(inputFile)) != EOF){
        // 自己做一个加密的操作
        // 加长这个char,以便于做加密，保存所有数据 ->  转为 short
        // 35    0000 0000 0010 0011   元数据
        // << 4  0000 0010 0011 0000   加密数据
        short temp = (short) item;
        // 对它操作
        temp = temp << 4;

        //使用这种方式，使得数据变成负数
        // << 4   0000 0010 0011 0000   加密数据
        //|0x8000 1000 0000 0000 0000
        //        1000 0010 0011 0000
        temp = temp | 0x8000;

        // 为后面四位 0000  加入一个随机数 0 - 16
        temp += rand() % 16;
        fprintf(outputFile,"%hd",temp);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decodeFile(const char *fileName,const char  *dstFile){
    // 读取
    // 打开源文件
    FILE *inputFile = fopen(fileName,"r");
    // 打开目标文件
    FILE *outputFile = fopen(dstFile,"w");
    if (!inputFile || !outputFile){
        printf("Open File Error.");
        return;
    }

    //          1000 0010 0011 0000
    // 先把首位的1干掉
    // << 1     0000 0100 0110 0000
    // 后面的5位是无用的数据，干掉
    // >> 5     0000 0000 0100 0110
    short temp;
    while (!feof(inputFile)){
        // 此时我们读入一个short的长度
        fscanf(inputFile,"%hd",&temp);
        // << 1
        temp = temp << 1;
        // >> 5
        temp = temp >> 5;
        // 然后把short还原到之前的 char
        char ch = (char) temp;
        // 写入文件
        fputc(ch,outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}