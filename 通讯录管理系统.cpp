#include <iostream>
using namespace std;
#include <string.h>
#define MAX 1000

//设计联系人的结构体
struct Person {
	//姓名
	string m_Name;
	//性别 1男 2女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录的结构体
struct Addressbooks {
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_size;
};

//1、添加联系人
void addPerson(Addressbooks* abs) {
	//判断通讯录是否已满
	if (abs->m_size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		//添加具体的联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;

		//性别 1男 2女
		int sex = 0;
		cout << "请输入性别（1-男  2-女）：" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		
		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;

		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

		//地址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_size].m_Addr = addr;

		//更新通讯录人数
		abs->m_size++;

		cout << "添加成功！" << endl;

		system("pause"); //请按任意键继续
		system("cls"); //清屏操作
	}
}

//2、显示所有联系人信息
void showPerson(Addressbooks* abs) {
	if (abs->m_size == 0)
	{
		cout << "当前记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++) 
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << "\t";
			cout << endl;
		}
	}

	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name	) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i; //找到了，返回下标
		}
	}

	return -1; //遍历完了都没找到，返回-1
}

//3、删除指定的联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除人的姓名：" << endl;
	string name;
	cin >> name;

	//ret==-1未找到，否则找到了
	int ret = isExist(abs, name);
	if (ret != -1)
	{ 
		//查到此人，进行删除操作
		for (int i = ret; i < abs->m_size - 1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//4、查找指定的联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;

	//ret==-1未找到，否则找到了
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "查找成功，联系人的信息如下：" << endl;
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

// 5、修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改联系人的姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别（1-男，2-女）：" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "请输入地址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人，修改失败！" << endl;
	}

	system("pause");
	system("cls");
}

//6、清空所有联系人
void cleanPerson(Addressbooks* abs)
{
	cout << "清空联系人操作不可逆，按1则清空，按其他数字键则取消：" << endl;
	int temp;
	cin >> temp;
	if (temp == 1)
	{
		abs->m_size = 0;  //将当前记录的联系人数量置为0，做逻辑清空
		cout << "已清空所有联系人信息！" << endl;
	}
	else
	{
		cout << "已取消清空操作！" << endl;
	}

	system("pause");
	system("cls");
}

//菜单界面
void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****	1、添加联系人	*****" << endl;
	cout << "*****	2、显示联系人	*****" << endl;
	cout << "*****	3、删除联系人	*****" << endl;
	cout << "*****	4、查找联系人	*****" << endl;
	cout << "*****	5、修改联系人	*****" << endl;
	cout << "*****	6、清空联系人	*****" << endl;
	cout << "*****	0、退出通讯录	*****" << endl;
	cout << "*****************************" << endl;
}


int main() {

	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员的个数
	abs.m_size = 0;



	//创建用户输入的变量
	int select = 0;

	while (true) {

		//菜单调用
		showMenu();

		cin >> select;

		switch (select) {
		case 1:  // 1、添加联系人
			addPerson(&abs);//利用地址传递，可以修改实参
			break;
		case 2:  // 2、显示联系人
			showPerson(&abs);
			break;
		case 3:  // 3、删除联系人
			deletePerson(&abs);
			break;
		case 4:  // 4、查找联系人
			findPerson(&abs);
			break;
		case 5:  // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:  //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:  // 0、退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}