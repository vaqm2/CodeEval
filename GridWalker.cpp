#include <iostream>
#include <map>
#include <cmath>
#include <string>

std::map <std::string, int> accessed_Coordinates;
int accessible_Coordinates = 0;

int find_Sum(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum = sum + (num % 10);
        num = num / 10;
    }
    return sum;
}

void CountAndWalk(int x, int y)
{
    std::string coordinate = "(" + std::to_string(x) + "," + " " + std::to_string(y) + ")";
    if((find_Sum(abs(x)) + find_Sum(abs(y)) <= 19) && accessed_Coordinates.find(coordinate) == accessed_Coordinates.end())
    {
        accessible_Coordinates++;
        accessed_Coordinates.insert(std::make_pair(coordinate, 1));
        CountAndWalk(x, y+1);
        CountAndWalk(x, y-1);
        CountAndWalk(x-1, y);
        CountAndWalk(x+1, y);
    }
}

int main()
{
    CountAndWalk(0,0);
    std::cout << accessible_Coordinates << std::endl;
}
