#include <iostream> 
#include <math.h> 

using namespace std; 

class Car 
{ 
	protected:
		float m_x, m_y, m_r, m_q; 
		string m_name;
	public: 
		Car(float x, float y, float r, float q, string name); 
		~Car(){}; 
		float krut() const
		{
			 return m_x/m_y*9.8;
		} 
		float plosh() const
		{
			return m_r*2+m_q*2;
		} 
		void print()
		{
			cout << "\nName of car is a " << m_name << " Nice car! " << "Good car!";
		} 
};

Car::Car(float x, float y, float r, float q, string name):
m_x(x),//Мощность 
m_y(y),//Обороты 
m_r(r),//Ширина 
m_q(q),//Длинна 
m_name(name)//Название машины
{}

class NameCar : public Car 
{ 
	public: 
		NameCar(float x, float y, float r, float q, string name);
		~NameCar(){}
		float krut() const
		{
			 return m_x/m_y*9.4;
		} 
		float plosh() const
		{
			return m_r*2+m_q*3;
		} 
		void print()
		{
			cout << "\nName of car is a " << m_name << " Nice car!";
		} 
}; 

NameCar::NameCar(float x, float y, float r, float q, string name):
Car(x, y, r, q, name)
{}

class Complect : public NameCar 
{
	public: 
		Complect(float x, float y, float r, float q, string name);
		float krut() const
		{
			return m_x/m_y*9.2;
		} 
		float plosh() const
		{
			return m_r*2+m_q*1.9;
		} 
		void print()
		{
			cout << "\nName of car is a " << m_name;
		} 
}; 

Complect::Complect(float x, float y, float r, float q, string name):
NameCar(x, y, r, q, name)
{}

int main(){ 
Car Car_1(196.5,870,2500,1600,"Nissan"); 
Car_1.print(); 
NameCar Car_2(124,675,1750,1200,"Toyota"); 
Car_2.print();
Complect Car_3(165.7,755,3500,2600,"Mazda"); 
Car_3.print(); 
return 0; 
}
