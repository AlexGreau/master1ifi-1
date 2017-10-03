#ifndef STR_H
#define STR_H

class Str {

	char *string;

  public:
	Str();
	Str(char*);
	Str(const Str&);
	~Str();

	void print();
	void printDebug(const char*);
	char* ch();
	void concat(/*const int,*/ const char*);
	void concat2(Str);
	Str concat3(Str);
	Str concat4(Str&);

	// Operator overlaoading allows you to redefine various operators
	// Str operator+(const Str); // est� et fonctionnel
	Str operator+(Str&); // - non test�

	// Declaring the function to be a friend of the class, gives it access to protected and private members of the class without opening up access to anyone else.
	// friend Str operator+(Str, const Str); // test� et fonctionnel
	// friend Str operator+(Str&, Str&); // non test�
	friend Str operator<(Str&, Str&);


};

#endif
