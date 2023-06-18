#pragma once
#include <iostream>

template <typename T>
class Vector
{
	T* data = nullptr;
	size_t capacity;
	size_t size;

	void resize();

	void copyFrom(const Vector<T>& other);
	void free();

	void moveFrom(Vector<T>&& other);

public:
	Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);

	Vector(Vector<T>&& other);
	Vector<T>& operator=(Vector<T>&& other);

	void pushBack(const T& element);
	void pushBack(T&& element);

	void pushAt(const T& element, const size_t index);
	void pushAt(T&& element, const size_t index);

	void popBack();
	void popAt(const int index);

	const T& operator[](const size_t index) const;
	T& operator[](const size_t index);

	bool empty() const;
	void clear();

	size_t getSize() const;

	void swap(Vector<T>& other);

	~Vector();
};

template <typename T>
Vector<T>::Vector()
{
	capacity = 2;
	size = 0;

	data = new T[capacity];
}

template <typename T>
void Vector<T>::resize()
{
	capacity *= 2;
	T* resized = new T[capacity];

	for (size_t i = 0; i < size; ++i)
	{
		resized[i] = data[i];
	}

	delete[] data;
	data = resized;

	delete[] resized;
}

template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	capacity = other.capacity;
	size = other.size;

	data = new T[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		data[i] = other.data[i];
	}
}

template <typename T>
void Vector<T>::free()
{
	delete[] data;
	data = nullptr;
	capacity = size = 0;
}

template <typename T>
void Vector<T>::moveFrom(Vector<T>&& other)
{
	capacity = other.capacity;
	size = other.size;

	data = other.data;
	other.data = nullptr;

	other.size = other.capacity = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
void Vector<T>::pushBack(const T& element)
{
	if (size == capacity)
	{
		resize();
	}

	data[size++] = element;
}

template <typename T>
void Vector<T>::pushBack(T&& element)
{
	if (size == capacity)
	{
		resize();
	}

	data[size++] = std::move(element);
}

template <typename T>
void Vector<T>::pushAt(const T& element, const size_t index)
{
	if (size == capacity)
	{
		resize();
	}
	else if (index > size)
	{
		throw std::out_of_range("Index out of range!");
	}

	data[index] = element;
	++size;
}

template <typename T>
void Vector<T>::pushAt(T&& element, const size_t index)
{
	if (size == capacity)
	{
		resize();
	}
	else if (index > size)
	{
		throw std::out_of_range("Index out of range!");
	}

	data[index] = std::move(element);
	++size;
}

template <typename T>
void Vector<T>::popBack()
{
	if (empty())
	{
		throw std::invalid_argument("Empty vector!");
	}

	--size;
}

template <typename T>
void Vector<T>::popAt(const int index)
{
	if (index > size)
	{
		throw std::out_of_range("Index out of range!");
	}
	else if (empty())
	{
		throw std::invalid_argument("Empty vector!");
	}

	std::swap(data[index], data[size - 1]);
	--size;
}

template <typename T>
const T& Vector<T>::operator[](const size_t index) const
{
	return data[index];
}

template <typename T>
T& Vector<T>::operator[](const size_t index)
{
	return data[index];
}

template <typename T>
bool Vector<T>::empty() const
{
	return size == 0;
}

template <typename T>
void Vector<T>::clear()
{
	delete[] data;

	data = new T[capacity];
	size = 0;
}

template <typename T>
size_t Vector<T>::getSize() const
{
	return size;
}

template <typename T>
void Vector<T>::swap(Vector<T>& other)
{
	Vector<T> temp = std::move(other);

	other = std::move(*this);
	*this = std::move(temp);
}

template <typename T>
Vector<T>::~Vector()
{
	free();
}