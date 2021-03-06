#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define n 5
char wybrane[n];
char proba[n+1];
char wartosci[5]={'q', 'w', 'e', 'a', 's'};

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
 }// koniec f. losowanie

int pobranie()
{
    scanf("%5s", proba); // pobranie pierwszych pieciu znakow do proba[]
    while((getchar())!='\n');

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

    char dopasowane[m];
    int c=0;
    int a=0;
    int d=0;
    for(int i=0; i<m; i++) // petla wybiera wyraz do sprawdzania z pozostalych z proba[]
    {
        int b=0;   
        a=pozostale[i]; // wybranie indeksu do sprawdzania z proby[a]
        int j=0;
    while(b==0 && j<m) // sprawdzanie albo az zostanie przyporzadkowany, albo jak przejdzie prze wszystkie i nie bedzie trafu
    {   
        c=pozostale[j];
        if(proba[a]==wybrane[c]) //porownanie z elementem wybrane[c]
        {   
            b=1; // jeśli jest traf
            if(d>0) // jesli jakies elementy zostaly oznaczone jako dopasowane TRAF
            {
                for(int k=0; k<d; k++) // sprawdzenie czy nie zostal dopasowany ponownie do tego samego elementu
                {
                    if(c==dopasowane[k])
                    b=0; // jesli tak, to nie zostaje on liczony jako TRAF
                }
            }
            if(b==1) //jesli jest do nowe dopasowanie
            {
                dopasowane[d]=c;// zapisujemy indeks do juz dopasowanych elementow
                d++;
            }
        }
        j++;
        traf+=b;
    }
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

void dodawanie(int wynik, char nick[]) // dodawanie wyniku 
{
    FILE *ranking;
    ranking=fopen("ranking.txt", "a");

    fprintf(ranking, "\n%d %s", wynik, nick); //dopisanie wyniku do pliku
    fclose(ranking);
    return;
}// koniec f. dodawanie

struct rank //struktura rankingu
{
    int wynik;
    char nick[25];
};

typedef char NICK[25]; 

int sortowanie() //sortowanie rankingu
{
    struct rank pozycja[100];

    FILE *rank;
    rank=fopen("ranking.txt", "r"); // otwarcie pliku z wynikami

    int a=0;
    while(fscanf(rank, "%d %s", &pozycja[a].wynik, pozycja[a].nick)==2) //wczytanie danych z pliku
    a++;

    int k;
    for (k=a-1; k>0; k--) //sortowanie danych wzgledem wyniku
    {
        for(int j=0; j<k; j++)
        {
            if(pozycja[j].wynik>pozycja[j+1].wynik) // porownywanie i ewentualna zamiana wyniku wraz z graczem
            {
                int temp = pozycja[j].wynik;
                pozycja[j].wynik=pozycja[j+1].wynik;
                pozycja[j+1].wynik=temp;

                NICK zam;
                strcpy(zam, pozycja[j].nick);
                strcpy( pozycja[j].nick, pozycja[j+1].nick);
                strcpy(pozycja[j+1].nick, zam);
            }
        }
    }

    printf("|%5s | %-25s|\n", "wynik", "nick");
    printf("=================================\n");

    int i;
    for(i=0; i<a; i++) // wypisanie rankingu w tabelce
    {
        printf("|%5d | %-25s|\n", pozycja[i].wynik, pozycja[i].nick);
    }
    return 0;
}// koniec f. sortowanie

int gra()
{
    losowanie();
    
    int stop=0;
    int miejsce=0;
    int razy=0;
    
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
    razy++;
    printf("\n");
    }
    
    printf("BRAWO! KONIEC GRY! UDALO CI SIE W -- %d -- PROBACH! \n", razy);
    
    char nick[25];
    printf("Podaj nick do zapisania wyniku: ");
    scanf("%25s", nick);

    dodawanie(razy, nick);

    int r=0;
    printf("Chcesz zobaczyc ranking, podaj 1: ");
    scanf ("%d", &r);
    printf("\n");
    if(r==1)
    sortowanie();
    else
    exit(0);
    return 0;
}