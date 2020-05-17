#include"StudentManager.h"
#include"Student.h"
#include<iostream>
#include<string>
#include<vector>

StudentManager::StudentManager()
{
	std::cout << "请选择操作："<< std::endl;
	for (int i = 0; i < 35; i++)
	{
		std::cout << '*';
	}
	std::cout << std::endl;
	std::cout << "1 插入" << std::endl;
	std::cout << "2 查找" << std::endl;
	std::cout << "3 删除" << std::endl;
	std::cout << "4 修改" << std::endl;
	std::cout << "5 输出" << std::endl;
	std::cout << "6 退出" << std::endl;
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
			std::cout << "数据已达到上限";	
	}
	else if (number == 2)
	{
		std::cout << "请输入要查询的姓名：（格式与插入信息的格式一致）";
		std::cout << std::endl;
		std::string name;
		std::cin >> name;
		this->StudentManager::lookup(name);
	}
	else if (number == 3)
	{
		std::cout << "请输入要删除数据的学生的姓名：";
		std::cout << std::endl;
		std::string name;
		std::cin >> name;
		this->StudentManager::cutoff(name);
	}
	else if (number == 4)
	{
		std::cout << "请输入要修改信息的学生的姓名：";
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
		throw std::string("功能不存在");
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
	{															//排序
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
						this->StudentManager::sheet.push_back(rest[k]);			//重新把剩下的数据插回去
						rest.pop_back();
				}
				break;
			}
		}
	}
	this->length++;
	std::cout << "数据插入成功";
}
void StudentManager::lookup(std::string key)
{
	std::cout << "查询结果如下";
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
		std::cout << "未找到该学生";
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
		std::cout << "该学生不存在";
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
			this->StudentManager::sheet.push_back(rest[k]);			//重新把剩下的数据插回去
			rest.pop_back();
		}
		this->length--;
		std::cout << "数据删除成功";
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
		std::cout << "该学生不存在";
	}
	else
	{
		std::cout << "请输入修改后的完整学生信息（格式与插入信息的格式一致）：";
		std::cout << std::endl;
		std::cin >> this->sheet[target][0];
		std::cin >> this->sheet[target][1];
		std::cin >> this->sheet[target][2];
		std::string temp;
		std::cin >> temp;
		if (temp == "0")
		{
			this->sheet[target][3] = "男";
		}
		if (temp == "1")
		{
			this->sheet[target][3] = "女";
		}
		else
		{
			std::cout << "请输入正确格式的信息";
			std::cout << std::endl;
			std::cin >> this->sheet[target][0];
			std::cin >> this->sheet[target][1];
			std::cin >> this->sheet[target][2];
			std::string temp;
			std::cin >> temp;
			if (temp == "0")
				this->sheet[target][3] = "男";
			if (temp == "1")
				this->sheet[target][3] = "女";	
		}
		std::cout << "数据修改成功";
	}	
}
void StudentManager::print()
{
	if(this->length==0)
		std::cout << "没有插入数据";
	else
	{
		std::cout << "数据如下";
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