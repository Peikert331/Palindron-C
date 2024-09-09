/*Sprawdzenie czy podany tekst jest palindronem*/
#include <stdio.h> /*Operacje wejścia i wyjścia*/
#include <string.h> /*Operacje na znakach*/
#define MAX 1000 /*Stała, maksymalny rozmiar tablicy to 1000*/
int CzyPalindron(char* slowo) /*Funkcja zwracająca wartości 1 i 0, char* oznacza ciąg znaków*/
{
    int dlugosc = strlen(slowo); /*Strlen zwraca długość słowa*/
    int polowa = (dlugosc + 1) / 2; /*Jeśli liczba parzysta, dzieli na poł, jeśli liczba nieparzysta, dzielenie przez 2 zaokrąglone jest w górę*/
    for(int i = 0; i < polowa; i++) /*Pętla iteruje po znakach od początku wyrazu do połowy*/
    {
        if(slowo[i] != slowo[dlugosc - 1 - i]) /*Instrukcja warunkowa sprawdza, czy pierwsze i ostatnie litery są takie same*/
        {
            return 0; /*Funkcja zwraca 0, gdy tekst nie jest palindronem*/
        }
    }
    return 1; /*Funkcja zwraca 1, gdy tekst jest palindronem*/
}
void main() /*Funkcja bez zwracanej wartości*/
{ 
    printf("Podaj tekst, aby sprawdzic, czy jest on palindronem\n"); /*Printf wyświetla tekst na ekranie, \n przenosi do nowej linii*/
    char tekst[MAX]; /*Deklaracja tablicy znaków, która może przechowywać maksymalnie 1000 znaków*/
    scanf_s("%s", tekst, 1000); /*Za pomocą scanf_s odczytujemy dane, %s, ponieważ oczekujemy ciągu znaków, &tekst przekazuje adres do zmiennej tekst */
    if(CzyPalindron(tekst) == 1) /*Instrukcja warunkowa, która sprawdza czy funkcja zwróciła wartość 1*/
    {
        printf("%s jest palindronem\n", tekst); /*Wyświetla informację, w "" wpisujemy %s, po przecinku zmienną*/
    }
    else
    {
        printf("%s nie jest palindronem", tekst); /*Wyświetla informację, jeśli funkcja nie zwróciła wartości 1*/
    }
}
