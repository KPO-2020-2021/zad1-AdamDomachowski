#include <iostream>
#include <cstring>
#include <cassert>
#include "WyrazenieZesp.hh"

using namespace std;

void WyswietlPYTANIE(WyrazenieZesp  WyrZ){

    //showpos - pokazuje plusy przed liczba jesli > 0
    //noshowpos - wylacza te opcje.

    cout << " (" << WyrZ.Arg1.re << showpos << WyrZ.Arg1.im << "i) " << noshowpos;
    if(WyrZ.Op == 0) cout << "+"; //WyrZ.Op przyjmuje wartosci od 0 - 3 nalezy je potem odszyfrowac
    if(WyrZ.Op == 1) cout << "-";
    if(WyrZ.Op == 2) cout << "*";
    if(WyrZ.Op == 3) cout << "/";
    cout << " (" << WyrZ.Arg2.re << showpos << WyrZ.Arg2.im << "i) =" << noshowpos << endl;
}

