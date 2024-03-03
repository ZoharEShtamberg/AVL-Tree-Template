#ifndef STUPIDARR_H
#define STUPIDARR_H

#include <cassert>

template<typename T>
class StupidArr{
public:
	explicit StupidArr(int size) : size(size), arr(new T[size]) {}	//!!the user is responsible for deleting the array, hence its stupidity!!
	StupidArr(T* arr, int size) : size(size), arr(arr) {}
	StupidArr(const StupidArr& other) = default;
	StupidArr& operator=(const StupidArr& other) = default;
	T* arr;
	int size;

	T& operator[](int index) {
		assert(index >= 0 && index < size);
		return arr[index];
	}
	
};

#endif // !STUPIDARR_H