#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initial = image[sr][sc];

    queue<pair<int, int>> q;

    if (initial != color)
        q.push({sr, sc});

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;

        q.pop();

        image[i][j] = color;

        if (i + 1 < image.size() && image[i + 1][j] == initial)
        {
            q.push({i + 1, j});
        }
        if (i - 1 >= 0 && image[i - 1][j] == initial)
        {
            q.push({i - 1, j});
        }
        if (j + 1 < image[0].size() && image[i][j + 1] == initial)
        {
            q.push({i, j + 1});
        }
        if (j - 1 >= 0 && image[i][j - 1] == initial)
        {
            q.push({i, j - 1});
        }
    }

    return image;
}

// DFS

void DFS(vector<vector<int>> &image, int i, int j, int initial, int color)
{
    image[i][j] = color;

    if (i + 1 < image.size() && image[i + 1][j] == initial)
    {
        DFS(image,i+1,j,initial,color);
    }
    if (i - 1 >= 0 && image[i - 1][j] == initial)
    {
        DFS(image,i-1,j,initial,color);
    }
    if (j + 1 < image[0].size() && image[i][j + 1] == initial)
    {
        DFS(image,i,j+1,initial,color);
    }
    if (j - 1 >= 0 && image[i][j - 1] == initial)
    {
        DFS(image,i,j-1,initial,color);
    }
}

vector<vector<int>> floodFill2(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initial = image[sr][sc];

    if (initial != color)
        DFS(image, sr, sc, initial, color);

    return image;
}

int main()
{

    return 0;
}