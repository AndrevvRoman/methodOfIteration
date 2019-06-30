#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

const int ResX = 800, ResY = 600;
double scale = 1;

void draw_coord(RenderWindow &window)
{
	RectangleShape x, y;
	x.setSize(Vector2f(1000, 3));
	y.setSize(Vector2f(1000, 3));
	x.setFillColor(Color::Yellow);
	y.setFillColor(Color::Cyan);

	x.setPosition(Vector2f(0, ResY / 2));
	y.setRotation(90);
	y.setPosition(Vector2f(ResX / 2, 0));
	window.draw(x);
	window.draw(y);

}

double centerX(double x)
{
	return x + ResX / 2;
}

double centerY(double y)
{
	return y + ResY / 2;
}

double funcX(double x)
{
	return 3*pow(x,5) + 29*pow(x,2) + x - 32 ;
}

void draw_graph(RenderWindow &window)
{
	int sizeOfArray = 2000;
	VertexArray point(Points, sizeOfArray);
	double x = 0.0;
	double n = 1;//плотность кривой;
	double h = 10;//высота кривой
	double d = 0.005; //плотность точек
	for (int i = 0; i < sizeOfArray; i++)
	{
		point[i].position = Vector2f(centerX(i*n),  centerY(- h * funcX(x)));
		int clr = (i < 256 ? i : i % 255);
		point[i].color = Color::White;
		x += d;
	}
	window.draw(point);
}

int main()
{
	RenderWindow window(VideoMode(ResX, ResY), "Method");
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		draw_coord(window);
		draw_graph(window);
		window.display();
	//	cin >> scale;
	}
	return 0;
}