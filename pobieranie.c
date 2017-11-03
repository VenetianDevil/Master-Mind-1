#include<stdio.h>

int pobranie()
{
    int n=5;
    char proba[n+1];
    for(int i=0; i<n+1; i++) // pobranie strzalow do tablicy
    {
        char a=0;
        printf("%d.= ", i);
        scanf("%c", &a);
        proba[i]=a;
    }

    for (int j=0; j<n; j++ ) // wypisanie zawartosci tablicy proba
    {
        char a=proba[j];
        printf("%c \n", a);
    }
}

int main()
{
    for(int i=0; i<10; i++)
    pobranie();

    return 0;
}