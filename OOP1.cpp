#include <iostream>

using namespace std;

class Point
{
    private:
        float x, y;
    public:
        Point(float x, float y)
        {
            this->x=x;
            this->y=y;
        }
        float getX()
        {
            return x;
        }
        float getY()
        {
            return y;
        }     
        void output()
        {
            printf("x = %.1f", x);
            cout << "; ";
            printf("y = %.1f", y);
        }
};

int main()
{
    int x, y;
    cout << "Enter the cordinats\n";
    cin >> x >> y;
    Point point1(x, y);
    point1.output(); 
    return 0;
}
