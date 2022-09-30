 #include <iostream>
 #include <math.h>


class RoundPeg
{
public:
	int radius;
	//improvizaci default i hamar error er tali esi drel em dzvel a
	RoundPeg() = default;
	RoundPeg(int _radius) : radius(_radius) {};
	int getRadius() const {
		return radius;
	}

};

class  RoundHole
{
	public:
	int radius;

	RoundHole(int _radius) : radius(_radius){}
	int getRadius() const {
		return radius;
	}

	virtual bool fits(RoundPeg *peg){
		return bool(this->getRadius() >= peg->getRadius());
	} 

};


class SquarePeg 
{
	public:
	int width;
	SquarePeg(int _width) : width(_width){}

	int getWidth() const {
		return width;
	}

};


class SquarePegAdapter : public RoundPeg 
{
	SquarePeg* peg ;

	public:
	SquarePegAdapter(SquarePeg *_peg) : peg(_peg){}

	int getRadius(){

		return peg->getWidth() * (sqrt(2)/2);
	}

};