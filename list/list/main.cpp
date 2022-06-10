#include <iostream>

using namespace std;

struct list
{
	int Value;
	list* Back;

};

void AddObject(list* _next, const int& _value);

void Output(list* _next);

// ** insert 함수 만들어오기
// ** 중간에 삽입해야된다면 배열을 사용하거나 for문 도중에 끼워넣듯 해도 괜찮다(erase는 뒤의 방식과 동일하게)


int main(void)
{
	list* Numberlist = new list;
	Numberlist->Value = 0;
	Numberlist->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		// ** 10회 추가
		AddObject(Numberlist, i * 10 + 10);
	}

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

void Output(list* _next)
{
	cout << _next->Value << endl;
	if (_next->Back == nullptr)
		Output(_next->Back);
}
