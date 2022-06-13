// ** list v0.2
#include <iostream>

using namespace std;

struct list
{
	int Value;
	list* Back;

};

void AddObject(list* _next, const int& _value);
void Insert(list* _next, int _where, const int& _value);
void erase(list* _next, int _where);

void Output(const list* _next);
list* front = nullptr;



int main(void)
{
	list* Numberlist = new list;
	Numberlist->Value = 0;
	Numberlist->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		// ** 10È¸ Ãß°¡
		AddObject(Numberlist, i * 10 + 10);
	}

	Insert(Numberlist, 2, 15);
	Output(Numberlist);

	erase(Numberlist, 2);
	Output(Numberlist);

	return 0;
}

void AddObject(list* _next, const int& _value)
{
	if (_next->Back == nullptr)
	{
		list* Temp = new list;
		Temp->Value = _value;
		Temp->Back = nullptr;

		_next->Back = Temp;
	}
	else
	{
		AddObject(_next->Back, _value);
	}
}

void Insert(list* _next, int _where, const int& _value)
{
	if (_where == 0)
	{
		list* Temp = new list;
		Temp->Value = _value;
		Temp->Back = _next->Back;

		_next->Back = Temp;
	}
	else
	{
		Insert(_next->Back, _where - 1, _value);
	}
}


void erase(list* _next, int _where)
{
	if (_where == -1)
	{
		/*
		list* Temp = _next->Back;
		_next->Back = _next->Back->Back;
		*/

		list* Temp = _next;
		front->Back = _next->Back;

		delete _next;
		Temp = nullptr;
	}
	else
	{
		front = _next;
		erase(_next->Back, _where - 1);
	}
}

void Output(const list* _next)
{
	cout << _next->Value << endl;
	if (_next->Back != nullptr)
		Output(_next->Back);
}
