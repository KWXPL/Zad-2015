#include <iostream>
#include <string>
#include "md5.h"

using namespace std;
 
int main(int argc, char *argv[])
{
    int i = 1;
    bool flag = true;
    string added;
    string data = "yzbqklnj"; //609043

    while(flag)
    {
        //cout << i << " = ";
        added = data + to_string(i);
        added = md5(added);
        for(int j = 0; j < 5; j++)
        {
            //cout << added[j] ;
            if(added[j] != '0')
            {
                //cout << " :  " << j;
                j = 0;
                break;
            }
            else if(j == 4)
            {
                cout << "Solution is: " << i << "\n";
                flag = false;
            }
        }
        //cout << "\n";
        i++;
    }
    return 0;
}