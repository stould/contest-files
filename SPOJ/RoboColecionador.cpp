#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for(i = 0; i < (n); i++)

int i, j, n, m, s, starti, startj, amount;
char maze[110][110], sequence[100010], base;
int di[4] = {-1, 1, 0, 0};
int dj[4] = { 0, 0, 1, -1};

void update(char inst)
{
    if(inst == 'F')
    {
        if(base == 'N')
        {
            if(starti + di[0] >= 0 && starti + di[0] < n && startj + dj[0] >= 0 && startj + dj[0] < m && maze[starti+di[0]][startj+dj[0]] != '#')
            {
                starti = starti + di[0];
                startj = startj + dj[0];
                if(maze[starti][startj] == '*')
                {
                    amount++;
                    maze[starti][startj] = '.';
                }
            }
        }
        else if(base == 'S')
        {
            if(starti + di[1] >= 0 && starti + di[1] < n && startj + dj[1] >= 0 && startj + dj[1] < m && maze[starti+di[1]][startj+dj[1]] != '#')
            {
                starti = starti + di[1];
                startj = startj + dj[1];
                if(maze[starti][startj] == '*')
                {
                    amount++;
                    maze[starti][startj] = '.';
                }
            }
        }
        else if(base == 'L')
        {
            if(starti + di[2] >= 0 && starti + di[2] < n && startj + dj[2] >= 0 && startj + dj[2] < m && maze[starti+di[2]][startj+dj[2]] != '#')
            {
                starti = starti + di[2];
                startj = startj + dj[2];
                if(maze[starti][startj] == '*')
                {
                    amount++;
                    maze[starti][startj] = '.';
                }
            }
        }
        else
        {
            if(starti + di[3] >= 0 && starti + di[3] < n && startj + dj[3] >= 0 && startj + dj[3] < m && maze[starti+di[3]][startj+dj[3]] != '#')
            {
                starti = starti + di[3];
                startj = startj + dj[3];
                if(maze[starti][startj] == '*')
                {
                    amount++;
                    maze[starti][startj] = '.';
                }
            }
        }
    }
    else
    {
        if(inst == 'D')
        {
            if(base == 'N')
            {
                base = 'L';
            }
            else if(base == 'S')
            {
                base = 'O';
            }
            else if(base == 'L')
            {
                base = 'S';
            }
            else
            {
                base = 'N';
            }
        }
        else if(inst == 'E')
        {
            if(base == 'N')
            {
                base = 'O';
            }
            else if(base == 'S')
            {
                base = 'L';
            }
            else if(base == 'L')
            {
                base = 'N';
            }
            else
            {
                base = 'S';
            }
        }
    }
}

int main(void)
{
    for(; scanf("%d%d%d", &n, &m, &s) && !(n == 0 && m == 0 && s == 0); )
    {
        amount = 0;
        REP(i, n)
        {
            scanf("%s", maze[i]);
            REP(j, m)
            {
                if(maze[i][j] == 'N' || maze[i][j] == 'S' || maze[i][j] == 'L' || maze[i][j] == 'O')
                {
                    starti = i;
                    startj = j;
                    base = maze[i][j];
                }
            }
        }
        scanf("%s", sequence);
        REP(i, s)
        {
            update(sequence[i]);
        }
        printf("%d\n", amount);
    }
    return 0;
}
