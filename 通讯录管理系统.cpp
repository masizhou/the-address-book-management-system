#include <iostream>
using namespace std;
#include <string.h>
#define MAX 1000

//�����ϵ�˵Ľṹ��
struct Person {
	//����
	string m_Name;
	//�Ա� 1�� 2Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//���ͨѶ¼�Ľṹ��
struct Addressbooks {
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_size;
};

//1�������ϵ��
void addPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		//��Ӿ������ϵ��

		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;

		//�Ա� 1�� 2Ů
		int sex = 0;
		cout << "�������Ա�1-��  2-Ů����" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		
		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;

		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

		//��ַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_size].m_Addr = addr;

		//����ͨѶ¼����
		abs->m_size++;

		cout << "��ӳɹ���" << endl;

		system("pause"); //�밴���������
		system("cls"); //��������
	}
}

//2����ʾ������ϵ����Ϣ
void showPerson(Addressbooks* abs) {
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++) 
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << "\t";
			cout << endl;
		}
	}

	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name	) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i; //�ҵ��ˣ������±�
		}
	}

	return -1; //�������˶�û�ҵ�������-1
}

//3��ɾ��ָ������ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ���˵�������" << endl;
	string name;
	cin >> name;

	//ret==-1δ�ҵ��������ҵ���
	int ret = isExist(abs, name);
	if (ret != -1)
	{ 
		//�鵽���ˣ�����ɾ������
		for (int i = ret; i < abs->m_size - 1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

//4������ָ������ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;

	//ret==-1δ�ҵ��������ҵ���
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "���ҳɹ�����ϵ�˵���Ϣ���£�" << endl;
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

// 5���޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸���ϵ�˵�������" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�1-�У�2-Ů����" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴��ˣ��޸�ʧ�ܣ�" << endl;
	}

	system("pause");
	system("cls");
}

//6�����������ϵ��
void cleanPerson(Addressbooks* abs)
{
	cout << "�����ϵ�˲��������棬��1����գ����������ּ���ȡ����" << endl;
	int temp;
	cin >> temp;
	if (temp == 1)
	{
		abs->m_size = 0;  //����ǰ��¼����ϵ��������Ϊ0�����߼����
		cout << "�����������ϵ����Ϣ��" << endl;
	}
	else
	{
		cout << "��ȡ����ղ�����" << endl;
	}

	system("pause");
	system("cls");
}

//�˵�����
void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****	1�������ϵ��	*****" << endl;
	cout << "*****	2����ʾ��ϵ��	*****" << endl;
	cout << "*****	3��ɾ����ϵ��	*****" << endl;
	cout << "*****	4��������ϵ��	*****" << endl;
	cout << "*****	5���޸���ϵ��	*****" << endl;
	cout << "*****	6�������ϵ��	*****" << endl;
	cout << "*****	0���˳�ͨѶ¼	*****" << endl;
	cout << "*****************************" << endl;
}


int main() {

	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա�ĸ���
	abs.m_size = 0;



	//�����û�����ı���
	int select = 0;

	while (true) {

		//�˵�����
		showMenu();

		cin >> select;

		switch (select) {
		case 1:  // 1�������ϵ��
			addPerson(&abs);//���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2:  // 2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:  // 3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:  // 4��������ϵ��
			findPerson(&abs);
			break;
		case 5:  // 5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:  //6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:  // 0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
		default:
			cout << "����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}