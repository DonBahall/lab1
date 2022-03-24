#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include "Students.h"
using namespace std;
//фукнція підрахунку не пустих рядків у потоці
int countString(istream& in)
{
    int count = 0;
    string line;
    while (!in.eof())
    {
        getline(in, line);
        if (in && !line.empty()) ++count;
    }
    return count;
}

int main() {

        //ifstream fin("D:\\Students_info\\Students.txt"); // открыли файл для чтения
        string inputDataStr = "Ivanov;5;56 100 78 56 90\nPetrov;3;56 100 34 89 68\nSmirnov;4;45 67 89 44 56";
        istringstream inputData(inputDataStr);
        int n = countString(inputData);
    NStud::STUDENTS *mas = new NStud:: STUDENTS[n];


        inputData.seekg(0);//відновлюемо данні у потоці
        inputData.clear(); //скинути прапорці помилок
        ostringstream resultData;

    NStud::input(mas, n, inputData);
    NStud::output(mas, n, resultData);

    ofstream fout("input.txt");
    cout << resultData.str() << endl;
    cout << "===============================";
    cout<<endl;
    fout << resultData.str() << endl;
    fout.close();
    resultData.str("");//очищення потоку
    string name;
    cin>>name;
    NStud::sort(mas,n);

    NStud::findStud(mas,n, name);

    //NStud::sort(mas,n);

for(int b=0 ;b<n;b++){
    NStud::avarageTstud(mas[b]);
    cout<<endl;
}


}
