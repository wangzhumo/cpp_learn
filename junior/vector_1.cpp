#include <iostream>
#include <vector>

using namespace std;
// using std::vector;

int main() {
    vector<int> vt1 = {1, 2, 3, 4};

    cout << "capacity = " << vt1.capacity() << endl;
    for (int i = 0; i < vt1.size(); i++) {
        cout << "Index = " << vt1[i] << endl;
    }

    //尾部插入
    vt1.push_back(5);
    cout << "capacity = " << vt1.capacity() << endl;
    for (int i = 0; i < vt1.size(); i++) {
        cout << "Index = " << vt1[i] << endl;
    }

    //中间插入
    vt1.insert((vt1.end() -2),20);
    cout << "capacity = " << vt1.capacity() << endl;
    for (int i = 0; i < vt1.size(); i++) {
        cout << "Index = " << vt1[i] << endl;
    }

    //删除
    vt1.erase((vt1.end() -3));
    cout << "capacity = " << vt1.capacity() << endl;
    for (int i = 0; i < vt1.size(); i++) {
        cout << "Index = " << vt1[i] << endl;
    }
    return 0;
}