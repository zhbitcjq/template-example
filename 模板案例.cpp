#include <iostream>
#include <string> 

//实现一个通用的数组类

//可以对内置的数据类型，以及对自定义数据类型进行存储
//存储到堆区
//构造函数传入数组容量
//提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//可以通过下标的方式访问数组元素
//可以获取数组中当前元素个数和数组的容量 
//提供尾插法和尾删法
//获取当前元素个数和数组的容量
using namespace std;

template <typename T>
class MyArray{
	public:
		
		MyArray(int Capacity)
		{
			cout << "hello" << endl; 
			this->m_Capacity = Capacity;
			this->m_Size = 0;
			this->pAddress = new T[this->m_Capacity];
		}
		
		~MyArray()
		{
			if (this->pAddress!=NULL)
			{
				cout << "bye" << endl; 
				delete[] this->pAddress;
				this->pAddress = NULL;
			}
		}
		
		//拷贝构造用于 MyArray<int> arr2(arr1)或者 MyArray<int> arr2 = arr1; 
		MyArray(const MyArray& arr)
		{
			cout << "拷贝构造函数调用" << endl; 
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			//this->pAddress = array.pAddress; 浅拷贝问题导致堆区问题重复释放	[Error] stray '\307' in program
			this->pAddress = new T[arr.m_Capacity];
			for(int i = 0;i < this->m_Size; i++)
			{
				this->pAddress[i] = arr.pAddress[i];
			}
			
			
		 } 
/*		 
		MyArray(const MyArray& arr)
		{
			cout << "拷贝构造函数调用" << endl; 
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			//this->pAddress = arr.pAddress;
			this->pAddress = new T[arr.m_Capacity];
			for(int i = 0;i < this->m_Size;i++)
			{
				this->pAddress[i] = arr.pAddress[i];
			}
		 } 
*/		 
		// 	MyArray<int>arr4(100);
		//  arr4 = arr3;
		MyArray& operator=(const MyArray& arr)
		{
			//先判断原来堆区是否有数据
			//如果有先释放
			cout << "operator函数调用" << endl; 
			if(this->pAddress != NULL)
			{
				delete[]  this->pAddress;
				this->pAddress = NULL;
				this->m_Capacity = 0;
				this->m_Size = 0;
			 } 
			 
			//深拷贝
			this->m_Size = arr.m_Size;
			this->m_Capacity = arr.m_Capacity;
			this->pAddress = new T[arr.m_Capacity];
			for(int i=0;i<this->m_Size;i++)
			{
				this->pAddress[i] = arr.pAddress[i];
			  }  
			  
			return *this;
		}
			//尾插法
			void Push_Back( T &val)
			{
				//判断容量是否等于大小
				if(this->m_Size == this->m_Capacity)
				{
					cout << "满了" << endl;
					return;
				 }
				//cout << this->pAddress[this->m_Size] << endl; 
				this->pAddress[this->m_Size] = val;
				this->m_Size++;
			 } 
			 
			//尾删除法
			void Pop_Back()
			{
				//逻辑尾删，让用户访问不到最后一个元素
				if(this->m_Size==0)
				{
					return;
				 } 
				 
				this->m_Size--;
			 } 
			
			//通过下标访问元素 
			//重载中括号
			//还可以作为左值存在,T要加个& 
			T& operator[](int index)
			{
				return this->pAddress[index];
			 }
			 
			//返回数组容量
			int get_capacity()
			{
				return this->m_Capacity;
			 } 
			
			
			//返回数组大小
			int get_size()
			{
				return this->m_Size;
			 } 
		
		
		 
		 
	private:
		T * pAddress;
		
		int m_Capacity;
		
		int m_Size;
		
};

void printArray(MyArray<int>& arr)
{
	cout << "显示数组内容" << endl;
	
	for(int i=0;i<arr.get_size();i++)
	{
	 	cout << arr[i] <<endl;
	}
	
}

class Person{
	public:
		string m_name;
		int m_age;
		
	Person();
	
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age	 = age; 
	} 
};

void printArray(MyArray<Person>& arr)
{
	cout << "显示数组内容" << endl;
	
}


void test01()
{
/*
	MyArray<int>arr1(5);
	//cout << arr1.get_capacity() << endl;
	//cout << arr1.get_size() << endl;
	
	for(int i = 0; i <arr1.get_capacity();i++)
	{
		//cout << arr1.get_size() << endl;
		arr1.Push_Back(i);
	}
	printArray(arr1);
	
	
	//MyArray<int>arr2 =arr1; 
	
	//MyArray<int>arr3(arr2);
	
	//MyArray<int>arr4(100);
	
	//arr4 = arr3;
	
*/
}

void printArray2(MyArray<Person>& arr)
{
	for(int i = 0; i < arr.get_size();i++)
	{
		cout << arr[i].m_name << arr[i].m_age << endl;
	}
}


void test2()
{

	MyArray<Person> arr2(6);
	Person p1("a",1);
	Person p2("b",2);
	Person p3("c",3);
	Person p4("d",4);
	Person p5("e",5);
	arr2.Push_Back(p1);
	arr2.Push_Back(p2);
	arr2.Push_Back(p3);
	arr2.Push_Back(p4);
	arr2.Push_Back(p5);
	
	printArray2(arr2);
}
int main()
{
	//test01();
	test2();
	
	return 0;
 } 
