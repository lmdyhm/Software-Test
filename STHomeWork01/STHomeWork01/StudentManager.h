#include<vector>
#include<string>
class StudentManager
{
	
public:
	StudentManager();
	std::vector<std::vector<std::string>> sheet;	//ϵͳ��洢
	int length=0;			//��������
	bool shutdown=0;			//�Ƿ�ر�
	void appswitch();	//����ѡ��
	void push();		//���幦�ܲ���
	void lookup(std::string key);		//����
	void cutoff(std::string key);		//ɾ��
	void print();		//���
	bool terminate();	//�˳�
	void modify(std::string key);		//�޸ģ���ʵ�֣�
};
