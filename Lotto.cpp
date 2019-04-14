//���� : MatchingNum���� ������ ���� �� �Ű������� �Լ����� ��� �ѱ��Ǵ���? public���� private����������

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define NUM_SIZE 7

class Lottogenerator { //�ζǹ�ȣ�� �����ϴ� class
public:
	int Lotto_num[NUM_SIZE];
	Lottogenerator();
	void generateNum()
	{
		for (int i = 0; i < NUM_SIZE; i++)
		{
			Lotto_num[i] = rand() % 45 + 1;
		}
	}
	int RandBonus = Lotto_num[NUM_SIZE];
	void showLottoNum() //�ζǹ�ȣ�� �����ִ� �Լ�
	{
		generateNum();
		for (int i = 0; i < NUM_SIZE - 1; i++) //������������
		{
			for (int j = i + 1; j < NUM_SIZE; ++j)
			{
				if (Lotto_num[i] > Lotto_num[j])
				{
					int temp = Lotto_num[i];
					Lotto_num[i] = Lotto_num[j];
					Lotto_num[j] = temp;
				}
			}
		}
		for (int i = 0; i < NUM_SIZE; i++)
		{
			cout << Lotto_num[i] << "\t";
		}
	}

};

Lottogenerator::Lottogenerator() //������
{
	srand((unsigned)time(NULL));
}

class Userinput { //������ �Է��� ��ȣ �����ϴ� class
public:
	int input_num[NUM_SIZE];
	int UserBonus = input_num[NUM_SIZE];
	void userinput();
	void showInputNum()
	{
		for (int i = 0; i < NUM_SIZE; i++)
		{
			cout << input_num[i] << "\t";
		}
	}
};

void Userinput::userinput() {
	for (int i = 0; i < NUM_SIZE ; i++)
	{
		cin >> input_num[i];
	}
}

class LottoManage { //�ζǹ�ȣ�� ������ �Է¹�ȣ ��ġ
	int count = 0;
	Userinput *userNum;
	Lottogenerator *lottoNum;
public:
	int MatchingNum(Userinput*, Lottogenerator*);
	void showCount()
	{
		cout << count << "�� ���߼̽��ϴ�.\n" << endl;
	}
};

int LottoManage::MatchingNum(Userinput* userN, Lottogenerator *lottoN)
{
	for (int i = 0; i < NUM_SIZE - 1; i++)
	{
		for (int j = 0; j < NUM_SIZE - 1; j++)
		{
			if (userN->input_num[i] == lottoN->Lotto_num[j]) //�̺κ�
			{
				this->count++;
			}
		}
	}
	return this->count;
}

class winPrize { // ��÷
	int bonusNum;
	int prize;
	Lottogenerator *lottoNum;
	Userinput *userNum;
	LottoManage *m;
public:
	winPrize()
	{ 
		if (userNum->UserBonus == lottoNum->RandBonus)
			bonusNum = 1;
		else
			bonusNum = 0;
	}
	void getprize();
};

void winPrize::getprize()
{
	if (m->MatchingNum(userNum, lottoNum) == 6)
		cout << "1���Դϴ�!! \n*******��÷�� 3,421,706,750��*******\n";
	else if (m->MatchingNum(userNum, lottoNum) == 5 && bonusNum == 1)
		cout << "2���Դϴ�!! \n*******��÷�� 77,766,063��*******\n";
	else if (m->MatchingNum(userNum, lottoNum) == 5)
		cout << "3���Դϴ�!! \n*******��÷�� 1,834,696��*******\n";
	else if (m->MatchingNum(userNum, lottoNum) == 4)
		cout << "3���Դϴ�!! \n*******��÷�� 50,000��*******\n";
	else if (m->MatchingNum(userNum, lottoNum) == 3)
		cout << "3���Դϴ�!! \n*******��÷�� 5,000��*******\n";
	else
		cout << "�ƽ����ϴ�. ������ȸ�� �����ϼ���\n";
}
int main(void)
{
	Userinput user;
	Lottogenerator L;
	L.showLottoNum();
	cout << "7���� ���ڸ� �Է��ϼ���!! ��÷�� ����մϴ�(������ ��ȣ�� ���ʽ���ȣ�Դϴ�)" << endl;
	user.userinput();
	user.showInputNum();

	cout << "\nLotto ��÷ ��ȣ�� �����帳�ϴ�.\n";
	L.showLottoNum();
	cout << "\n ������ ��ȣ�� ���ʽ���ȣ�Դϴ�.\n";
	LottoManage M;
	M.showCount();
	winPrize money;
	money.getprize();

	system("pause");
}