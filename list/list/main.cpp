// ** list v0.3
#include <iostream>

using namespace std;

struct list
{
	list* Front;
	int Value;
	list* Back;

};

void AddObject(list* _Current, const int& _value);
void DelObjectB(list* _Current);

void Insert(list* _Current, int _where, const int& _value);
void erase(list* _Current, int _where);

void Output(const list* _Current);

list* End = nullptr;

int main(void)
{
	list* Numberlist = new list;

	Numberlist->Front = nullptr;
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

	DelObjectB(Numberlist);
	Output(Numberlist);

	return 0;
}

void AddObject(list* _Current, const int& _value)
{
	if (_Current->Back == nullptr)
	{
		list* Temp = new list;

		Temp->Front = _Current;
		Temp->Value = _value;
		Temp->Back = nullptr;

		_Current->Back = Temp;
	}
	else
	{
		AddObject(_Current->Back, _value);
	}
}

void DelObjectB(list* _Current)
{
	if (_Current->Back == nullptr)
	{
		End = _Current->Front;

		_Current->Front->Back = nullptr;
		delete _Current;
		_Current = nullptr;
	}
	else
	{
		DelObjectB(_Current->Back);
	}
}

void Insert(list* _Current, int _where, const int& _value)
{
	if (_where == 0)
	{
		list* Temp = new list;

		Temp->Front = _Current;
		Temp->Value = _value;
		Temp->Back = _Current->Back;

		_Current->Back = Temp;
	}
	else
	{
		Insert(_Current->Back, _where - 1, _value);
	}
}


void erase(list* _Current, int _where)
{
	if (_where == -1)
	{
		list* Temp = _Current;

		Temp->Back->Front = _Current->Front;
		Temp->Front->Back = _Current->Back;

		delete _Current;
		_Current = nullptr;
	}
	else
	{
		erase(_Current->Back, _where - 1);
	}
}

void Output(const list* _Current)
{
	cout << _Current->Value << endl;
	if (_Current->Back != nullptr)
		Output(_Current->Back);
}
