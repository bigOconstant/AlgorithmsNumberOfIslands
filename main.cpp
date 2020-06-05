#include <iostream>
#include <vector>
#include <assert.h>

void exploreDFS(std::vector<std::vector<char> >& grid, std::vector<std::vector<bool> >& visited, int y, int x)
{
    if (grid[y][x] == '0' || visited[y][x])
        return;

    visited[y][x] = true;

    if (y < grid.size() - 1)
        exploreDFS(grid, visited, y + 1, x);

    if (y > 0 && !visited[y - 1][x])
        exploreDFS(grid, visited, y - 1, x);

    if (x < grid[y].size() - 1)
        exploreDFS(grid, visited, y, x + 1);

    if (x > 0 && !visited[y][x - 1]) 
        exploreDFS(grid, visited, y, x - 1);
    

    return;
}

int numIslands(std::vector<std::vector<char> >& grid)
{
    int count = 0;
    std::vector<std::vector<bool> > visited;
    for (auto const& col : grid) {
        std::vector<bool> rowin;
        for (auto const& row : col) {
            rowin.push_back(false);
        }
        visited.push_back(rowin);
        rowin.clear();
    }

    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            if (!visited[y][x] && grid[y][x] == '1') {
                ++count;
                exploreDFS(grid, visited, y, x);
            }
        }
    }
    return count;
}

int main(int argc, char** argv)
{

    std::vector<std::vector<char> > test1{ { '1', '1', '1', '1', '0' },
        { '1', '1', '0', '1', '0' },
        { '1', '1', '0', '0', '0' },
        { '0', '0', '0', '0', '0' } };

    std::vector<std::vector<char> > test2{ { '1', '1', '0', '0', '0' },
        { '1', '1', '0', '0', '0' },
        { '0', '0', '1', '0', '0' },
        { '0', '0', '0', '1', '1' } };

    std::vector<std::vector<char> > test3 = { { '1', '0', '1', '1', '0', '1', '1' } };

    std::vector<std::vector<char> > test4 = {
        { '1', '1', '1' },
        { '0', '1', '0' },
        { '1', '1', '1' },
    };

    assert(numIslands(test1) == 1);
    assert(numIslands(test2) == 3);
    assert(numIslands(test3) == 3);
    assert(numIslands(test4) == 1);

    return 0;
}
