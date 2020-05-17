#include"Student.h"
#include<string>
#include<iostream>
#include<sstream>

Student::Student()
{
	std::cout << "请录入信息，格式为：";
	std::cout << std::endl;
	std::cout << "学号 姓名 生日 性别（性别男以数字1代替女以数字0代替）";
	std::cout << std::endl;
	std::cin >> ID;
	std::cin >> name;
	std::cin >> birDate;
	std::cin >> gender;
}
int Student::getID()
{
	return ID;
}
std::string Student::getname()
{
	return name;
}
std::string Student::getbirDate()
{
	return birDate;
}
bool Student::getgender()
{
	return gender;
}
std::vector<std::string> Student::getinfoemation()
{
	std::vector<std::string> info;
	std::stringstream str1;
	std::string  s1;
	int id = Student::getID();
	str1<< id;
	str1>>s1;
	info.push_back(s1);
	info.push_back(Student::getname());
	info.push_back(Student::getbirDate());
	if (Student::getgender() == 1)
		info.push_back("男");		//1代表男
	else
		info.push_back("女");		//0代表女
	return info;
	str1.str("");					              //40 已关闭
}