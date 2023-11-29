#include <iostream>
using namespace std;

// ���м�

// ���м� = ĸ��ȭ
// ���� �Ǵ� ���� ����ϰ� ����ڴ�.
// ����� ����?
// 1) ���� �����ϰ� �ǵ帮�� �ȵǴ� ����
// 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ������ ���忡�� ����ϴ� ��?
// - �ڵ�/���/��
// ���� �� (������ �ǵ帮�� ū�ϳ�)
// - ����, ���� ���⼱

// public(����) protected(��ȣ) private(����)
// - public : �������׳� ����. ���� ����ϼ���~!
// - protected :  ���� �ڼյ����׸� ���
// - private : ���� ����Ҳ�! << class Car ���ο�����!

// ��� ���� ������ : ���� �������� �θ�� ������ ��� ��������?
// �θ������ �������� ������ �� ���� �ڼյ����׵� �Ȱ����� ������� ���� ����
// - public : ������ ��� -> �θ���� ���� ���� �״�� (public -> public, protected -> protected)
// - protected : ��ȣ�޴� ��� ->  �� �ڼյ����׸� �����ٲ��� (public -> protected, protected -> protected)
// - private : �������� ��� -> �������� �� ���� �ڼյ����״� �ƿ� �� �����ٲ��� (public -> private, protected -> private)

class Car
{
public: // (���) ���� ������
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey()
	{
		// ...
		RunEngine();
	}

protected:
	void DisassembleCar() {} // ���� �����Ѵ�
	void RunEngine() {} // ������ ������Ų��
	void ConnectCircuit() {} // ���⼱ ����

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���� ���⼱
};

class SuperCar : private Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
	
};

class TestSuperCar : public SuperCar
{
public:
	void Test()
	{
		DisassembleCar();
	}
};

// 'ĸ��ȭ'
// ������ �����Ϳ� �Լ��� ���������� ������� ��

class Berserker
{
public:

	int GetHp() { return _hp; }
	// ��� : ü���� 50 ���Ϸ� �������� ����Ŀ ��� �ߵ� (������)
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	void SetBerserkerMode()
	{
		cout << "�ſ� ������ !" << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	Berserker b;
	TestSuperCar c;
	


	return 0;
}