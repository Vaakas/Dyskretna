#include "Optimization.h"

template<size_t rows>
void Optimization::nearestNeighbour(int(*distances)[rows], int startPos, int &length, int *path) {
	//Ustawienie zmiennych poczatkowych
	length = 0;

	bool visited[rows][rows] = { false };						//Macierz odwiedzonych wierzcholkow
	int current = startPos;										//Ustawienie startowego wierzcholka jako aktualny

	setVisited(current, visited);								//Ustawienie aktualnego wierzcholka jako odwiedzony
	
	for (int i = 0; i < rows; i++) {
		path[i] = current;
		current = findClosest(current, distances, visited);		//Ustawienie znalezionego najblizszego znalezionego wierzcholka jako obecnego
		length += distances[i][current];						//Dodanie pokonanej drogi
		setVisited(current, visited);							//Ustawienie wierzcholka jako odwiedzonego
	}
};


template<size_t rows>
static int Optimization::findClosest(int current, int(*distances)[rows], bool(*visited)[rows]) {
	int closest = current;

	for (int i = 0; i < rows; i++) {
		if (!visited[i][current]) {
			if (closest != current) {
				closest = distances[current][i] < distances[current][closest] ? i : closest;
			} else {
				closest = i;
			}
		}
	}

 	return closest;
}

template<size_t rows>
void Optimization::setVisited(int pos, bool(*visited)[rows]) {
	for (int i = 0; i < rows; i++) {
		visited[pos][i] = true;
	}
}