#include<vector>
#include<string>
class StudentManager
{
	
public:
	StudentManager();
	std::vector<std::vector<std::string>> sheet;	//系统表存储
	int length=0;			//数据数量
	bool shutdown=0;			//是否关闭
	void appswitch();	//功能选择
	void push();		//具体功能插入
	void lookup(std::string key);		//查找
	void cutoff(std::string key);		//删除
	void print();		//输出
	bool terminate();	//退出
	void modify(std::string key);		//修改（已实现）
};
