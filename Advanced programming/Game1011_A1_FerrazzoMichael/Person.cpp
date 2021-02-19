#include <iostream>
#include  <string>
#include "Person.h"

using namespace std;

Person::Person()
{
	SetName("");
	SetAge(0);
}

Person::Person(string name, int age)
{
	SetName(name);
	SetAge(age);
}

void Person::SetName(string name)
{
	this->name = name;
}

string Person::GetName()
{
	return name;
}

void Person::SetAge(int age)
{
	this->age = age;
}

int Person::GetAge()
{
	return age;
}

Student::Student(cName college, pName program, int semester)
{
	SetCollege(college);
	SetProgram(program);
	SetSemester(semester);
}

void Student::SetCollege(cName col)
{
	college = col;
}

cName Student::GetCollege()
{
	return college;
}

void Student::SetProgram(pName prog)
{
	program = prog;
}

pName Student::GetProgram()
{
	return program;
}


void Student::SetSemester(int sem)
{
	semester = sem;
}

int Student::GetSemester()
{
	return semester;
}


GamingStudent::GamingStudent(dName device, int hours, int age, cName college, pName program, int semester) : Student(college, program, semester)
{
	SetAge(age);
}

void GamingStudent::SetDevice(dName dev)
{
	device = dev;
}

dName GamingStudent::GetDevice()
{
	return device;
}

void GamingStudent::SetHours(int hours)
{
	this->hours = hours;
}

int GamingStudent::GetHours()
{
	return hours;
}

NonGamingStudent::NonGamingStudent(sName service, int hours, int age, cName college, pName program, int semester) : Student(college, program, semester)
{
	SetAge(age);
}

void NonGamingStudent::SetService(sName service)
{
	this->service = service;
}

sName NonGamingStudent::GetService()
{
	return service;
}

void NonGamingStudent::SetHours(int hours)
{
	this->hours = hours;
}

int NonGamingStudent::GetHours()
{
	return hours;
}

