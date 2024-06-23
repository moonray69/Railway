#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>
using namespace std;

template <typename T>
class container
{
private:
	T* arr;
	int size;
	int copacity;
public:
	container() {
		arr = 0;
		size = 0;
		copacity = 0;
	}

	container(int size_) {
		size = 0;
		arr = new T[size_];
		copacity = size_;
	}

	container(const container& other) {
		this->size = other.size;
		this->copacity = other.copacity;
		this->arr = new T[other.copacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}

	~container() { delete[] arr; }

	/*void print()const {
		for (int i = 0; i < size; i++)
		{
			arr[i].print();
		}
	}*/

	T& operator[](int index) {
		if (index < 0 || index >= copacity) {
			cerr << ("Помилка)");
		}
		return arr[index];
	}

	void push_back(const T& data) {
		if (size == copacity) {
			copacity += 10;
			T* new_arr = new T[copacity];
			for (int i = 0; i < size; i++)
			{
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
		}
		arr[size++] = data;
	}

	void pop_back(int index) {
		if (index < 0 || index >= size) {
			throw exception("Помилка)");
		}
		for (int i = index; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		--size;
	}

	int get_copacity()const {
		return copacity;
	}

	int get_size()const {
		return size;
	}
};

