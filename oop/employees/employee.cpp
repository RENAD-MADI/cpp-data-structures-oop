//Aseel Khaled Al-Salmi 
#include <iostream>
#include <limits>
#include "employee.h"

using namespace std;
int Employee::count = 0;

Employee::Employee()
{
	count++;
	Person();
	set("", 0, 0);
}

Employee::~Employee()
{
	count--;
}

Employee::Employee(const Employee& obj)
{
	count++;
	set(obj);
}

Employee& Employee::operator=(const Employee& obj)
{
	if (this == &obj)
		return (*this);

	set(obj);
	return *this;	
}

Employee::Employee(const string& name_i, int age_i,
	const string&  job_i, int experience_i, int salary_i)
{
	count++;
	set(name_i, age_i, job_i, experience_i, salary_i);
}

ostream& operator<<(ostream& os, const Employee& obj)
{
	os << Person(obj) <<
		",  job = " << obj.job << ", experience = " << obj.experience << ",  salary = " << obj.salary;
	return os;
}

istream& operator>>(istream& is, Employee& obj)
{
	Person p;
	is >> p;
	obj.set_name(p.get_name());
	obj.set_age(p.get_age());
	cout << "Enter job: ";
	is.ignore(); 
	getline(cin, obj.job);
	cout << "Enter salary: ";
	is >> obj.salary;
	cout << "Enter experience: ";
	is >> obj.experience;


	return is;
}

int Employee::get_count()
{
	return count;
}

void Employee::set_count(int count_i)
{
	count = count_i;
}

int Employee::get_experience() const
{
	return experience;
}

const string Employee::get_job() const
{
	return  job;
}

int Employee::get_salary() const
{
	return salary;
}

void Employee::set_job(const string&  job_i)
{
	 job =  job_i;
}

void Employee::set_experience(int experience_i)
{
	experience = experience_i;
}
void Employee::set_salary (int salary_i)
{
	salary = salary_i;
}

void Employee::set(const string&  job_i, int experience_i, int salary_i)
{
	set_job( job_i);
	set_experience(experience_i);
	set_salary(salary_i);
}

void Employee::set(const string& name_i, int age_i,
	const string&  job_i, int experience_i, int salary_i)
{
	Person::set(name_i, age_i);
	set_job( job_i);
	set_experience(experience_i);
set_salary(salary_i);

}

void Employee::set(const Employee& obj)
{
	Person::set(obj.get_name(), obj.get_age());
	set(obj.job, obj.experience, obj.salary);
}

void Employee::print(ostream& os) const
{
	os << *this << endl;
}

void Employee::read()
{
	cin >> *this;
}



