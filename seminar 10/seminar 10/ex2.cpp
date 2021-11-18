#include "Header.hpp"


template <typename T, typename ... Types>
T* indicator(Types && ... args)
{
	return new T(args...);
}

void ex2()
{
	Gm::Vector p1(0, 0), p2(3, 0), p3(5, 4), p4(3, 6), p5(0, 6);
	Gm::Close_Shape* pol = indicator <Gm::SPoligon>(std::vector{ p1,p2,p3,p4,p5 });
	Gm::Close_Shape* cy = indicator <Gm::Сircle>(std::vector{ p1, p2 });
	Gm::Close_Shape* tr = indicator <Gm::Triangle>(std::vector{ p1, p2, p3 });
	std::vector<Gm::Close_Shape*> figures = { pol, cy, tr};
	for (auto i : figures)
	{
		std::cout << *i;
		delete i;
	}
	figures.clear();
}