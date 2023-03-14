// Figures. Methods.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<string>
#include <iostream>
#include <exception>



class Figure
{
protected:
	std::string nameOfFigure = "фигура";
	bool checkFigure = false;
	int quantityOfSides = 0;
	int haveSides = 0;
	int sideLengthA = 0;
	int sideLengthB = 0;
	int sideLengthC = 0;
	int sideLengthD = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
	int angleD = 0;
	virtual bool metodCheckFigure()
	{
		if (quantityOfSides == 0)
		{
			return true;
		}
		else
		{
			throw std::exception("ошибка создания фигуры");
			return false;
		}
	};
public:
	std::string getNameOfFigure() { return nameOfFigure; }
	int getSides() { return haveSides; }

	int getSideLengthA() { return sideLengthA; }
	int getSideLengthB() { return sideLengthB; }
	int getSideLengthC() { return sideLengthC; }
	int getSideLengthD() { return sideLengthD; }

	int getAngleA() { return angleA; }
	int getAngleB() { return angleB; }
	int getAngleC() { return angleC; }
	int getAngleD() { return angleD; }

	virtual void printFigure() //Виртуальный метод печати и проверка правильности фигуры
	{
		std::cout << std::endl;
		std::cout << nameOfFigure << ":" << std::endl;
		if (metodCheckFigure())
		{
			std::cout << "Правильная" << std::endl;
		}
		else { std::cout << "Неправильная" << std::endl; }

		std::cout << "Количество сторон: " << quantityOfSides << std::endl;
	}
};
class Triangle : public Figure
{
protected:
	bool metodCheckFigure() override //Переписанный метод проверки на сумма всех углов треуг == 180
	{
		if ((angleA + angleB + angleC) == 180)
		{
			return true;
		}
		else
		{
			throw std::exception("неверная сумма углов");
			return false;
		}
	};


public:
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
	{
		nameOfFigure = "Треугольник";
		this->sideLengthA = sideLengthA;
		this->sideLengthB = sideLengthB;
		this->sideLengthC = sideLengthC;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		quantityOfSides = 3;
		checkFigure = metodCheckFigure();
	}
	void printFigure() override //Переписанный метод печати с вызовом базового метода печати
	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << getSideLengthA() << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << std::endl;
	}

};
class rightTriangle : public Triangle
{
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (angleC == 90))
		{
			return true;
		}
		else
		{
			throw std::exception("нет 90");
			return false;
		};
	};

public:
	rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Прямоугольный треугольник";
	};
};
class isoscelesTriangle : public Triangle
{
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (sideLengthA == sideLengthC && angleA == angleC))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	isoscelesTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC) : Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Равнобедренный треугольник";
	};
};

class equilateralTriangle : public Triangle
{
private:
	bool CheckEquilateralTriangle()
	{
		if ((sideLengthA == sideLengthB && sideLengthB == sideLengthC) && ((angleA == 60) && (angleA = 60) && (angleC = 60)))
		{
			return true;
		}
		else
		{
			throw std::exception("не равны сторорны или углы");
			return false;
		};
	}

public:
	equilateralTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Равносторонний треугольник";
	};
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (CheckEquilateralTriangle()))
		{
			return true;
		}
		else
		{
			return false;
		};
	};



};

class Quadrilateral : public Figure
{
protected:
	virtual bool metodCheckFigure()
	{
		if ((angleA + angleB + angleC + angleD) == 360)
		{
			return true;
		}
		else
		{
			throw std::exception(" сумма углов не равна 360");
			return false;
		}
	};


	bool metodCheckSideLengthACiBD()
	{
		if (sideLengthA == sideLengthC && sideLengthB == sideLengthD)
		{
			return true;
		}
		else
		{
			throw std::exception("стороны не равны попарно");
			return false;
		}
	};

	bool metodCheckSideLengthACBD()
	{
		if (sideLengthA == sideLengthB && sideLengthB == sideLengthC && sideLengthC == sideLengthD)
		{
			return true;
		}
		else
		{
			throw std::exception("стороны не одинаковые");
			return false;
		}
	};


	bool metodCheckAngleabcd90()
	{
		if (angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90)
		{
			return true;
		}
		else
		{
			throw std::exception(" углы не 90 ");
			return false;
		}
	};

	bool metodCheckAngleACiBD()
	{
		if (angleA == angleC && angleB == angleD)
		{
			return true;
		}
		else
		{
			throw std::exception("сторны не равны попарно");
			return false;
		}
	};

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		nameOfFigure = "Четырехугольник";

		quantityOfSides = 4;
		this->sideLengthA = sideLengthA;
		this->sideLengthB = sideLengthB;
		this->sideLengthC = sideLengthC;
		this->sideLengthD = sideLengthD;

		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		this->angleD = angleD;
	}

	void printFigure() override
	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << getSideLengthA() << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << ", d = " << getSideLengthD() << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << ", D = " << getAngleD() << std::endl;
	}

};

class Rectangle : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Rectangle(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	Square(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Parallelogram(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Rhomb(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Ромб";
	}
};
void printFigure(Figure& figure)
{


	figure.printFigure();
	/*std::cout << std::endl;
	std::cout << figure.getNameOfFigure() << ":" << std::endl;

	std::cout << "Стороны:";
	std::cout << " a = " << figure.getSideLengthA() << ", b = " << figure.getSideLengthB() << ", с = " << figure.getSideLengthC();
	if (figure.getSides()==3)
	{
		std::cout << ", d = " << figure.getSideLengthD() << std::endl;
	}
	else { std::cout << std::endl; }

	std::cout << "Углы:";
	std::cout << " А = " << figure.getAngleA() << ", В = " << figure.getAngleB() << ", С = " << figure.getAngleC();
	if (figure.getSides()==4) { std::cout << ", D = " << figure.getAngleD() << std::endl; }
	else { std::cout << std::endl; }*/
}

//
//Parent* par_child = &child;
//par_child->method(); // Потомок
//Родитель
// 
// 
// 
//int function(Figure& figure)
//{
//	if (! figure->metodCheckFigure())
//
//
//}



int main()
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
	system("chcp 1251");
	try
	{
		Figure Figure1;
		Figure1.printFigure();

		Triangle Triangle1(10, 20, 30, 50, 60, 70);
		printFigure(Triangle1);

		rightTriangle rightTriangle1(10, 20, 30, 50, 60, 70);
		printFigure(rightTriangle1);

		rightTriangle rightTriangle2(10, 20, 30, 50, 60, 90);
		printFigure(rightTriangle2);

		isoscelesTriangle isoscelesTriangle1(10, 20, 10, 50, 60, 90);
		printFigure(isoscelesTriangle1);

		equilateralTriangle equilateralTriangle1(30, 30, 30, 60, 60, 60);
		printFigure(equilateralTriangle1);

		Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
		printFigure(Quadrilateral1);

		Rectangle Rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
		printFigure(Rectangle1);

		Square Square1(20, 20, 20, 20, 90, 90, 90, 90);
		printFigure(Square1);

		Parallelogram Parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
		printFigure(Parallelogram1);

		Rhomb Rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
		printFigure(Rhomb1);
	}
	catch (const std::exception& error)
	{
		std::cout << std::endl << error.what() << std::endl;
	}
}

