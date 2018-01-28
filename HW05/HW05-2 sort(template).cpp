#include <iostream>
#include <cstdlib>

using namespace std;

class Engine{
	
	private:
		
		int CC;
		int type;
		int weight;
		
	public:
		
		void show(){
			
			cout << CC << " " << type << " " << weight << endl;
			
		}
		
		Engine()
		{
			//default constructor
			cout << "default costructor" << endl;
		}
		
		Engine(const int &c, const int &t, const int &w)
		{
			//non default constructor
			cout << "non default constructor" << endl;
			CC = c;
			type = t;
			weight = w;
		}
		
		~Engine()
		{
			//destructor
			cout << "destructor is called." << endl;	
		}
		
		
		Engine(const Engine &e){
			
			//copy constructor 
			cout << "copy constructor is called." << endl;
			CC = e.CC;
			type = e.type;
			weight = e.weight;
		}
		
		Engine& operator = (const Engine &e)
		{
			//assigment operator
			cout << "assigment operator is called." << endl;
			CC = e.CC;
			type = e.type;
			weight = e.weight;
			
			return *this;	
		}
		
		Engine(Engine &&e)
		{
			//move consructor
			cout << "move constructor is called." << endl;
			
			CC = e.CC;
			type = e.type;
			weight = e.weight;
		}
		
		Engine& operator = (Engine&& e){
			
			//assigment operator
			cout << "move assigment operator is called." << endl;
			CC = e.CC;
			type = e.type;
			weight = e.weight;
			
			return *this;	
		}
		
};

int main()
{
	/*Engine e0;
	Engine e1(2000, 1, 100);
	Engine e2(e1);
	Engine e3 (std::move(e2));
	Engine e4;
	e4 = std::move(e2);*/
	
	Engine E1(1,1,1);
	Engine E2(2,2,2), E3(3,3,3);
	
	E3 = (E2 = E1);
	
	E1.show();
	E2.show();
	E3.show();
	
	return 0;
}

