#include <stdexcept>
template<class T>
class CheckedArray
{
public:
	CheckedArray();
	CheckedArray(int size);
	~CheckedArray();
	T& operator[](int index);
	int length();
private:
	T* p;
	int size;
};

template<class T>
CheckedArray<T>::CheckedArray() : size(10)
{
	p = new T[size];
}

template<class T>
CheckedArray<T>::CheckedArray(int size) : size(size)
{
	p = new T[size];
}

template<class T>
CheckedArray<T>::~CheckedArray() {
	delete p;
	p = nullptr;
}

template<class T>
int CheckedArray<T>::length()
{
	return size;
}

template<class T>
T& CheckedArray<T>::operator[](int index){
	if( index < 0 || index > size ){
		throw std::runtime_error("BAD BAD BAD BAD BAD BAD BAD BAD TRY AGAIN TRY AGAIN BAD BAD");
	}
	return *(p + index);
}
