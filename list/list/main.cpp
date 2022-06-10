#include <iostream>

using namespace std;

struct list
{
	int Value;
	list* Back;

};

void AddObject(list* _next, const int& _value);

void Output(list* _next);

// ** insert �Լ� ��������
// ** �߰��� �����ؾߵȴٸ� �迭�� ����ϰų� for�� ���߿� �����ֵ� �ص� ������(erase�� ���� ��İ� �����ϰ�)


int main(void)
{
	list* Numberlist = new list;
	Numberlist->Value = 0;
	Numberlist->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		// ** 10ȸ �߰�
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
