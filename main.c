#include <stdio.h>
void gra();

int main()
{
    printf("MASTER MIND - gra polega na odgadnięciu szyfru 5 znakow. \n \
     Masz do dyspozycji 5 znaków: q, w, e, a, s \n \
     znaki mogą się powtarzać \n \
     podawanych znakow nie oddzielaj spacja, koncz ruch ENTER \n \
     po każdej probie bedziesz informowany: \n \
     MIEJSCE - dobry znak na wlasciwym miejscu, \n \
     TRAF - dobry znak, ale na zlym miejscu (bez uwzglednioniania znakow w MIEJSCA) \n \
     Powodzenia! \n");

    gra();
    
    return 0;
}