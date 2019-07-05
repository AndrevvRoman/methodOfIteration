#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

const int ResX = 800, ResY = 600;
 double n = 25;//плотность кривой;
 double h = 25;//высота кривой
const double d = 0.05; //плотность точек

void draw_coord(RenderWindow &window)
{
	RectangleShape x, y;
	x.setSize(Vector2f(1000, 1.5));
	y.setSize(Vector2f(1000, 1.5));
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
	return pow(x,2)+ 2*x - 3;
}

double r_funcX(double x)
{
	return (pow(x, 2) - 3) / (-2);
}

void draw_point(RenderWindow &window,double x)
{
	CircleShape circle;
	circle.setRadius(0.05*n);
	circle.setFillColor(Color::Red);
	circle.setPosition(Vector2f(centerX(x*n), centerY(-h*0)));
	window.draw(circle);
}

void draw_line(RenderWindow &window,double x1 ,double x2)
{
	VertexArray line(Lines, 2);
	line[0].color = Color::Red;
	line[1].color = Color::Red;
	cout << centerX(x1*n) << " " << -h * centerY(-x2) << endl;
	cout << centerX(x2*n) << " " << -h*centerY(x2) << endl;
	for (int i = 0; i < 4; i++)
	{
		line[0].position = Vector2f(centerX(i*n), centerY(-h * funcX(i)));
		line[1].position = Vector2f(centerX(-n*i), centerY(-h * funcX(-i)));
		window.draw(line);
		x1 = x1 - 1;
		x2 = x2 - 1;
	}

}

void draw_graph(RenderWindow &window)
{
	int sizeOfArray = 2000;
	VertexArray point(LinesStrip, sizeOfArray);
	double x = -7.0;
	cout << "n= "<< n << " h=" << h << "d=" << d << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		point[i].position = Vector2f(centerX(x*n),  centerY(- h * funcX(x)));
		//cout << centerX(x*n) << " " << -h * centerY(-x) << endl;
		int clr = (i < 256 ? i : i % 255);
		point[i].color = Color::White;
		x += d;
		if (i % 100 == 0) draw_point(window, x);
	}
	window.draw(point);
		//draw_line(window, 5, -5);
	x = -7.0;
	cout << "n= " << n << " h=" << h << "d=" << d << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		point[i].position = Vector2f(centerX(x*n), centerY(-h * r_funcX(x)));
		//cout << centerX(x*n) << " " << -h * centerY(-x) << endl;
		int clr = (i < 256 ? i : i % 255);
		point[i].color = Color::Cyan;
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
		cin >> n;
		h = n;
	}
	return 0;
}