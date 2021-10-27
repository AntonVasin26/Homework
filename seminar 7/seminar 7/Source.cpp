#include "geometry.hpp"

int main()
{
	Gm::Vector p1(0, 0), p2(3, 0), p3(5, 4), p4(3, 6), p5(0, 6);
	Gm::Close_Shape* pol = new Gm::SPoligon({ p1,p2,p3,p4,p5 });
	Gm::Close_Shape* cy = new Gm::Ñircle({ p1, p2 });
	Gm::Close_Shape* tr = new Gm::Triangle({ p1, p2, p3 });
	Gm::Vector p6(2, 0), p7(0, 4), p8(-2, 0), p9(0, -4);
	Gm::Close_Shape* ell = new Gm::Ellipse({ p6, p7, p8, p9 });
	Gm::Close_Shape* rb = new Gm::Rhomb({ p6,p7,p8,p9 });
	Gm::Vector p10(0, 0), p11(2, 3), p12(7, 3), p13(0, 5);
	Gm::Close_Shape* pl = new Gm::Parallelogram({ p10, p11, p12, p13 });
	std::vector<Gm::Close_Shape*> figures = { pol, cy, tr, ell, rb, pl };
	for (auto i : figures)
	{
		std::cout << *i;
		delete i;
	}
	figures.clear();
}