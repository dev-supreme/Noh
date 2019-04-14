//질문 : MatchingNum에서 값들을 비교할 때 매개변수나 함수들을 어떻게 넘기면되는지? public말고 private으로했을때

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define NUM_SIZE 7

class Lottogenerator { //로또번호를 생성하는 class
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
	void showLottoNum() //로또번호를 보여주는 함수
	{
		generateNum();
		for (int i = 0; i < NUM_SIZE - 1; i++) //오름차순정렬
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

Lottogenerator::Lottogenerator() //생성자
{
	srand((unsigned)time(NULL));
}

class Userinput { //유저가 입력한 번호 저장하는 class
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

class LottoManage { //로또번호와 유저의 입력번호 매치
	int count = 0;
	Userinput *userNum;
	Lottogenerator *lottoNum;
public:
	int MatchingNum(Userinput*, Lottogenerator*);
	void showCount()
	{
		cout << count << "개 맞추셨습니다.\n" << endl;
	}
};

int LottoManage::MatchingNum(Userinput* userN, Lottogenerator *lottoN)
{
	for (int i = 0; i < NUM_SIZE - 1; i++)
	{
		for (int j = 0; j < NUM_SIZE - 1; j++)
		{
			if (userN->input_num[i] == lottoN->Lotto_num[j]) //이부분
			{
				this->count++;
			}
		}
	}
	return this->count;
}

class winPrize { // 당첨
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
		cout << "1등입니다!! \n*******당첨금 3,421,706,750원*******\n";
	else if (m->MatchingNum(userNum, lottoNum) == 5 && bonusNum == 1)
		cout << "2등입니다!! \n*******당첨금 77,766,063원*******\n";
	else if (m->MatchingNum(userNum, lottoNum) == 5)
		cout << "3등입니다!! \n*******당첨금 1,834,696원*******\n";
	else if (m->MatchingNum(userNum, lottoNum) == 4)
		cout << "3등입니다!! \n*******당첨금 50,000원*******\n";
	else if (m->MatchingNum(userNum, lottoNum) == 3)
		cout << "3등입니다!! \n*******당첨금 5,000원*******\n";
	else
		cout << "아쉽습니다. 다음기회에 도전하세요\n";
}
int main(void)
{
	Userinput user;
	Lottogenerator L;
	L.showLottoNum();
	cout << "7개의 숫자를 입력하세요!! 당첨을 기원합니다(마지막 번호는 보너스번호입니다)" << endl;
	user.userinput();
	user.showInputNum();

	cout << "\nLotto 당첨 번호를 보여드립니다.\n";
	L.showLottoNum();
	cout << "\n 마지막 번호는 보너스번호입니다.\n";
	LottoManage M;
	M.showCount();
	winPrize money;
	money.getprize();

	system("pause");
}