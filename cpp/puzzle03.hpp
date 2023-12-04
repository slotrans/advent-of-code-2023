#include <vector>
#include <string>
#include <cctype>
#include <pystring.h>
#include "aocutil.hpp"

using std::string;
using std::vector;


struct Grid {
    int xSize;
    int ySize;
    char* points;
    //
    public:
    char getAtXY(int x, int y) const {
        if(x < 0 || x >= xSize || y < 0 || y >= ySize) {
            return '.';
        }
        return points[y*xSize + x];
    }
    void setAtXY(int x, int y, char val) {
        points[y*xSize + x] = val;
    }
    bool hasAdjacentSymbol(int x, int y) const {
        for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
                if(dx == 0 && dy == 0) {
                    continue;
                }
                char adjacent = getAtXY(x+dx, y+dy);
                if(adjacent != '.' && !isdigit(adjacent)) {
                    return true;
                }
            }
        }
        return false;
    }
} ;

Grid GridFromFile(const string &filename) {
    vector<string> lines = ReadFileAsLines(filename);

    Grid grid;
    grid.ySize = lines.size();
    grid.xSize = lines[0].size();
    grid.points = new char[grid.xSize*grid.ySize];

    for(int y = 0; y < grid.ySize; y++) {
        for(int x = 0; x < grid.xSize; x++) {
            grid.setAtXY(x, y, lines[y][x]);
        }
    }

    return grid;
}

vector<int> FindPartNumbers(const Grid &grid) {
    vector<int> part_numbers;

    vector<char> digits;
    vector<int> x_locations;
    for(int y = 0; y < grid.ySize; y++) {
        digits.clear();
        x_locations.clear();
        for(int x = 0; x < grid.xSize; x++) {
            char val = grid.getAtXY(x, y);
            if(isdigit(val)) {
                digits.push_back(val);
                x_locations.push_back(x);
            }

            if(!isdigit(val) || x == grid.xSize-1) {
                //finished a number, check if it counts
                for(int x_temp : x_locations) {
                    if(grid.hasAdjacentSymbol(x_temp, y)) {
                        part_numbers.push_back(std::stoi(string(digits.begin(), digits.end())));
                        break;
                    }
                }
                digits.clear();
                x_locations.clear();
            }
        }
    }

    return part_numbers;
}

int SumOfPartNumbers(const string &filename) {
    Grid grid = GridFromFile(filename);

    int sum = 0;
    for(int part_num : FindPartNumbers(grid)) {
        sum += part_num;
    }

    return sum;
}
