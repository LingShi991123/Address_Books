#include "AddressBooks.h"

struct Person
{
	string m_name;//姓名
	string m_sex;//性别 1.男  2.女
	string m_age;//年龄
	string m_phone;//电话
	string m_qq;//QQ
	string m_eleaddr;//电子邮箱
	string m_addr;//住址
};
struct AddressBooks
{
	struct Person personA[MAX];
	int m_size;//当前个数
};
void menu()
{
	printf("***********************\n");
	printf("***********************\n");
	printf("*****1、添加联系人*****\n");
	printf("*****2、显示联系人*****\n");
	printf("*****3、查找联系人*****\n");
	printf("*****4、删除联系人*****\n");
	printf("*****5、修改联系人*****\n");
	printf("*****6、清空联系人*****\n");
	printf("*****0、退出通讯录*****\n");
	printf("***********************\n");
	printf("***********************\n");
	printf("\n");
	printf("警告：请不要输入除数字外的任何字符！\n");
}
void addPers(AddressBooks* abs)
{
	system("cls");
	if (abs->m_size != MAX)
	{
		string name;
		printf("请输入姓名： ");
		cin >> name;
		abs->personA[abs->m_size].m_name = name;
		printf("\n请输入性别： ");
		string sex;
		while (1)
	    {
	    	cin >> sex;
	    	if (sex == "男" || sex == "女")
	        {
		    	abs->personA[abs->m_size].m_sex = sex;
		    	break;
	        }
		    printf("输入有误！请重新输入！");
	   	}
		printf("\n请输入年龄： ");
		string age;
		cin >> age;
		abs->personA[abs->m_size].m_age = age;
		printf("\n请输入联系电话： ");
		string phone;
		cin >> phone;
		abs->personA[abs->m_size].m_phone = phone;
		printf("\n请输入QQ号： ");
		string qq;
		cin >> qq;
		abs->personA[abs->m_size].m_qq = qq;
		printf("\n请输入电子邮箱： ");
		string eleaddr;
		cin >> eleaddr;
		abs->personA[abs->m_size].m_eleaddr = eleaddr;
		printf("\n请输入住址： ");
		string addr;
		cin >> addr;
		abs->personA[abs->m_size].m_addr = addr;
		abs->m_size++;
		printf("\n添加成功！\n ");
	}
	else
	{
		printf("\n无法添加！通讯录可添加人数已满！\n");
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
			printf("%d、姓名：%s  性别：%s  年龄：%s  联系电话：%s  QQ号：%s  电子邮箱：%s  住址：%s \n"
				, i + 1, abs->personA[i].m_name.c_str(), abs->personA[i].m_sex.c_str(), abs->personA[i].m_age.c_str(),
				abs->personA[i].m_phone.c_str(), abs->personA[i].m_qq.c_str(), abs->personA[i].m_eleaddr.c_str(), 
				abs->personA[i].m_addr.c_str());
		}
	}
	else
	{
		printf("没有联系人！\n");
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
		printf("请输入需要删除的联系人的姓名：");
		string name;
		cin >> name;
		int ret = isExist(abs, name);
		if (ret == -1)
		{
			printf("查无此人！\n");
			system("pause");
			break;
		}
		else
		{
			printf("确定删除？\n（Y/N）");
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
				printf("无法识别指令！请重新输入！\n");
			}
		}
	}
	system("cls");
}
void findPers(AddressBooks* abs)
{
	system("cls");
	string name;
	printf("请输入联系人姓名： ");
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		printf("\n联系人存在！以下为TA的信息： \n");
		printf("\t姓名：%s\n  \t性别：%s\n  \t年龄：%s\n  \t联系电话：%s\n  \tQQ号：%s\n  \t电子邮箱：%s\n  \t住址：%s \n\n"
			,abs->personA[ret].m_name.c_str(), abs->personA[ret].m_sex.c_str(), abs->personA[ret].m_age.c_str(),
			abs->personA[ret].m_phone.c_str(), abs->personA[ret].m_qq.c_str(), abs->personA[ret].m_eleaddr.c_str(),
			abs->personA[ret].m_addr.c_str());
	}
	else
	{
		printf("\n联系人不存在！");
	}
	system("pause");
}
void modifyPers(AddressBooks* abs)
{
	system("cls");
	string name;
	printf("请输入需要更改信息的人的姓名： ");
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		char modify = NULL;
		printf("是否修改姓名？\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newname;
				printf("\n请输入新的姓名： ");
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
				printf("\n无法识别指令！请重新输入！");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n是否修改性别？\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newsex;
				printf("\n请输入新的性别： ");
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
				printf("\n无法识别指令！请重新输入！");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n是否修改年龄？\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newage;
				printf("\n请输入新的年龄： ");
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
				printf("\n无法识别指令！请重新输入！");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n是否修改联系电话？\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newphone;
				printf("\n请输入新的联系电话： ");
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
				printf("\n无法识别指令！请重新输入！");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n是否修改QQ号？\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newqq;
				printf("\n请输入新的QQ号： ");
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
				printf("\n无法识别指令！请重新输入！");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n是否修改电子邮箱？\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string neweleaddr;
				printf("\n请输入新的电子邮箱： ");
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
				printf("\n无法识别指令！请重新输入！");
				modify = NULL;
			}
		}
		modify = NULL;
		printf("\n是否修改住址？\n(Y/N)");
		while (1)
		{
			cin >> modify;
			if (modify == 'Y' || modify == 'y')
			{
				string newaddr;
				printf("\n请输入新的住址： ");
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
				printf("\n无法识别指令！请重新输入！");
				modify = NULL;
			}
		}
		printf("\n修改成功！\n");
	}
	else
	{
		printf("查无此人！\n");
	}
	system("pause");
	system("cls");
}
void cleanPers(AddressBooks* abs)
{
	system("cls");
	char clean = NULL;
	printf("确定删除所有联系人？\n(Y/N)");
	while (1)
	{
		cin >> clean;
		if (clean == 'Y' || clean == 'y')
		{
			abs->m_size = 0;
			printf("联系人已清空！\n");
			break;
		}
		else if (clean == 'N' || clean == 'n')
		{
			break;
		}
		else
		{
			printf("无法识别指令！请重新输入！");
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
		//菜单
		system("cls");
		menu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			addPers(&abs);
			break;	
		case 2://2、显示联系人
			showPers(&abs);
			break;	
		case 3://3、查找联系人
			findPers(&abs);
			break;	
		case 4://4、删除联系人
			deletePers(&abs);
	    	break;
		case 5://5、修改联系人
			modifyPers(&abs);
			break;	
		case 6://6、清空联系人
			cleanPers(&abs);
			break;	
		case 0://0、保存并退出通讯录
			saveData(&abs);
			system("pause");
			return 0;
			break;
		default://其他情况
			printf("无此功能！\n");
			break;
		}
	}
}