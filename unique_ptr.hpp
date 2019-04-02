//#include<utility>
#include<algorithm>
class unique_ptr
{
private:
	int* data;

public:
	unique_ptr(int* data) : data(data)
	{}

	~unique_ptr()
	{
		delete data;
	}

	unique_ptr(const unique_ptr&) = delete;

	//operator overloads
	unique_ptr& operator=(const unique_ptr&) = delete;
	int* operator*() { return data; }
	int& operator->() { return *data; }
	
	int* get() { return data; }

	int* release()
	{
		//int* result = std::exchange(data, nullptr); - better?
		int* result = data;
		data = nullptr;
		return result;
	}

	void swap(unique_ptr& other)
	{
		//std::swap(data, other.data); - better?
		int* temp = data;
		data = other.data;
		other.data = temp;
		delete temp;
	}

};