#include <iostream>

using namespace std;

class Point
{
    private:
        float m_x, m_y;
    public:
        Point(float x, float y)
        {
            m_x=x;
            m_y=y;
        }
        float getX()
        {
            return m_x;
        }
        float getY()
        {
            return m_y;
        }
        void output()
        {
            printf("x = %.1f", m_x);
            cout << "; ";
            printf("y = %.1f", m_y);
        }
};

int main()
{
    float x, y;
    cout << "Enter the cordinats\n";
    cin >> x >> y;
    Point point1(x, y);
    point1.output(); 
    return 0;
}
