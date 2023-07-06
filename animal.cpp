#include <iostream>

class Animal
{
	std::string sound;
	std::string spcie;
	std::string name;
	std::string type_of_food;
	std::string gender;
	std::string movement_type;
	std::string respiratory_system;
	std::string breathing_system;
protected:
static int constructerCount;

public:
	int age;
	int speed;
	int lifespan;
	int weight;
	int feet;
	int teeth;

public:

	Animal()
	{
		std::cout << __func__ << std::endl;
		++constructerCount;
	}
	
	bool operator >(Animal& other)
	{
		std::cout << __func__ << std::endl;
		if (this->weight > other.weight)
		{
			return true;
		}
		else return false;
	}
	bool operator<(Animal& other)
	{
		std::cout << __func__ << std::endl;
		if (this->weight < other.weight)
		{
			return true;
		}
		else
			return false;
	}
	bool operator ==(Animal& other)
	{
		std::cout << __func__ << std::endl;
		if (this->weight == other.weight)
		{
			return true;
		}
		else
			return false;
	}

	void operator ()()
	{
		std::cout << "This is our Animal functor \n";
	}
	Animal& operator ++()
	{
		std::cout << "Prefix " << __func__ << std::endl;
		weight++;

		return *this;
	}
	Animal operator++(int)
	{
		std::cout << "Postix " << __func__ << std::endl;
		Animal temp = *this;
		++weight;
		return temp;
	}


       static int getCount()
    {
	return constructerCount;
    }

};
int Animal::constructerCount=0;
class Mammal :public Animal
{
	int fins_count;
	int  claws_count;
	int ears;
	std::string habitat;
public:

	Mammal()
	{
		std::cout << __func__ << std::endl;
		++constructerCount;

	}

};

class Lion :public Mammal
{
	int main_lenght;

public:
	Lion()
	{
		std::cout << __func__ << std::endl;
		++constructerCount;

	}

};


int main(int argc, char** argv)
{
	Lion lion1;
	Lion lion2;
	lion1.weight = 45;
	lion2.weight = 35;
	bool isHavier = lion1 > lion2;
	std::cout << "First lion is havier than the second one statment is " << std::boolalpha << isHavier << std::endl;
	bool isSmaller = lion1 < lion2;
	std::cout << "First lion is smaller than the second one statment is " << std::boolalpha << isSmaller << std::endl;
	bool isEqual = lion1 == lion2;
	std::cout << "First lion is equal to the second one statment is " << std::boolalpha << isEqual << std::endl;
	lion1();
	Animal obj;
	obj++;
	++obj;
	int count=Animal::getCount();
	std::cout << "We have called " << count << " constructors \n";
	return 0;
}
