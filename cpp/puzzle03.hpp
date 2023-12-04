#include <iostream>
#include <fmt/ranges.h>
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cctype>
#include <pystring.h>
#include "aocutil.hpp"

using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;


struct Point {
    int x;
    int y;
    //
    bool operator==(const Point&) const = default;
} ;

template<> struct std::hash<Point> {
    std::size_t operator()(const Point &p) const {
        return std::hash<int>{}(p.x) ^ (std::hash<int>{}(p.y) << 1);
    }
} ;

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
    unordered_set<Point> adjacentGears(int x, int y) const {
        unordered_set<Point> gears;
        for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
                if(dx == 0 && dy == 0) {
                    continue;
                }
                char adjacent = getAtXY(x+dx, y+dy);
                if(adjacent == '*') {
                    Point p = {.x=(x+dx), .y=(y+dy)};
                    gears.insert(p);
                }
            }
        }
        return gears;
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

vector<int> FindGearRatios(const Grid &grid) {
    vector<int> gear_ratios;
    unordered_map<Point, vector<int>> part_numbers_by_gear;

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

            if(!digits.empty() && (!isdigit(val) || x == grid.xSize-1)) {
                //finished a number, check if it counts
                int temp_part_number = std::stoi(string(digits.begin(), digits.end()));
                unordered_set<Point> nearbyGears;
                for(int x_temp : x_locations) {
                    nearbyGears.merge(grid.adjacentGears(x_temp, y));
                }

                for(Point p : nearbyGears) {
                    //std::cout << "part_num " << temp_part_number << " is near a gear at (" << p.x << "," << p.y << ")" << std::endl;
                    part_numbers_by_gear[p].push_back(temp_part_number);
                }

                digits.clear();
                x_locations.clear();
            }
        }
    }

    for(auto pair : part_numbers_by_gear) {
        //std::cout << "gear at (" << pair.first.x << "," << pair.first.y << ") is near parts: " << fmt::format("{}", pair.second) << std::endl;
        if(pair.second.size() == 2) {
            int temp_gear_ratio = pair.second[0] * pair.second[1];
            //std::cout << "  adding gear ratio " << temp_gear_ratio << std::endl;
            gear_ratios.push_back(temp_gear_ratio);
        }
    }

    return gear_ratios;
}

int SumOfGearRatios(const string &filename) {
    Grid grid = GridFromFile(filename);

    int sum = 0;
    for(int gear_ratio : FindGearRatios(grid)) {
        sum += gear_ratio;
        //std::cout << "added " << gear_ratio << ", sum is now " << sum << std::endl;
    }
    //std::cout << "final sum is " << sum << std::endl;

    return sum;
}
