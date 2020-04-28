#include<iostream>
#include<Windows.h>
#include"Student.h"
#include"StudentManager.h"
int main()
{
	StudentManager s1 ;
	
	int button = 0;
	while (button == 0)
	{
		s1.StudentManager::appswitch();
		std::cout << std::endl;
		if (s1.StudentManager::terminate() == 1)
			button = 1;
	}
	std::cout << "³ÌÐòÒÑÍË³ö";
	system("pause");
	return 0;
}