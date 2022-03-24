#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
using namespace std;
namespace NStud
{
struct STUDENTS{
    string last_name;
    string num;
    int mass[5];
};
    ostream& operator<<(ostream& out, const STUDENTS &Stud);
    istream& operator>>(istream& in, STUDENTS &Stud);
    // створення власних маніпуляторів
    ostream& manipStr(ostream& out);
    ostream& manipInt(ostream& out);
    double sort(STUDENTS f, int count);
    double avarageTstud(const STUDENTS&st);
    const STUDENTS* findStud(const STUDENTS* gr, int n, string name);

    void input(STUDENTS* gr,int n, istream& in); //введення з потоку
    void output(const STUDENTS*gr, int n, ostream& out); //введення у потік

}
#endif
