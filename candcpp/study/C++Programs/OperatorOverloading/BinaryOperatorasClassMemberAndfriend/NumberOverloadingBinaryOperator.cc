
/***************************************
Binary operator overloading for numbers
***************************************/

class X
{
	int i;
	public:
	X():i(0)
	{}

	X(int a):i(a)
	{}

	X& operator+(const X &obj)
	{
		if(this != &obj)
		{
			//this->i = this->i + obj.i; // object x gets affected
			X *temp;
			temp->i = this->i+obj.i; //object x remains the same
			return *temp; //Should be within the block, or else goes out of scope
		}
		//return *this;
	}

	void display()
	{
		cout<<i<<endl;
	}
};

int main()
{
	X x(2),y(4),z;
        z=x+y;
	x.display();
	y.display();
	z.display();
	return 0;
}

