#include <iostream>
#include <iomanip>
#include <string>
#include "Optimization.h"
#include "Optimization.cpp"
#define LENGTH 16

using namespace std;

template <size_t rows>
void displayTable(const string*, int(&array)[rows][rows]);
void displayPath(int, const string*, int, int[]);

int main()
{
    const string cities[LENGTH] = {
        "Bialystok",
        "Bydgoszcz",
        "Gdansk",
        "Gorzow",
        "Katowice",
        "Kielce",
        "Krakow",
        "Lodz",
        "Lublin",
        "Olsztyn",
        "Opole",
        "Poznan",
        "Rzeszow",
        "Szczecin",
        "Warszawa",
        "Wroclaw"
    };

    //Odleglosci po posortowaniu. Dane wziete z Google Maps. Odleglosc w km do przejechania autem
    int distances[LENGTH][LENGTH] = { 
        {0},                                                                            //Bialystok
        {491, 0},                                                                       //Bydgoszcz
        {424, 222, 0},                                                                  //Gdansk
        {655, 293, 330, 0},                                                             //Gorzow Wlkp.
        {491, 406, 520, 470, 0},                                                        //Katowice
        {374, 357, 471, 517, 154, 0},                                                   //Kielce
        {486, 482, 596, 547, 81,  114, 0},                                              //Krakow
        {326, 226, 340, 360, 203, 153, 278, 0},                                         //Lodz
        {352, 471, 585, 634, 416, 195, 337, 305, 0},                                    //Lublin
        {225, 216, 166, 516, 479, 389, 501, 296, 385, 0},                               //Olsztyn
        {509, 413, 538, 373, 113, 274, 188, 205, 480, 491, 0},                          //Opole
        {501, 142, 358, 165, 383, 368, 458, 221, 481, 366, 286, 0},                     //Poznan
        {510, 647, 761, 712, 246, 155, 167, 445, 178, 545, 344, 622, 0},                //Rzeszow
        {756, 259, 359, 108, 570, 619, 645, 473, 733, 493, 473, 265, 812, 0},           //Szczecin
        {200, 302, 342, 465, 295, 177, 290, 136, 173, 217, 312, 311, 331, 566, 0},      //Warszawa
        {545, 311, 549, 293, 195, 348, 271, 224, 522, 509, 98,  181, 437, 393, 355, 0}  //Wroclaw
    };

    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            distances[i][j] = distances[j][i];
        }
    }

    displayTable(cities, distances);

    int length = 0;
    int path[LENGTH] = { 0 };
    for (int i = 0; i < LENGTH; i++) {
        Optimization::nearestNeighbour(distances, i, length, path);
        displayPath(i, cities, length, path);
    }
}

template<size_t rows>
void displayTable(const string* cities, int(&distances)[rows][rows]) {
    const int width = 9;
    
    cout  << setw(width + 1)  << "|";
    
    for (int i = 0; i < rows; i++) {
        cout << setw(width) << cities[i] << "|";    }

    for (int i = 0; i < rows; i++) {
        cout << "\n" << setw(width) << cities[i]  << "|";

        for (int j = 0; j < rows; j++) {
            cout << setw(width) << distances[i][j] << "|";
        }

    }
}

void displayPath(int startPos, const string* cities, int length, int path[]) {
    cout << "\nPunkt poczatkowy : " << cities[startPos] << "\n";
    cout << "Pokonana droga: " << length << "\n";
    for (int i = 0; i < LENGTH - 1; i++) {
        cout << cities[path[i]] << " -> ";
    }
    cout << cities[path[LENGTH - 1]] << "\n";
}