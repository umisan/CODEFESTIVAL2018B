#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

void generate_grid_upper(vector<vector<char>> &grid)
{
	int y = 0;
	int x = 1;
	int start_y = 0;
	int start_x = 1;
	while(true)
	{
		bool is_valid = false;
		while(true)
		{
			if(x >= 0 && y >= 0 && x < grid.size() && y < grid.size())
			{
				grid[y][x] = 'X';
				if(y > 0)
				{
					grid[y - 1][x] = '#';
				}
				if(y < grid.size() - 1)
				{
					grid[y + 1][x] = '#';
				}
				if(x > 0)
				{
					grid[y][x - 1] = '#';
				}
				if(x < grid.size() - 1)
				{
					grid[y][x + 1] = '#';
				}
				is_valid = true;
			}
			x += 1;
			y += 2;
			if(x >= grid.size() && y >= grid.size()){
				start_x += 2;
				start_y -= 1;
				x = start_x;
				y = start_y;
				break;
			}
		}
		if(!is_valid)
		{
			break;
		}
	}
}

void generate_grid_lower(vector<vector<char>> &grid)
{
	int y = -1;
	int x = -2;
	int start_y = -1;
	int start_x = -2;
	while(true)
	{
		bool is_valid = false;
		while(true)
		{
			if(x >= 0 && y >= 0 && x < grid.size() && y < grid.size())
			{
				grid[y][x] = 'X';
				if(y > 0)
				{
					grid[y - 1][x] = '#';
				}
				if(y < grid.size() - 1)
				{
					grid[y + 1][x] = '#';
				}
				if(x > 0)
				{
					grid[y][x - 1] = '#';
				}
				if(x < grid.size() - 1)
				{
					grid[y][x + 1] = '#';
				}
				is_valid = true;
			}
			x += 1;
			y += 2;
			if(x >= grid.size() && y >= grid.size()){
				start_x -= 2;
				start_y += 1;
				x = start_x;
				y = start_y;
				break;
			}
		}
		if(!is_valid)
		{
			break;
		}
	}

}

void generate_grid(vector<vector<char>> &grid)
{
	generate_grid_upper(grid);
	generate_grid_lower(grid);
	for(int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid.size(); j++)
		{
			if(grid[i][j] == '.')
			{
				grid[i][j] = 'X';
			}
		}
	}
	for(int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid.size(); j++)
		{
			if(grid[i][j] == '#')
			{
				grid[i][j] = '.';
			}
		}
	}
}

void test(vector<vector<char>> &grid)
{

}

int main()
{
	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n, '.'));
	generate_grid(grid);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
	return 0;
}
