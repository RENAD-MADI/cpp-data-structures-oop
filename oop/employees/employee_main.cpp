//Aseel Khaled Al-Salmi 
#include <iostream>
#include <vector>
#include <iterator>
#include "person.h"
#include "employee.h"

using namespace std;

int main(void)
{
	cout << "Welcome to main()! " << endl;
	int num = 0;
	while (true)
	{

		cout << "Enter num of employees ( <= 0 to quit): ";
		cin >> num;
		if (num <= 0)
			break; 

		vector<Employee> pa(num);  
		Employee obj;
		for (size_t i = 0; i < num; i++)
		{
			cout << "Reading a new employee " << endl;
			cin >> obj;
			pa.push_back(obj);  
			Employee e = obj;
			pa[i] = obj;
		}

		cout << "contents of pa: " << endl;
		int size = pa.size();
		for (size_t i = 0; i < size; i++)
		{
			cout << "pa[" << i << "]: " << pa[i] << endl;
		}
		cout << endl;
	}
	return 0;
}


