#include <iostream>
#include <fstream>
#include <string>


using namespace std;

string number;
size_t x;

string numberCat(string line)
{
    x = line.find("x");
    return number = line.substr(0, x);
}

int main()
{
    string line;
    int l, w, h, a, s;
    int a1, a2, a3;
    int all = 0;
    
    ifstream file;
    file.open("Dane_2_1.txt",ios::in);

    if (!file.good())
        std::cout << "File do not exist";
   while (getline(file, line))
   {
        std::cout << "line: " << line << endl;
        l = stoi(numberCat(line));
        line.erase(0, ++x);
        w = stoi(numberCat(line));
        line.erase(0, ++x);
        h = stoi(line);

        //std::cout << "l: " << l << endl;
        //std::cout << "w: " << w << endl;
        //std::cout << "h: " << h << endl;

        a1 = l * w;
        a2 = w * h;
        a3 = h * l;

        if (a1 <= a2 && a1 <= a3)
            s = a1;
        else if (a2 <= a1 && a2 <= a3)
            s = a2;
        else
            s = a3;

        std::cout << "a1: " << a1 << endl;
        std::cout << "a2: " << a2 << endl;
        std::cout << "a3: " << a3 << endl;
        std::cout << "s: " << s << endl;
        a = 2 * a1 + 2 * a2 + 2 * a3;
        std::cout << "a: " << a << endl;
        a = a + s;
        std::cout << "a + s: " << a << endl;
        all = all + a;

        std::cout << "all: " << all << endl;
    }
    //std::cout << "all: " << all << endl;
}
