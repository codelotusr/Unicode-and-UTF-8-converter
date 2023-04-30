#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <sstream>
#include <math.h>
#include <stdio.h>

void meniu();
void konvertavimasSesioliktaine(unsigned long);
void konvertavimasDvejetaine(unsigned long);
void konvertavimasSimbolis(unsigned long);

void konvertavimasSesioliktaine(unsigned long skaicius) {
    int likutis;
    std::string sesioliktainisSkaicius;
    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (skaicius > 0) {
        likutis = skaicius % 16;
        sesioliktainisSkaicius = hex[likutis] + sesioliktainisSkaicius;
        skaicius = skaicius / 16;
    }
    int ilgis = (4 - sesioliktainisSkaicius.length());
    std::string nuliai;
    std::cout << "UNICODE: U+";
    while (ilgis > 0) {
        nuliai += "0";
        --ilgis;
    }
    std::string unikodas = nuliai + sesioliktainisSkaicius;
    std::cout << unikodas << "\n";
}

void konvertavimasDvejetaine(unsigned long skaicius) {
    std::string dvejetainisSkaicius;
    dvejetainisSkaicius = std::bitset<8>(skaicius).to_string();
    std::cout << "Bindary number: " << dvejetainisSkaicius << "\n";
    std::cout << "UTF-8: " << "\n";
}

void konvertavimasSimbolis(unsigned long skaicius) {
    std::cout << "CHAR: " << char(skaicius - 48);
}

void meniu() {
    unsigned long simbolioKodas;
    std::cout << "Sveiki atvyke į Unicode/UTF-8 konverterį!\n\n";
    std::cout << "Įveskite simbolio kodą:\n";
    std::cin >> simbolioKodas;
    std::system("clear");
    konvertavimasSesioliktaine(simbolioKodas);
    konvertavimasDvejetaine(simbolioKodas);
    konvertavimasSimbolis(simbolioKodas);
}



int main() {
    meniu();
    return 0;
}