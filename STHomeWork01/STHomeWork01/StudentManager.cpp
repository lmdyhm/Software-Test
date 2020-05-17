#include"StudentManager.h"
#include"Student.h"
#include<iostream>
#include<string>
#include<vector>

StudentManager::StudentManager()
{
	std::cout << "��ѡ�������"<< std::endl;
	for (int i = 0; i < 35; i++)
	{
		std::cout << '*';
	}
	std::cout << std::endl;
	std::cout << "1 ����" << std::endl;
	std::cout << "2 ����" << std::endl;
	std::cout << "3 ɾ��" << std::endl;
	std::cout << "4 �޸�" << std::endl;
	std::cout << "5 ���" << std::endl;
	std::cout << "6 �˳�" << std::endl;
	for (int i = 0; i < 35; i++)
	{
		std::cout << '*';
	}
	std::cout << std::endl;
}
void StudentManager::appswitch()
{
	int number;
	std::cin >> number;
	if (number == 1)
	{
		if (this->length < 20) 
		{
			this->StudentManager::push();
		}
		else
			std::cout << "�����Ѵﵽ����";	
	}
	else if (number == 2)
	{
		std::cout << "������Ҫ��ѯ������������ʽ�������Ϣ�ĸ�ʽһ�£�";
		std::cout << std::endl;
		std::string name;
		std::cin >> name;
		this->StudentManager::lookup(name);
	}
	else if (number == 3)
	{
		std::cout << "������Ҫɾ�����ݵ�ѧ����������";
		std::cout << std::endl;
		std::string name;
		std::cin >> name;
		this->StudentManager::cutoff(name);
	}
	else if (number == 4)
	{
		std::cout << "������Ҫ�޸���Ϣ��ѧ����������";
		std::cout << std::endl;
		std::string name;
		std::cin >> name;
		this->StudentManager::modify(name);
	}
	else if (number == 5)
	{
		this->StudentManager::print();
	}
	else if (number == 6)
	{
		this->shutdown = 1;
	}
	else
	{
		throw std::string("���ܲ�����");
	}
}

void StudentManager::push()
{
	Student s;
	if (this->length == 0)
	{
		this->StudentManager::sheet.push_back(s.Student::getinfoemation());
	}
	else
	{															//����
		std::vector<std::vector<std::string>>rest;
		for (int i = 0; i < this->length; i++)
		{
			if (s.Student::getinfoemation()[0] < this->sheet[i][0])
			{
				for (int j = this->length-1; j >= i; j--)
				{
					rest.push_back(this->sheet[j]);
					this->sheet.pop_back();
					
				}
				this->StudentManager::sheet.push_back(s.Student::getinfoemation());
				
				for (int k = rest.size()-1; k >= 0; k--)
				{
						this->StudentManager::sheet.push_back(rest[k]);			//���°�ʣ�µ����ݲ��ȥ
						rest.pop_back();
				}
				break;
			}
		}
	}
	this->length++;
	std::cout << "���ݲ���ɹ�";
}
void StudentManager::lookup(std::string key)
{
	std::cout << "��ѯ�������";
	int target=-1;
	for (int i = 0; i < this->length; i++)
	{
		if (this->sheet[i][1] == key)
		{
			target = i;
		}
	}
	if (target == -1)
	{
		std::cout << std::endl;
		std::cout << "δ�ҵ���ѧ��";
	}
	else 
	{
		for (int i = 0; i < 4; i++)
		{
			std::string temp = this->sheet[target][i];
			std::cout << temp << ' ';
		}
	}
	
}
void StudentManager::cutoff(std::string key)
{
	int target = -1;
	for (int i = 0; i < this->length; i++)
	{
		if (this->sheet[i][1] == key)
		{
			target = i;
		}
	}
	if (target == -1)
	{
		std::cout << "��ѧ��������";
	}
	else
	{
		std::vector<std::vector<std::string>>rest;
		for (int j = this->length - 1; j > target; j--)
		{
			rest.push_back(this->sheet[j]);
			this->sheet.pop_back();
		}
		this->StudentManager::sheet.pop_back();

		for (int k = rest.size() - 1; k >= 0; k--)
		{
			this->StudentManager::sheet.push_back(rest[k]);			//���°�ʣ�µ����ݲ��ȥ
			rest.pop_back();
		}
		this->length--;
		std::cout << "����ɾ���ɹ�";
	}	
}
void StudentManager::modify(std::string key)
{
	int target=-1;
	for (int i = 0; i < this->length; i++)
	{
		if (this->sheet[i][1] == key)
		{
			target = i;
		}
	}
	if (target == -1)
	{
		std::cout << "��ѧ��������";
	}
	else
	{
		std::cout << "�������޸ĺ������ѧ����Ϣ����ʽ�������Ϣ�ĸ�ʽһ�£���";
		std::cout << std::endl;
		std::cin >> this->sheet[target][0];
		std::cin >> this->sheet[target][1];
		std::cin >> this->sheet[target][2];
		std::string temp;
		std::cin >> temp;
		if (temp == "0")
		{
			this->sheet[target][3] = "��";
		}
		if (temp == "1")
		{
			this->sheet[target][3] = "Ů";
		}
		else
		{
			std::cout << "��������ȷ��ʽ����Ϣ";
			std::cout << std::endl;
			std::cin >> this->sheet[target][0];
			std::cin >> this->sheet[target][1];
			std::cin >> this->sheet[target][2];
			std::string temp;
			std::cin >> temp;
			if (temp == "0")
				this->sheet[target][3] = "��";
			if (temp == "1")
				this->sheet[target][3] = "Ů";	
		}
		std::cout << "�����޸ĳɹ�";
	}	
}
void StudentManager::print()
{
	if(this->length==0)
		std::cout << "û�в�������";
	else
	{
		std::cout << "��������";
		std::cout << std::endl;
		for (int i = 0; i < this->length; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << this->sheet[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}
bool StudentManager::terminate()
{
	bool cheekresult;
	if (this->shutdown == 1)
	{
		return cheekresult = 1;
	}
	else
	{
		return cheekresult = 0;
	}
}