//Aseel Khaled Al-Salmi 
#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

class Employee: public Person
{
public:
	Employee();
	virtual ~Employee();
	Employee(const Employee& e);	
	Employee& operator=(const Employee& e); 
	Employee(const string& name_i, int age_i, 
		const string& job_i, int experience_i, int salary_i);

	friend ostream& operator<<(ostream& os, const Employee& e);
	friend istream& operator>>(istream& os, Employee& e);

	static int get_count();
	static void set_count(int count_i);

	int get_experience() const; 
	const string get_job() const; 
	int get_salary () const;

	void set_experience(int experience_i);
	void set_job(const string& job_i);
	void set_salary(int salary_i);

	virtual void set(const string& job_i, int experience_i, int salary_i);
	virtual void set(const string& name_i, int age_i,
	const string& job_i, int experience_i, int salary_i);
	virtual void set(const Employee& e);

	virtual void print(ostream& os) const;
	virtual void read();

private:
	static int count; 
	string job;
	int salary; 
	int experience;
	


};


