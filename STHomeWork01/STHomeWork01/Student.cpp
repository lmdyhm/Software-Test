#include"Student.h"
#include<string>
#include<iostream>
#include<sstream>

Student::Student()
{
	std::cout << "请录入信息（性别男以数字1代替女以数字0代替）";
	std::cout << std::endl;
	std::cin >> this->ID;
	std::cin >> this->name;
	std::cin >> this->birDate;
	std::cin >> this->gender;



}
int Student::getID()
{
	return this->ID;
}
std::string Student::getname()
{
	return this->name;
}
std::string Student::getbirDate()
{
	return this->birDate;
}
bool Student::getgender()
{
	return this->gender;
}
std::vector<std::string> Student::getinfoemation()
{
	std::vector<std::string> info;
	std::stringstream str1;
	std::string  s1;
	int id = this->Student::getID();

	str1<< id;
	str1>>s1;
	info.push_back(s1);
	info.push_back(this->Student::getname());
	info.push_back(this->Student::getbirDate());
	if (this->Student::getgender() == 1)
		info.push_back("男");		//1代表男
	else
		info.push_back("女");		//0代表女
	return info;
}