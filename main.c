#include <stdio.h>
int gra();

int main()
{
    printf("MASTER MIND - gra polega na odgadnięciu szyfru. \n \
     Masz do dyspozycji 5 znaków: R, B, Y, G, C \n \
     znaki mogą się powtarzać \n \
     podawanych znakow nie oddzielaj spacja, podawaj ich tylko 5 i koncz ruch ENTER \n \
     mozesz wykonac kilka prob naraz, oddzielajac je pojdyncza SPACJA \n \
     po każdej probie bedziesz informowany: \n \
     MIEJSCE - dobry znak na wlasciwym miejscu, \n \
     TRAF - dobry znak, ale na zlym miejscu (bez uwzglednioniania znakow w MIEJSCA) \n \
     Powodzenia! \n");

    gra();
    
    return 0;
}