#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>


struct Spaseship;
struct Lesson;
struct Student;
enum class Month;

struct Lesson
{
	std::string name;
	std::vector <const Student*> list_student;
	Lesson(std::string name) : name(name)
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
	std::string name;
	std::vector <const Lesson*> list_lesson;
	Student(std::string name) : name(name)
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
enum class Month
{
	January,
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

<<<<<<< HEAD
<<<<<<< HEAD
bool leap_year(int year);
unsigned days_in_month(int month, int year);
=======
=======
>>>>>>> parent of 77b0140 (seminar 4 var3)
bool leap_year(int year = 2000);
unsigned days_in_month(Month month, int year);
>>>>>>> parent of 77b0140 (seminar 4 var3)

void ex1();
void ex2();
void ex3();
void ex4();