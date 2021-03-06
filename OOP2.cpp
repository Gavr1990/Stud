#include <iostream>
#include <math.h>

using namespace std;

class Point
{
    public:
        float x, y;
        Point(float x, float y)
        {
            this->x=x;
            this->y=y;
        }
        ~Point(){}
        void SetData(float x, float y)
        {
            this->x=x;
            this->y=y;
        }
};

class Graphicpoint : public Point
{
	public:
		string c;
		Graphicpoint(float x, float y, string cn);
		float Length(Point point)
		{
			return sqrt(pow(this->x-point.x,2)+pow(this->y-point.y,2));
		}
};

Graphicpoint::Graphicpoint(float x, float y, string cn):
Point(x,y),
c(cn)
{}

int main()
{
    float x, y, x1, y1;
    cout << "Enter the cordinats\n";
    cin >> x >> y;
    Point point1(x, y);
    cout << "Enter the cordinats\n";
    cin >> x1 >> y1;
    Graphicpoint point2(x1, y1, "Lolka");
    cout << "Length = " << point2.Length(point1) << endl << point1.x << point1.y << point2.x << point2.y;
    return 0;
}

