#include <iostream>
#include <iomanip>
#include <sstream>
#include "Students.h"
using namespace std;
namespace NStud {
//создание манипуляторов
    ostream &manipStr(ostream &out) {
        out << setw(10) << setfill('.')
            << resetiosflags(ios::right)
            << setiosflags(ios::left);
        return out;
    }

    ostream &manipInt(ostream &out) {
        out << setw(4) << setfill('_')
            << resetiosflags(ios::left)
            << setiosflags(ios::right);
        return out;
    }

// перевантаження потоків
    ostream &operator<<(ostream &out, const STUDENTS &stud) {
        out << manipStr << stud.last_name
            << manipStr << stud.num;
        int n = sizeof(stud.mass) / sizeof(int);
        for (int i = 0; i < n; ++i)
            out << manipInt << stud.mass[i];
        return out;
    }

    istream &operator>>(istream &in, STUDENTS &stud) {
        getline(in, stud.last_name, ';');
        getline(in, stud.num, ';');
        string examsstr;
        getline(in, examsstr);
        stringstream examsstream(examsstr);
        int n = sizeof(stud.mass) / sizeof(int);
        for (int i = 0; i < n && examsstream.good(); ++i) {
            string tmp;
            examsstream >> tmp;
            if (examsstream) stud.mass[i] = atoi(tmp.c_str());
        }
        return in;
    }
   double sort(STUDENTS f, int count) {
       for (int startIndex = 0; startIndex < count; ++startIndex) {
           int smallestIndex = startIndex;
           for (int currentIndex = startIndex + 1; currentIndex < count; ++currentIndex) {
               if (f->num[currentIndex] < f->num[smallestIndex])
                   smallestIndex = currentIndex;
           }
           STUDENTS z=f[startIndex];
           f[startIndex]=f[smallestIndex];
           f[smallestIndex]=z;
          // swap(f[startIndex], f[smallestIndex]);
       }

       cout<<"============================="<<endl;
   }

    double avarageTstud(const STUDENTS& st) //середній бал студента
    {
        double avarage = 0.0;
        int n = sizeof(st.mass) / sizeof(int);
        for (int i = 0; i < n; ++i) {
            avarage += st.mass[i];
        }

        if (avarage / n > 40) {
            cout<<st.last_name<<" "<<st.num;
        }
        return 0;
    }

    const STUDENTS *findStud(const STUDENTS *gr, int n, string name) //пошук студента по першим літерам
    {
        const STUDENTS *result = nullptr;
        for (int i = 0; i < n; ++i) {
            if (gr[i].last_name.find(name) != string::npos) {
                result = &gr[i];
                cout<<gr[i].last_name<<endl;
                break;
            }
        }
        return result;
    }

    void input(STUDENTS*gr, int n,istream &in) //введення з потоку
{
    int i = 0;
    while (i<n &&!in.eof()) {
    in >> gr[i++];
}
}

void output(const STUDENTS *gr, int n, ostream &out) //введення у потік
{
    for (int i = 0; i < n; ++i)
        out << gr[i] << endl;
}


}


