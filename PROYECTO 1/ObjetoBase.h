#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class ObjetoBase
{
public:
	ObjetoBase();
	virtual ~ObjetoBase();
	virtual  ObjetoBase* clonar()const = 0;
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream&, const ObjetoBase&);
};

