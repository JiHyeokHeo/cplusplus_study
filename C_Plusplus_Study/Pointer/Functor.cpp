//#include <iostream>
//using namespace std;
//
//// �Լ� ��ü
//
//void HelloWorld()
//{
//	cout << "Hello World" << endl;
//}
//
//void HelloNumber(int number)
//{
//	cout << "Hello Number" << number << endl;
//}
//
//class Knight
//{
//public:
//	void AddHp(int addHp)
//	{
//		_hp += addHp;
//		cout << "Add Hp" << endl;
//	}
//
//private:
//	int _hp = 100;
//};
//
//class Functor
//{
//public:
//	void operator()()
//	{
//		cout << "Functor Test" << endl;
//		cout << _value << endl;
//	}
//
//	bool operator()(int num)
//	{
//		cout << "Functor Test" << endl;
//		_value += num;
//		cout << _value << endl;
//
//		return true;
//	}
//
//private:
//	int _value = 0;
//};
//
//class MoveTask
//{
//public:
//	void operator()()
//	{
//		// TODO
//		cout << "�ش���ǥ�� �÷��̾� �̵�" << endl;
//	}
//
//public:
//	int _playerId;
//	int _posX;
//	int _posY;
//};
//
//int main()
//{
//	// �Լ� ��ü (Functor) : �Լ�ó�� �����ϴ� ��ü
//	// �Լ��������� ����
//
//	// �Լ� ������ ����
//
//	void (*pfunc)(void);
//	
//	// ������ �Ѱ��� �� �����ϴ�
//	pfunc = &HelloWorld;
//	(*pfunc)();
//
//	// �Լ� ������ ����
//	// 1) �ñ״�ó�� �� ������ ����� �� ����.
//	// 2) ���¸� ���� �� ����.
//	//pfunc = &HelloNumber;
//	
//	// [�Լ�ó�� ����]�ϴ� ��ü
//	// () ������ �����ε�
//	HelloWorld();
//
//	Functor functor;
//	functor();
//	bool ret = functor(3);
//
//	// MMO���� �Լ� ä���� ����ϴ� ����
//	// Ŭ�� <-> ����
//	// ���� : Ŭ�� ������ ��Ʈ��ũ ��Ŷ�� �޾Ƽ� ó��
//	// ex) Ŭ�� : �� (5, 0) ��ǥ�� �̵�������!
//	MoveTask task;
//	task._playerId = 100;
//	task._posX = 5;
//	task._posY = 0;
//	
//	// ���߿� ���� �ɶ� �ϰ��� �����Ѵ�.
//	task();
//
//	return 0;
//}