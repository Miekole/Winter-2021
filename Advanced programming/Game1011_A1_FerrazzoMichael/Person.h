#pragma once
#include <iostream>
#include  <string>
using namespace std;

enum cName { None, George_Brown, Sheridan, Durham, Seneca, Georgian };
enum pName { pNone, Engineering, Psychology, Business, History, Education};
enum dName { dNone, Computer, Xbox, Playstation, Nintendo, Phone };
enum sName { sNone, Youtube, Netflix, Hulu, Prime_Video, Twitch };

class Person
{
private:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);
	void SetName(string name);
	string GetName();
	void SetAge(int age);
	int GetAge();
};

class Student : public Person
{
protected:
	cName college;
	pName program;
	int semester;
public:
	Student(cName college, pName program, int semester);
	void SetCollege(cName col);
	cName GetCollege();
	void SetProgram(pName prog);
	pName GetProgram();
	void SetSemester(int sem);
	int GetSemester();
};

class GamingStudent : public Student
{
private:
	dName device;
	int hours;
public:
	GamingStudent(dName device, int hours, int age, cName college, pName program, int semester);
	void SetDevice(dName dev);
	dName GetDevice();
	void SetHours(int hours);
	int GetHours();
};

class NonGamingStudent : public Student
{
private:
	sName service;
	int hours;
public:
	NonGamingStudent(sName service, int hours, int age, cName college, pName program, int semester);
	void SetService(sName service);
	sName GetService();
	void SetHours(int hours);
	int GetHours();
};
