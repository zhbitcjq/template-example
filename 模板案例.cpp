#include <iostream>
#include <string> 

//ʵ��һ��ͨ�õ�������

//���Զ����õ��������ͣ��Լ����Զ����������ͽ��д洢
//�洢������
//���캯��������������
//�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
//����ͨ���±�ķ�ʽ��������Ԫ��
//���Ի�ȡ�����е�ǰԪ�ظ�������������� 
//�ṩβ�巨��βɾ��
//��ȡ��ǰԪ�ظ��������������
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
		
		//������������ MyArray<int> arr2(arr1)���� MyArray<int> arr2 = arr1; 
		MyArray(const MyArray& arr)
		{
			cout << "�������캯������" << endl; 
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			//this->pAddress = array.pAddress; ǳ�������⵼�¶��������ظ��ͷ�	[Error] stray '\307' in program
			this->pAddress = new T[arr.m_Capacity];
			for(int i = 0;i < this->m_Size; i++)
			{
				this->pAddress[i] = arr.pAddress[i];
			}
			
			
		 } 
/*		 
		MyArray(const MyArray& arr)
		{
			cout << "�������캯������" << endl; 
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
			//���ж�ԭ�������Ƿ�������
			//��������ͷ�
			cout << "operator��������" << endl; 
			if(this->pAddress != NULL)
			{
				delete[]  this->pAddress;
				this->pAddress = NULL;
				this->m_Capacity = 0;
				this->m_Size = 0;
			 } 
			 
			//���
			this->m_Size = arr.m_Size;
			this->m_Capacity = arr.m_Capacity;
			this->pAddress = new T[arr.m_Capacity];
			for(int i=0;i<this->m_Size;i++)
			{
				this->pAddress[i] = arr.pAddress[i];
			  }  
			  
			return *this;
		}
			//β�巨
			void Push_Back( T &val)
			{
				//�ж������Ƿ���ڴ�С
				if(this->m_Size == this->m_Capacity)
				{
					cout << "����" << endl;
					return;
				 }
				//cout << this->pAddress[this->m_Size] << endl; 
				this->pAddress[this->m_Size] = val;
				this->m_Size++;
			 } 
			 
			//βɾ����
			void Pop_Back()
			{
				//�߼�βɾ�����û����ʲ������һ��Ԫ��
				if(this->m_Size==0)
				{
					return;
				 } 
				 
				this->m_Size--;
			 } 
			
			//ͨ���±����Ԫ�� 
			//����������
			//��������Ϊ��ֵ����,TҪ�Ӹ�& 
			T& operator[](int index)
			{
				return this->pAddress[index];
			 }
			 
			//������������
			int get_capacity()
			{
				return this->m_Capacity;
			 } 
			
			
			//���������С
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
	cout << "��ʾ��������" << endl;
	
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
	cout << "��ʾ��������" << endl;
	
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
