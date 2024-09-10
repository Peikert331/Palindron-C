/*Sprawdzenie czy podany tekst jest palindronem*/
#include <stdio.h> /*Operacje wejścia i wyjścia*/
#include <string.h> /*Operacje na znakach*/
#define MAX 1000 /*Stała, maksymalny rozmiar tablicy to 1000*/
void UsunSpacje(char* tablicazrodlowa, char* tablicadocelowa) /*Funkcja nie zwraca wartości*/
{
    int j = 0; /*Deklaracja dodatkowej zmiennej, która będzie zawierała indeksy słowa bez spacji*/
    for(int i = 0; tablicazrodlowa[i] != '\0'; i++) /*Pętla, która iteruje po wszystkich znakach tekstu użytkownika, aż do znaku końca linii*/
    {
        if(tablicazrodlowa[i] != ' ') /*Instrukcja warunkowa, która sprawdza, czy znak w tekście użytkownika nie jest spacją*/
        {
            tablicadocelowa[j++] = tablicazrodlowa[i]; /*Jeśli znak nie jest spacją, zostaje wpisany do docelowej tablicy na pierwsze wolne miejsce*/
        }
    }
    tablicadocelowa[j] = '\0'; /*Dodajemy na końcu nowego ciągu znaków bez spacji znak końca linii*/
}
int CzyPalindron(char* slowo) /*Funkcja zwracająca wartości 1 i 0, char* oznacza ciąg znaków*/
{
    int dlugosc = strlen(slowo); /*Strlen zwraca długość słowa*/
    int polowa = (dlugosc + 1) / 2; /*Jeśli liczba parzysta, dzieli na poł, jeśli liczba nieparzysta, dzielenie przez 2 zaokrąglone jest w górę*/
    for(int i = 0; i < polowa; i++) /*Pętla iteruje po znakach od początku wyrazu do połowy*/
    {
        if(tolower(slowo[i]) != tolower(slowo[dlugosc - 1 - i])) /*Instrukcja warunkowa sprawdza, czy pierwsze i ostatnie litery są takie same, tolower zmniejsza duże litery */
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
    fgets(tekst, MAX, stdin); /*Za pomocą fgets odczytujemy dane, scanf_s kończy wczytywanie na 1 spacji, podajemy tablicę znaków, rozmiar tablicy i strumień wejściowy, stdin to dane wpisywane z klawiatury */
    tekst[strcspn(tekst, "\n")] = '\0'; /*Funkcja fgets dodaje na końcu znak nowej linii, funkcja strcspn zwraca indeks pierwszego wystąpienia znaku nowej linii, który zamieniamy na znak końca ciągu znaków*/
    char slowobezspacji[MAX]; /*Deklaracja tablicy znaków*/
    UsunSpacje(tekst, slowobezspacji); /*Wywołanie funkcji usuwającej z tekstu spacje, podajemy tekst od użytkownika oraz pustą tablicę, do której zostanie wpisany tekst bez spacji*/
    if(CzyPalindron(slowobezspacji) == 1) /*Instrukcja warunkowa, która sprawdza czy funkcja zwróciła wartość 1*/
    {
        printf("%s jest palindronem\n", tekst); /*Wyświetla informację, w "" wpisujemy %s, po przecinku zmienną*/
    }
    else
    {
        printf("%s nie jest palindronem", tekst); /*Wyświetla informację, jeśli funkcja nie zwróciła wartości 1*/
    }
}
