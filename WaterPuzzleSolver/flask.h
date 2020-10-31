#pragma once
#include<stack>

using namespace std;

template<class T>
class flask : public stack<T>
{
private:
	int mMaxSize;
public:
	flask(const int maxSize):mMaxSize(maxSize){}
	~flask(){}
	bool full()
	{
		return (mMaxSize == this->size()) ? true : false;
	}
};

