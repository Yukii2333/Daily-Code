#include <iostream>
#include <queue>
using namespace std;
bool map[100][100] = {};
class Point
{
public:
	int x;
	int y;
	int step;
	Point(int x, int y, int step)
	{
		this->x = x;
		this->y = y;
		this->step = step;
	}
	int getX()
	{
		return x;
	}
	void setX(int x)
	{
		this->x = x;
	}
	int getY()
	{
		return y;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getStep()
	{
		return step;
	}
	void setStep(int step)
	{
		this->step = step;
	}
};
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = true;
		}
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;
		queue<Point> queue;
		bool loop = false;
		queue.push(Point(startX, startY, 0));
		while (!queue.empty())
		{
			Point cur = queue.front();
			queue.pop();
			int curx = cur.x;
			int cury = cur.y;
			if (curx == endX && cury == endY)
			{
				cout << cur.step << endl;
				loop = true;
				break;
			}
			//右
			if (curx < 99 && cury < 99 && map[curx][cury + 1] == false)
			{
				//右上
				if (curx - 1 >= 0 && cury + 3 <= 99 && map[curx - 1][cury + 3] == false)
				{
					int x = curx - 1;
					int y = cury + 3;
					map[x][y] = true;
					queue.push(Point(x, y, cur.step + 1));
				}
				//右下
				if (curx + 1 <= 99 && cury + 3 <= 99 && map[curx + 1][cury + 3] == false)
				{
					int x = curx + 1;
					int y = cury + 3;
					map[x][y] = true;
					queue.push(Point(x, y, cur.step + 1));
				}
			}
			//下
			if (curx < 99 && cury > 0 && map[curx + 1][cury] == false)
			{
				//下左
				if (curx + 3 <= 99 && cury - 1 >= 0 && map[curx + 3][cury - 1] == false)
				{
					int x = curx + 3;
					int y = cury - 1;
					map[x][y] = true;
					queue.push(Point(x, y, cur.step + 1));
				}
				//下右
				if (curx + 3 <= 99 && cury + 1 <= 99 && map[curx + 3][cury + 1] == false)
				{
					int x = curx + 3;
					int y = cury + 1;
					map[x][y] = true;
					queue.push(Point(x, y, cur.step + 1));
				}
			}
			//左
			if (curx > 0 && cury > 0 && map[curx][cury - 1] == false)
			{
				//左上
				if (curx - 1 >= 0 && cury - 3 >= 0 && map[curx - 1][cury - 3] == false)
				{
					int x = curx - 1;
					int y = cury - 3;
					map[x][y] = true;
					queue.push(Point(x, y, cur.step + 1));
				}
				//左下
				if (curx + 1 <= 99 && cury + 3 <= 99 && map[curx + 1][cury + 3] == false)
				{
					int x = curx + 1;
					int y = cury + 3;
					map[x][y] = true;
					queue.push(Point(x, y, cur.step + 1));
				}
			}
			//上
			if (curx > 0 && cury > 0 && map[curx - 1][cury] == false)
			{
				//左上
				if (curx - 3 >= 0 && cury - 1 >= 0 && map[curx - 3][cury - 1] == false)
				{
					int x = curx - 3;
					int y = cury - 1;
					map[x][y] = true;
					queue.push(Point(x, y, cur.step + 1));
				}
				//右上
				if (curx - 3 >= 0 && cury + 1 <= 99 && map[curx - 3][cury + 1] == false)
				{
					int x = curx - 3;
					int y = cury + 1;
					map[x][y] = true;
					queue.push(Point(x, y, cur.step + 1));
				}
			}
		}
		if (!loop)
		{
			cout << "impossible" << endl;
		}
	}
	return 0;
}