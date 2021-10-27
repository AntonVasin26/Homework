#include "geometry.hpp"

int main()
{
	Gm::Vector p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 2), p5(0, -1), p6(3, 4), p7(-1, 0), p8(0, -2);
	std::vector <Gm::Vector> v1({ p1, p2, p3 ,p4 });

	Gm::Close_Shape* pol = new Gm::SPoligon(v1);
	Gm::Close_Shape* cy = new Gm::Ñircle({p1, p6 });
	Gm::Close_Shape* tr = new Gm::Triangle({ p1, p2, p3 });
	Gm::Close_Shape* ell = new Gm::Ellipse({ p2, p4, p7, p8 });

	Gm::Vector p9(2, 4), p10(7, 4), p11(5, 0), p12(0, 0);
	Gm::Close_Shape* rb = new Gm::Rhomb({ p2, p4, p7, p8 });
	Gm::Close_Shape* pl = new Gm::Parallelogram({ p9, p10, p11, p12 });
	std::vector<Gm::Close_Shape*> figures = { pol, cy, tr, ell, rb, pl };
	for (auto i : figures)
	{
		std::cout << *i;
		delete i;
	}
	figures.clear();
}