#include "list_function.hpp"
#include <vector>

void Student::add_lesson(Lesson* const lesson)
{
	auto found1 = std::find(list_lesson.begin(), list_lesson.end(),lesson);
	auto found2 = std::find(lesson -> list_student.begin(), lesson -> list_student.end(), this);
	if (found1 == list_lesson.end())
	{
		list_lesson.push_back(lesson);
	}
	if (found2 == lesson -> list_student.end())
	{
		lesson -> list_student.push_back(this);
	}
}

void Lesson::add_student(Student* const student)
{
	auto found1 = std::find(list_student.begin(), list_student.end(), student);
	auto found2 = std::find(student -> list_lesson.begin(), student -> list_lesson.end(), this);
	if (found1 == list_student.end())
	{
		list_student.push_back(student);
	}
	if (found2 == student -> list_lesson.end())
	{
		student -> list_lesson.push_back(this);
	}
}

void Lesson::print()
{
	std::cout << (*this).name << ":\n";

	for (auto i : (*this).list_student)
	{
		std::cout << (*i).name << '\n';
	}
}


void Student::print()
{
	std::cout << (*this).name << ":\n";

	for (auto i : (*this).list_lesson)
	{
		std::cout << (*i).name << '\n';
	}
}

void ex2()
{
	std::cout << "\n\nex2 start\n\n";
	Student S1("Anton");
	Student S2("Andrey");
	Student S3("Ivan");
	Student S4("Ann");

	Lesson Maths("Maths");
	Lesson Physics("Physics");
	Lesson Computer_science("Computer science");
	Lesson English("English");

	Maths.add_student(&S1);
	Maths.add_student(&S2);
	Maths.add_student(&S4);
	Physics.add_student(&S1);
	Physics.add_student(&S3);
	Computer_science.add_student(&S3);
	S1.add_lesson(&English);
	S2.add_lesson(&English);
	S4.add_lesson(&English);
	S1.add_lesson(&Computer_science);
	S1.add_lesson(&Computer_science);

	Maths.print();
	std::cout << '\n';
	Physics.print();
	std::cout << '\n';
	S1.print();
	std::cout << '\n';
	S2.print();
	std::cout << "\nex2 end\n\n";
}