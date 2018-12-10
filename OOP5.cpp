#include <iostream> 
#include <math.h>
#include <fstream>

using namespace std; 

class Product
{
	string m_Name;
	unsigned short m_Price, m_Day, m_Mouth, m_Year;
	public:
		Product(string Name, int Price, int Day, int Mouth, int Year);
		~Product(){}
		void SetName(string Name);
		void SetPrice(int Price);
		void SetDay(int Day);
		void SetMouth(int Mouth);
		void SetYear(int Year);
		string GetName();
		int GetPrice();
		int GetDay();
		int GetMouth();
		int GetYear();
		virtual void ChekDate();
};

Product::Product(string Name, int Price, int Day, int Mouth, int Year):
m_Name(Name),
m_Price(Price),
m_Day(Day),
m_Mouth(Mouth),
m_Year(Year)
{}

void Product::SetName(string Name) {m_Name = Name;}
void Product::SetPrice(int Price) {m_Price = Price;}
void Product::SetDay(int Day) {m_Day = Day;}
void Product::SetMouth(int Mouth) {m_Mouth = Mouth;}
void Product::SetYear(int Year) {m_Year = Year;}
string Product::GetName() {return m_Name;}
int Product::GetPrice() {return m_Price;}
int Product::GetDay() {return m_Day;}
int Product::GetMouth() {return m_Mouth;}
int Product::GetYear() {return m_Year;}
void Product::ChekDate()
{
	if ((m_Year < 2018) || ((m_Year == 2018) && (m_Mouth < 12)) || ((m_Year == 2018) && (m_Mouth < 12) && (m_Day < 7))) 
	cout << "\nTis pruduct ";
	else cout << "\nTis a fres product!";
}

class Buy : public Product
{
	int m_quantityBuyGoods, m_priceForAllPurchasedGoods, m_weightGoods;
	public:
		Buy(string Name, int Price, int Day, int Mouth, int Year, int QuantityBuyGoods, int PriceForAllPurchasedGoods, int WeightGoods);
		~Buy(){}
		void SetQuantityBuyGoods(int quantityBuyGoods);
		void SetPriceForAllPurchasedGoods(int priceForAllPurchasedGoods);
		void SetWeightGoods(int weightGoods);
		int GetQuantityBuyGoods();
		int GetPriceForAllPurchasedGoods();
		int GetWeightGoods();
};

Buy::Buy(string Name, int Price, int Day, int Mouth, int Year, int QuantityBuyGoods, int PriceForAllPurchasedGoods, int WeightGoods):
Product(Name, Price, Day, Mouth, Year),
m_quantityBuyGoods(QuantityBuyGoods),
m_priceForAllPurchasedGoods(PriceForAllPurchasedGoods),
m_weightGoods(WeightGoods)
{}

void Buy::SetQuantityBuyGoods(int QuantityBuyGoods) {m_quantityBuyGoods = QuantityBuyGoods;}
void Buy::SetPriceForAllPurchasedGoods(int PriceForAllPurchasedGoods) {m_priceForAllPurchasedGoods = PriceForAllPurchasedGoods;}
void Buy::SetWeightGoods(int WeightGoods) {m_weightGoods = WeightGoods;}
int Buy::GetQuantityBuyGoods(){return m_quantityBuyGoods;}
int Buy::GetPriceForAllPurchasedGoods(){return m_priceForAllPurchasedGoods;}
int Buy::GetWeightGoods(){return m_weightGoods;}

class Delivery : public Buy
{
	int m_Car;
	public:
		Delivery(string Name, int Price, int Day, int Mouth, int Year, int QuantityBuyGoods, int PriceForAllPurchasedGoods, int WeightGoods, int Car);
		~Delivery(){}
		void SetCar(int Car);
		int GetCar();
};

Delivery::Delivery(string Name, int Price, int Day, int Mouth, int Year, int QuantityBuyGoods, int PriceForAllPurchasedGoods, int WeightGoods, int Car):
Buy(Name, Price, Day, Mouth, Year, QuantityBuyGoods, PriceForAllPurchasedGoods, WeightGoods),
m_Car(Car)
{}

void Delivery::SetCar(int Car){m_Car = Car;}
int Delivery::GetCar(){return m_Car;}

class Provider
{
	public:
		char providerName[100], *namesProvidersProducts;
		int *quantityProvidersProducts, quantityNamesProvidersProducts, quantityQuantityProvidersProducts;
		Provider(char ProviderName[100], int QuantityNamesProvidersProducts, int QuantityQuantityProvidersProducts)
		{
			providerName[100] = ProviderName[100];
			quantityNamesProvidersProducts = QuantityNamesProvidersProducts;
			quantityQuantityProvidersProducts = QuantityQuantityProvidersProducts;
			char *namesProvidersProducts = new char [QuantityNamesProvidersProducts];
			int *quantityProvidersProducts = new int [QuantityQuantityProvidersProducts];
			ofstream f_namesProvidersProducts("namesProvidersProducts.txt", ios::out);
			for(int i = 0; i <= QuantityNamesProvidersProducts; i++)
				{ 
					f_namesProvidersProducts.put(namesProvidersProducts[i]);
					f_namesProvidersProducts.put(',');
					f_namesProvidersProducts.put(' ');
				}
			ofstream f_quantityProvidersProducts("quantityProvidersProducts.txt", ios::out);
			for(int i = 0; i <= QuantityQuantityProvidersProducts; i++)
				{ 
					f_quantityProvidersProducts.put(quantityProvidersProducts[i]);
					f_quantityProvidersProducts.put(',');
					f_quantityProvidersProducts.put(' '); 
				}
			
		}
		~Provider()
		{
			delete[] namesProvidersProducts;
			delete[] quantityProvidersProducts;
		}
			
};

int main()
{
	Delivery Milk("Milk", 50, 31, 12, 2018, 2, 100, 2, 10);
	Milk.ChekDate();
	return 0;
}

