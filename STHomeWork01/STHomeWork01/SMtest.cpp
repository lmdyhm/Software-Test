#include<iostream>
#include<Windows.h>
#include<vector>
#include"Student.h"
#include"StudentManager.h"
int main()
{
	StudentManager s1 ;
	int button = 0;
	while (button == 0)
	{
		try 
		{
			s1.StudentManager::appswitch();
			std::cout << std::endl;
			if (s1.StudentManager::terminate() == 1)
				button = 1;
		}
		catch (std::string)
		{
			std::cout << "功能不存在"<<std::endl;
		}
		
	}
	std::cout << "程序已退出";
	system("pause");
	return 0;
}