#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>


struct Spaseship;
struct Lesson;
struct Student;
enum Month;

struct Lesson
{
	const std::string name;
	std::vector <const Student*> list_student;
	Lesson(const std::string name) : name(name)
	{
		//std::cout << "\ncreate lesson: " << name << '\n';
	}

	void add_student(Student* const student);
	void print();

	~Lesson()
	{
		//std::cout << "\ndelete lesson: " << name << '\n';
	}
};
struct Student
{
	const std::string name;
	std::vector <const Lesson*> list_lesson;
	Student(const std::string name) : name(name)
	{
		//std::cout << "\ncreate student: " << name << '\n';
	}
	void add_lesson(Lesson* const lesson);
	void print();

	~Student()
	{
		//std::cout << "\ndelete student: " << name << '\n';
	}
};
enum Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	Jule,
	August,
	September,
	October,
	November,
	December
};

bool leap_year(int year);
unsigned days_in_month(Month month, int year);

void ex1();
void ex2();
void ex3();
void ex4();