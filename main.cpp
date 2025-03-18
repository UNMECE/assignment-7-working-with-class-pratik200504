#include<iostream>
#include<cmath>
using namespace std;

class Electric_Field
{
	private:
		double E_x;
		double E_y;
		double E_z;
	public:
		Electric_field() //default constructor
		{
			E_x=0.0;
			E_y=0.0;
			E_z=0.0;
		}

		Electric_Field(double Ex, double Ey, double Ez)
		{
			E_x=Ex;
			E_y=Ey;
			E_z=Ez;
		}

		~Electric_Field()//Destructor
		{
		//no dynamic memory to delete now
		}

		void setfield(double Ex, double Ey, double Ez)
		{
			E_x=Ex;
			E_y=Ey;
			E_z=Ez;
		}

		double getX() const {return E_x;}
		double getY() const {return E_y;}
		double getZ() const {return E_z;}

		double calculateMagnitude()
		{
			return sqrt(E_x*E_x+E_y*E_y+E_z*E_z);
		}

		double calculteInnerProduct(Electric_field &other)
		{
			return E_x *other.getX()+E_y*other.getY()+E_z*other.getZ();
		}

		void display()
		{
			cout <<"Electric Field Components: ("<<E_x<< ", "<<E_y<<","<<E_z<<")"<<endl;
		}
	};

	class Magnetic field
	{
	private:
		double B_x;
		double B_y;
		double B_z;
	public:
		Magnetic field() {}//default constructor
		{
			B_x=0.0;
			B_y=0.0;
			B_z=0.0;
		}

		Magnetic_Field(double Bx, double By, double Bz)//parameterized constructor
		{
			B_x=Bx;
			B_y=By;
			B_z=Bz;
		}

		~Magnetic_Field()//destructor
		{
		//NO Dynamic memory to delete now
		}

		void setfield(double Bx, double By, double Bz)
		{
			B_x=Bx;
			B_y=By;
			B_z=Bz;
		}

		double getX() const {return B_x;}
		double getY() const {return B_y;}
		double getZ() const {return B_z;}

		double calculateMagnitude()
		{
			return sqrt(B_x*B_x+B_y*B_y+B_z*B_z);
		}

		void calculateUnitvector()
		{
			double mag=calculateMagnitude();
			cout<<"Unit vector: ("<<B_x/mag<<", " mag << ", " <<B_y/mag<<", "<<B_z/mag<<")" <<endl;
		}

		void display()
		{
			cout<<"Magnetic Field Components: ("<<B_x<<", " <<B_y<< ", "<<B_z<<")" <<endl;
		}
	};
	
	int main()
	{
		Electric_Field E_default;
		Electric_Field E_components(1e5, 10.9, 1.7e2);
		E_default.setField(2.0, 3.0, 4.0);

		Magnetic_Field B_default;
		Magnetic_Field B_components(5.0, 6.0, 7.0);
		B_default.setField(1.0, 2.0, 3.0);

		E_default.display();
		cout << "Electric Field Magnitude (Default): " << E_default.calculateMagnitude() << endl;

		E_components.display();
		cout << "Electric Field Magnitude (Components): " << E_components.calculateMagnitude() << endl;

		B_default.display();
		cout << "Electric Field Magnitude (Default): " << E_default.calculateMagnitude() << endl;

		E_components.display();
		cout << "Electric Field Magnitude (Components): " << E_components.calculateMagnitude() << endl;

		cout << "Magnetic Field Magnitude (Default): " << B_default.calculateMagnitude() << endl;

		B_components.display();
		cout << "Magnetic Field Magnitude (Components): " << B_components.calculateMagnitude() << endl;

		cout << "Inner Product of Electric Fields: " << E_default.calculateInnerProduct(E_components) << endl;

		cout << "Magnetic Field Unit Vector (Components): ";
		B_components.calculateUnitVector();

				return 0;
	}
