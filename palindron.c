/*Sprawdzenie czy podany tekst jest palindronem*/
#include <stdio.h> /*Operacje wejścia i wyjścia*/
#include <string.h> /*Operacje na znakach*/
#define MAX /*stała, maksymalny rozmiar tablicy*/
int CzyPalindron(char* slowo) /*funkcja zwracająca wartości 1 i 0, char* oznacza ciąg znaków*/
{
    int dlugosc = strlen(slowo); /*strlen zwraca długość słowa*/
    int polowa = ceil(dlugosc / 2); /*ceil zaokrągla wynik do góry*/
    for(int i = 0; i < polowa; i++)
    {
        if(slowo[i] =! slowo[dlugosc - 1 - i])
        {
            return 0;
        }
        return 1;
    }
}

