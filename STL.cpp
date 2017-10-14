#include <iostream>
#include <Vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <map>
#include <deque>

#include "string"
#include "set"
#include "iterator"
#include "functional"

using namespace std;

class Speaker
{
public:

	string m_name;
	int    m_score[3];
};

int genSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());

	for (int i = 0; i < 24; i++)
	{
		Speaker tmp;
		tmp.m_name   = "选手";
		tmp.m_name   = tmp.m_name + str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));
	}

	for (int i = 0; i < 24; i++)
	{
		v.push_back(100 + i);
	}

	return 0;

}

//选手抽签
int speechContest(vector<int> &v)
{ 
	random_shuffle(v.begin(), v.end());
	return 0;
}

//选手比赛
int speechContestScore(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
	multimap<int, int, greater<int>> multimapGroup;
	int tmpCount = 0;

	for (vector<int>::iterator ite = v1.begin(); ite != v1.end(); ite++)
	{
		tmpCount++;
		//打分
		{
			deque<int> dscore;
			for (int j = 0; j < 10; j++)
			{
				int score = 50 + rand() % 50;
				dscore.push_back(score);
			}
			sort(dscore.begin(), dscore.end());
			dscore.pop_back();
			dscore.pop_front();

			//求平均分
			int scoreSum = accumulate(dscore.begin(), dscore.end(), 0);
			int scoreAvg = scoreSum / dscore.size();

			mapSpeaker[*ite].m_score[index] = scoreAvg;
			multimapGroup.insert(pair<int, int>(scoreAvg, *ite));
		}

		if (tmpCount % 6 == 0)
		{
			cout << "小组成绩：" << endl;

			for (multimap<int, int, greater<int>>::iterator mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++)
			{
				cout << mit->second << "\t" << mapSpeaker[mit->second].m_name << "\t" << mit->first << endl;
			}

			//前三名晋级
			while (multimapGroup.size() > 3)
			{
				multimap<int, int, greater<int>>::iterator ite1 = multimapGroup.begin();
				v2.push_back(ite1->second);
				multimapGroup.erase(ite1);
			}
		}
	}
	return 0;
}

//选手结果
int speechContestPrint(int index, vector<int> &v, map<int, Speaker> &mapSpeaker)
{
	printf("第%轮 晋级名单\n", index);
	for (vector<int>::iterator ite = v.begin(); ite != v.end(); ite++)
	{
		cout << "参赛编号：" << *ite << "\t" << mapSpeaker[*ite].m_name << "\t" << mapSpeaker[*ite].m_score[index] << endl;
	}

	return 0;
}

void main(void)
{
	//容器的设计
	map<int, Speaker>   mapSpeaker;
	vector<int>			v1;
	vector<int>			v2;
	vector<int>			v3;
	vector<int>			v4;

	//产生选手的比赛名单
	genSpeaker(mapSpeaker, v1);

	speechContest(v1);
	speechContestScore(0, v1, mapSpeaker, v2);
	speechContestPrint(0, v2, mapSpeaker);

	speechContest(v2);
	speechContestScore(1, v2, mapSpeaker, v3);
	speechContestPrint(1, v3, mapSpeaker);

	speechContest(v3);
	speechContestScore(2, v3, mapSpeaker, v4);
	speechContestPrint(2, v3, mapSpeaker);

	system("pause");
	return;
}
