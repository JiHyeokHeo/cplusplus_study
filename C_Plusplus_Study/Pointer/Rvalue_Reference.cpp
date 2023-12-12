#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>

// 오른쪽(rvalue) 참조와 std::move

class Pet
{

};

class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}
	// 복사 생성자
	Knight(const Knight& knight)
	{
		cout << "Knight(const Knight& knight)" << endl;
	}

	// 이동 생성자
	Knight(Knight&& knight)
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// 복사 대입 연산자
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;

		_hp = knight._hp;

		if(knight._pet)
			_pet = new Pet(*knight._pet);
		
	}

	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(Knight&&)" << endl;

		// 얕은 복사
		_hp = knight._hp;
		_pet = knight._pet;

		knight._pet = nullptr;
	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) {} // 복사 생성자 호출
void TestKnight_LValueRef(Knight& knight) {} // 복사 X
void TestKnight_ConstLValueRef(const Knight& knight) {} // Read ONLY
void TestKnight_ConstRValueRef(Knight&& knight) { } // 이동 대상

int main()
{
	// 왼값(lvalue) vs 오른값(rvalue)
	// - lvalue : 단일식을 넘어서 계속 지속되는 개체
	// - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)

	int a = 3;

	Knight k1;

	TestKnight_Copy(k1);

	TestKnight_LValueRef(k1);
	//TestKnight_LValueRef(Knight());

	TestKnight_ConstLValueRef(Knight());
	
	TestKnight_ConstRValueRef(Knight());

	TestKnight_ConstRValueRef(static_cast<Knight&&>(k1));

	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// 원본은 날려도 된다 << 는 Hint를 주는 쪽에 가깝다!
	Knight k3;
	//k3 = static_cast<Knight&&>(k2);

	k3 = std::move(k2); // 오른쪽 참조로 캐스팅
	// std::move의 본래 이름 후보 중 하나가 rvalue_cast

	std::unique_ptr<Knight> uptr = std::make_unique<Knight>();
	std::unique_ptr<Knight> uptr2 = std::move(uptr);

	return 0;
}