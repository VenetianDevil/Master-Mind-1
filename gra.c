#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define n 5
char wybrane[n];
char proba[n+1];
char wartosci[5]={'R', 'B', 'Y', 'G', 'C'};

void losowanie ()
{
    srand(time(0));

    for (int i=0; i<n; i++) //wybranie kodu do tab wybranych
    {
        int j=rand()%5;
        wybrane[i]=wartosci[j]; 
    }

   /* for (int i=0; i<n; i++) //wypisanie tablicy wybranych
    {
        char a=wybrane[i];
        printf(" %c \n", a);
    }*/
} // koniec f. losowanie

int pobranie()
{
    for(int i=0; i<n+1; i++) // pobranie strzalow do tablicy
    {
        char a=0;
        scanf("%c", &a);
        proba[i]=a;
    }

    /*for (int j=0; j<n; j++ ) // wypisanie zawartosci tablicy proba
    {
        char a=proba[j];
        printf("%c \n", a);
    }*/
} // koniec f. pobieranie

int poprawnosc()    // sprawdzanie czy wpisane wartosci sa zgodne z poleceniem
{
    int p=0;

    for(int i=0; i<n; i++) // wybranie strzalu
    {
        int a=proba[i];
        for(int j=0; j<n; j++) //sprawdzanie po kolei czy jest zgodny z ktorymkolwiek z wartosci
        {
            if(a==wartosci[j])
            p++; // gdy zgaza sie z jedym
        }
    }

    if(p==n) // czy wszystkie sie zwieraja
    return 0;
    else    // jesli jest jakas niepoprawana wartosc podana
    {
        printf("podales litery spoza zakresu, sprobuj ponownie!");
        return 1;
    }
} // koniec f. poprawnosc

unsigned sprawdzanie()
{
    int miejsce=0;
    int traf=0;
    int pozostale[n];
    int m=0;

    for(int i=0; i<n; i++)
    {
        if(proba[i]==wybrane[i]) // znalezienie tych na dobrym miejscu
        {
            miejsce++;  
        }
        else
        {
            pozostale[m]=i; // tabela z indekasami tych na zlym meijscu
            m++;
        }
    }

    int c=0;
    int a=0;
    for(int i=0; i<m; i++) // petla wybiera wyraz do sprawdzania z pozostalych z proba[]
    {
        int b=0;   
        a=pozostale[i]; // wybranie indeksu do sprawdzania
        for(int j=0; j<m; j++)
        {   
            c=pozostale[j];
            if(proba[a]==wybrane[c])
            b=1;
        }
        traf+=b;
    }

    printf("MIEJSCE: %d; TRAF: %d \n", miejsce, traf);

 return miejsce;
} // koniec f. sprawdzanie

unsigned koniec(unsigned m)
{
    if(m==5) // czy wszystkie miejsca sa poprawnie
    return 1;
    else
    return 0;
} // koniec f. koniec

int gra()
{
    losowanie();
    
    int stop=0;
    int miejsce=0;
    
    while(stop==0)
    {    
        int poprawne=1;
    
        while(poprawne==1)
        {
            pobranie();
            poprawne=poprawnosc();
        }    
      
    miejsce=sprawdzanie();
    stop=koniec(miejsce);
    }
    
    printf("BRAWO! KONIEC GRY \n");
}