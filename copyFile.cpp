#include <iostream>

using namespace std;

void copyFile()
{
    char sourceFile[50],destinationFile[50];  //源文件，副本文件名或路径
    cin >> sourceFile >> destinationFile;
    if(access(dirname,F_OK) == -1)  //若文件不存在
    {
        cout << strerror(2) << endl;
    }
    else
    {

    }
}
