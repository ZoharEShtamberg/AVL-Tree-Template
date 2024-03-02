#ifndef STUPIDARR_H
#define STUPIDARR_H

template<typename T>
class StupidArr{
public:
	StupidArr(int size) : size(size), arr(new T[size]) {}
	~StupidArr() {
		delete[] arr;
	}
	T* arr;
	int size;

	T& operator[](int index) {
		assert(index >= 0 && index < size);
		return arr[index];
	}
	
};

#endif // !STUPIDARR_H