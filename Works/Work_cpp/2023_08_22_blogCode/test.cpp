#define _CRT_SECURE_NO_WARNINGS 1

template<class T, size_t N = 10>
class array
{
public:
	T& operator[](size_t index) { return _array[index]; }
	const T& operator[](size_t index)const { return _array[index]; }

	size_t size()const { return _size; }
	bool empty()const { return 0 == _size; }

private:
	T _array[N];
	size_t _size;
};

int main()
{
	array<int> arr1;
	array<int, 20> arr2;
	return 0;
}