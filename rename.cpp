#include <iostream>

using namespace std;

void reName()
{
    char filename[20],filename1[20];
    cin >> filename >> filename1;
    if(rename(filename,filename1) == 0)
    {
        cout << "修改成功！" <<endl;
    }
    else
    {
         cout << "修改失败！" <<endl;
    }
}
