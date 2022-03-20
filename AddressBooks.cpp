#include "AddressBooks.h"

struct Person
{
	string m_name;//����
	string m_sex;//�Ա� 1.��  2.Ů
	string m_age;//����
	string m_phone;//�绰
	string m_qq;//QQ
	string m_eleaddr;//��������
	string m_addr;//סַ
};
struct AddressBooks
{
	struct Person personA[MAX];
	int m_size;//��ǰ����
};
void menu()
{
	printf("***********************\n");
	printf("***********************\n");
	printf("*****1�������ϵ��*****\n");
	printf("*****2����ʾ��ϵ��*****\n");
	printf("*****3��������ϵ��*****\n");
	printf("*****4��ɾ����ϵ��*****\n");
	printf("*****5���޸���ϵ��*****\n");
	printf("*****6�������ϵ��*****\n");
	printf("*****0���˳�ͨѶ¼*****\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("\n");
	printf("���棺�벻Ҫ�������������κ��ַ���\n");
}
void addPers(AddressBooks* abs)
{
	system("cls");
	if (abs->m_size != MAX)
	{
		string name;
		printf("������������ ");
		cin >> name;
		abs->personA[abs->m_size].m_name = name;
		printf("\n�������Ա� ");
		string sex;
		while (1)
	    {
	    	cin >> sex;
	    	if (sex == "��" || sex == "Ů")
	        {
		    	abs->personA[abs->m_size].m_sex = sex;
		    	break;
	        }
		    printf("�����������������룡");
	   	}
		printf("\n���������䣺 ");
		string age;
		cin >> age;
		abs->personA[abs->m_size].m_age = age;
		printf("\n��������ϵ�绰�� ");
		string phone;
		cin >> phone;
		abs->personA[abs->m_size].m_phone = phone;
		printf("\n������QQ�ţ� ");
		string qq;
		cin >> qq;
		abs->personA[abs->m_size].m_qq = qq;
		printf("\n������������䣺 ");
		string eleaddr;
		cin >> eleaddr;
		abs->personA[abs->m_size].m_eleaddr = eleaddr;
		printf("\n������סַ�� ");
		string addr;
		cin >> addr;
		abs->personA[abs->m_size].m_addr = addr;
		abs->m_size++;
		printf("\n��ӳɹ���\n ");
	}
	else
	{
		printf("\n�޷���ӣ�ͨѶ¼���������������\n");
	}
	system("pause");
}
void showPers(AddressBooks* abs)
{
	system("cls");
	if (abs->m_size != 0)
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			printf("%d��������%s  �Ա�%s  ���䣺%s  ��ϵ�绰��%s  QQ�ţ�%s  �������䣺%s  סַ��%s \n"
				, i + 1, abs->personA[i].m_name.c_str(), abs->personA[i].m_sex.c_str(), abs->personA[i].m_age.c_str(),
				abs->personA[i].m_phone.c_str(), abs->personA[i].m_qq.c_str(), abs->personA[i].m_eleaddr.c_str(), 
				abs->personA[i].m_addr.c_str());
		}
	}
	else
	{
		printf("û����ϵ�ˣ�\n");
	}
	system("pause");
}
int isExist(AddressBooks* abs, string name)
{
	system("cls");
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personA[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
void deletePers(AddressBooks* abs)
{
	while (1)
	{
		system("cls");
		printf("��������Ҫɾ������ϵ�˵�������");
		string name;
		cin >> name;
		int ret = isExist(abs, name);
		if (ret == -1)
		{
			printf("���޴��ˣ�\n");
			system("pause");
			break;
		}
		else
		{
			printf("ȷ��ɾ����\n��Y/N��");
			char select;
			cin >> select;
			if (select == 'Y' || select == 'y')
			{
				for (int i = ret; i < abs->m_size; i++)
				{
					abs->personA[i] = abs->personA[i + 1];
				}
				abs->m_size--;
				break;
			}
			else if (select == 'N' || select == 'n')
			{
				break;
			}
			else
			{
				printf("�޷�ʶ��ָ����������룡\n");
			}
		}
	}
	system("cls");
}
void findPers(AddressBooks* abs)
{
	system("cls");
	string name;
	printf("��������ϵ�������� ");
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		printf("\n��ϵ�˴��ڣ�����ΪTA����Ϣ�� \n");
		printf("\t������%s\n  \t�Ա�%s\n  \t���䣺%s\n  \t��ϵ�绰��%s\n  \tQQ�ţ�%s\n  \t�������䣺%s\n  \tסַ��%s \n\n"
			,abs->personA[ret].m_name.c_str(), abs->personA[ret].m_sex.c_str(), abs->personA[ret].m_age.c_str(),
			abs->personA[ret].m_phone.c_str(), abs->personA[ret].m_qq.c_str(), abs->personA[ret].m_eleaddr.c_str(),
			abs->personA[ret].m_addr.c_str());
	}
	else
	{
		printf("\n��ϵ�˲����ڣ�");
	}
	system("pause");
}
void modifyPers(AddressBooks* abs)
{
	system("cls");
	string name;
	printf("��������Ҫ������Ϣ���˵������� ");
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		char modify = NULL;
		printf("�Ƿ��޸�������\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newname;
				printf("\n�������µ������� ");
				cin >> newname;
				abs->personA[ret].m_name = newname;
				break;
			}
			else if (modify == 'N' || modify == 'n')
			{
				break;
			}
			else
			{
				printf("\n�޷�ʶ��ָ����������룡");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n�Ƿ��޸��Ա�\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newsex;
				printf("\n�������µ��Ա� ");
				cin >> newsex;
				abs->personA[ret].m_sex = newsex;
				break;
			}
			else if (modify == 'N' || modify == 'n')
			{
				break;
			}
			else
			{
				printf("\n�޷�ʶ��ָ����������룡");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n�Ƿ��޸����䣿\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newage;
				printf("\n�������µ����䣺 ");
				cin >> newage;
				abs->personA[ret].m_age = newage;
				break;
			}
			else if (modify == 'N' || modify == 'n')
			{
				break;
			}
			else
			{
				printf("\n�޷�ʶ��ָ����������룡");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n�Ƿ��޸���ϵ�绰��\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newphone;
				printf("\n�������µ���ϵ�绰�� ");
				cin >> newphone;
				abs->personA[ret].m_phone = newphone;
				break;
			}
			else if (modify == 'N' || modify == 'n')
			{
				break;
			}
			else
			{
				printf("\n�޷�ʶ��ָ����������룡");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n�Ƿ��޸�QQ�ţ�\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newqq;
				printf("\n�������µ�QQ�ţ� ");
				cin >> newqq;
				abs->personA[ret].m_qq = newqq;
				break;
			}
			else if (modify == 'N' || modify == 'n')
			{
				break;
			}
			else
			{
				printf("\n�޷�ʶ��ָ����������룡");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n�Ƿ��޸ĵ������䣿\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string neweleaddr;
				printf("\n�������µĵ������䣺 ");
				cin >> neweleaddr;
				abs->personA[ret].m_eleaddr = neweleaddr;
				break;
			}
			else if (modify == 'N' || modify == 'n')
			{
				break;
			}
			else
			{
				printf("\n�޷�ʶ��ָ����������룡");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n�Ƿ��޸�סַ��\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newaddr;
				printf("\n�������µ�סַ�� ");
				cin >> newaddr;
				abs->personA[ret].m_addr = newaddr;
				break;
			}
			else if (modify == 'N' || modify == 'n')
			{
				break;
			}
			else
			{
				printf("\n�޷�ʶ��ָ����������룡");
				modify = NULL;
			}
		}
		printf("\n�޸ĳɹ���\n");
	}
	else
	{
		printf("���޴��ˣ�\n");
	}
	system("pause");
	system("cls");
}
void cleanPers(AddressBooks* abs)
{
	system("cls");
	char clean = NULL;
	printf("ȷ��ɾ��������ϵ�ˣ�\n(Y/N)");
	while (1)
	{
		cin >> clean;
		if (clean == 'Y' || clean == 'y')
		{
			abs->m_size = 0;
			printf("��ϵ������գ�\n");
			break;
		}
		else if (clean == 'N' || clean == 'n')
		{
			break;
		}
		else
		{
			printf("�޷�ʶ��ָ����������룡");
		}
	}
	system("pause");
}
void saveData(AddressBooks* abs)
{
	ofstream foutput("Data.txt");
	for (int i = 0; i < abs->m_size; i++)
	{
		foutput << abs->personA[i].m_name << endl;
		foutput << abs->personA[i].m_sex << endl;
		foutput << abs->personA[i].m_age << endl;
		foutput << abs->personA[i].m_phone << endl;
		foutput << abs->personA[i].m_qq << endl;
		foutput << abs->personA[i].m_eleaddr << endl;
		foutput << abs->personA[i].m_addr << endl;
	}
	foutput.close();
}
void readData(AddressBooks* abs)
{
	abs->m_size = 0;
	ifstream ifs;
	ifs.open("Data.txt", ios::in);
	string temp;
	int i = 0;
	while (ifs >> temp)
	{
		i == 0 ? abs->personA[abs->m_size].m_name = temp : temp = temp;
		i == 1 ? abs->personA[abs->m_size].m_sex = temp : temp = temp;
		i == 2 ? abs->personA[abs->m_size].m_age = temp : temp = temp;
		i == 3 ? abs->personA[abs->m_size].m_phone = temp : temp = temp;
		i == 4 ? abs->personA[abs->m_size].m_qq = temp : temp = temp;
		i == 5 ? abs->personA[abs->m_size].m_eleaddr = temp : temp = temp;
		i == 6 ? abs->personA[abs->m_size].m_addr = temp : temp = temp;
		i++;
		if (i >= 7)
		{
			abs->m_size++;
			i = 0;
		}
	}
	ifs.close();
}
int main()
{
	AddressBooks abs;
	readData(&abs);
	while (1)
	{
		//�˵�
		system("cls");
		menu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPers(&abs);
			break;	
		case 2://2����ʾ��ϵ��
			showPers(&abs);
			break;	
		case 3://3��������ϵ��
			findPers(&abs);
			break;	
		case 4://4��ɾ����ϵ��
			deletePers(&abs);
	    	break;
		case 5://5���޸���ϵ��
			modifyPers(&abs);
			break;	
		case 6://6�������ϵ��
			cleanPers(&abs);
			break;	
		case 0://0�����沢�˳�ͨѶ¼
			saveData(&abs);
			system("pause");
			return 0;
			break;
		default://�������
			printf("�޴˹��ܣ�\n");
			break;
		}
	}
}