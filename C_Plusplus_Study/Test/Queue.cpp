//#include <iostream>
//#include <vector>
//#include <list>
//#include <deque>
//#include <queue>
//
//using namespace std;
//
//// Queue FIFO( 선입선출 )
//
//// front << [1][2][3][4] << rear(back) 밀어넣음
//// 대기열
//
//// 어레이 큐 // 순환구조
//// [front / back][][][][][][][][][][][][][][][][][][][][][][][]
//template <typename T>
//class ArrayQueue
//{
//public:
//    ArrayQueue()
//    {
//        _container.resize(100);
//    }
//
//    void push(const T& value)
//    {
//        // TODO : 다 찼는지 체크
//        if (_size == _container.size())
//        {
//            // 증설 작업
//            int newSize = max(1, _size * 2);
//            vector<T> newData;
//            newData.resize(newSize);
//
//            for (int i = 0; i < _size; i++)
//            {
//                int index = (_front + i) % _container.size();
//                newData[i] = _container[index];
//            }
//
//            _container.swap(newData);
//            _front = 0;
//            _back = _size;
//        }
//        
//
//        _container[_back] = value;
//        _back = (_back + 1) % _container.size();
//        _size++;
//    }
//
//    void pop()
//    {
//        _front = (_front + 1) % _container.size();
//        _size--;
//    }
//
//    T& front()
//    {
//        return _container[_front];
//    }
//
//    bool empty() { return _size == 0; }
//    int size() { return _size; }
//
//private:
//    vector<T> _container;
//
//    int _front = 0;
//    int _back = 0;
//    int _size = 0;
//};
//
//// 리스트 큐
//template <typename T>
//class ListQueue
//{
//public:
//    void push(const T& value)
//    {
//        _container.push_back(value);
//    }
//
//    void pop()
//    {
//        _container.pop_front();
//    }
//
//    T& front()
//    {
//        return _container.front();
//    }
//
//    bool empty() { return _container.empty(); }
//    int size() { return _container.size(); }
//
//private:
//    deque<T> _container;
//};
//
//int main()
//{
//    queue   <int>a;
//    ArrayQueue<int> q;
//    
//    for (int i = 0; i < 100; i++)
//        q.push(i);
//    
//    
//    while (q.empty() == false)
//    {
//        int value = q.front();
//        q.pop();
//        cout << value << endl;
//    }
//
//    int size = q.size();
//
//    return 0;
//}