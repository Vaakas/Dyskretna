#pragma once
class Optimization {
public:
	template<size_t rows>
	static void nearestNeighbour(int(*distances)[rows], int startPos, int &length, int *path);
private:
	template<size_t rows>
	static int findClosest(int current, int(*distances)[rows], bool(*visited)[rows]);
	
	template<size_t rows>
	static void setVisited(int pos, bool(*visited)[rows]);
};

