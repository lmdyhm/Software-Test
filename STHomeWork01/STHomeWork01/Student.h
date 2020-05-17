#include<string>
#include<vector>
class Student
{
public:
	Student();
	int getID();
	std::string getname();
	std::string getbirDate();
	bool getgender();
	std::vector<std::string> getinfoemation();
private:
	int ID;
	std::string name;
	std::string birDate;
	bool gender;
};
