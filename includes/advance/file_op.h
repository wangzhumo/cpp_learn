//
// Created by 王诛魔 on 12/3/20.
//

#ifndef LEARN_CPP_FILE_OP_H
#define LEARN_CPP_FILE_OP_H


#include <string>
#include <iostream>
#include <fstream>
#include <vector>



// 文件相关操作
namespace FileOps {

    // 读取文件名称为filename中的内容，并将其中包含的所有词语放进words中
    int firstCharacterIndex(const std::string &s, int start) {
        for (int i = start; i < s.length(); i++)
            if (isalpha(s[i]))
                return i;
        return s.length();
    }

    // 将字符串s中的所有字母转换成小写之后返回
    std::string lowerS(const std::string &s) {

        std::string ret = "";
        for (int i = 0; i < s.length(); i++)
            ret += tolower(s[i]);
        return ret;
    }

    // 读取文件名称为filename中的内容，并将其中包含的所有词语放进words中
    bool readFile(const std::string &filename, std::vector<std::string> &words) {

        // 文件读取
        std::string line;
        std::string contents = "";
        std::ifstream file(filename);
        if (file.is_open()) {
            while (getline(file, line))
                contents += (line + "\n");
            file.close();
        } else {
            std::cout << "Can not open " << filename << " !!!" << std::endl;
            return false;
        }

        // 简单分词
        // 这个分词方式相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做demo展示用
        int start = firstCharacterIndex(contents, 0);
        for (int i = start + 1; i <= contents.length();)
            if (i == contents.length() || !isalpha(contents[i])) {
                words.push_back(lowerS(contents.substr(start, i - start)));
                start = firstCharacterIndex(contents, i);
                i = start + 1;
            } else
                i++;

        return true;
    }

}

#endif //LEARN_CPP_FILE_OP_H
