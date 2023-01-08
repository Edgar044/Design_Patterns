#include <iostream>
#include <vector>

#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP


class IGraphic {

public:

	IGraphic();
	virtual void move(int x, int y) = 0;
	virtual void drow() = 0;
	}
	~IGraphic();



};


class Dot : public IGraphic
{
public:
	Dot(int x, int y) : _x(x), _y(y) {}
	void move(int x, int y) override {
		this->_x += x;
		this->_y += y;
	}
	void drow() override {
		std::cout << "drow\n";
	}

	~Dot();
private:
	int _x;
	int _y;

};

class Circle : public Dot
{
	Circle(int x, int y, int radius) : _x(x), _y(y), _radius(radius) {}
	void drow() override {
		std::cout << "drow circle\n";
	}
	~Circle(){}

public:

	int _radius;
};
 
class CompoundGraphic :public IGraphic
{
public:

	std::vector<IGraphic> graphics;
	
	void add(IGraphic newItem) {
		graphics.push_back(newItem)
	}
	
	void remove(IGraphic newItem) {
		std::cout << "remove item\n";
		//graphics.push_back(newItem)
			
	}

	void drow() {
		std::cout << "drow compound graphics\n";
	}

};



class ImigeEditor  
{
	CompoundGraphic* all;
	 


public: 
	void load() {
		all = new CompoundGraphic();
		all->add(new Dot(1, 2));
		all->add(new Circle(2, 3, 5));

	}


	void groupSelected(std::vector<IGraphic> Graphics) {
		
		CompoundGraphic* group;
		group = new CompoundGraphic();
		
	/*	for (const ComponentGraphic* c : Graphics) {
			if (c == Graphics.back()) {
				result += c.
			}
		}



		while () {
			
			group->add();
		}


		*/



	}



};


























#endif // !COMPOSITE_HPP
