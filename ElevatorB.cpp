#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#define N 5
using namespace std;
int sum = 0, a[15][2] = { 0 }, max1, time = 0, wait = 0; // 时间总和 不同楼层等待人数
string s1, s4;
class node
{
public:
	int time, pos, des; // 时间，位置，目的地
	friend istream &operator>> (istream &is, node &qwe);// 重载>>运算符
}per[100];
istream &operator>> (istream &is, node &qwe)
{
	is >> qwe.time >> qwe.pos >> qwe.des;
	if (!is)qwe = node();
	return is;
}
struct qwe
{
	int pos, ans[2], dic; //电梯位置 人数 方向0代表停 1代表向下 2 代表向上
}Ele;
void Eleva(int t, string s, int &pos, int &an1, int &an2,int &wait)
{
	int j = 0, n = s.size(), t1, s1;
	for (int i = time; i < t&& j < n; i++, j++)
	{
		t1 = 0;
		if (s[j] == '2')
		{
			if (pos == 10) t1 = an2, an2 = 0, an1 += a[pos][1];
			else if (pos==1) t1 = an1, an1=0, an2 += a[pos][0];
			else an1 += a[pos][1], an2 += a[pos][0];
			s1 = a[pos][0] + a[pos][1];
			a[pos][0] = 0; a[pos][1] = 0;
			wait -= s1;
			printf("%d 时，停靠在%d楼: 进电梯  %d人，出电梯 %d人。\n", i, pos, s1, t1);
		}
		else
		{
			if (s[j] == '1') pos++;
			else pos--;
		}
		sum += wait + an1 + an2;
		s4 += s[j];
	}
	time = t;
}
void dfs(int po, int an1, int an2, string s,int ans,int wait) //参数分别代表：电梯位置 电梯中去1楼人数 去10楼人数 电梯运作过程 
{                                                             // 总耗时 电梯外等待人数
	int i;
	if (!an1 && !an2 && !wait)
	{
		if (ans < max1)
		{
			s1 = s;
			max1 = ans;
		}
	}
	else
	{
		string s2(po - 1, '0'), s3(10 - po, '1');
		if (an1 > 0) dfs(1, 0, an2 + a[1][0], s + s2+ '2', ans + (po - 1)*(wait + an1 + an2), wait);  // 直接送乘客去1楼
		if (an2 > 0) dfs(10, an1 + a[10][1], 0, s + s3 + '2', ans + (10 - po) * (wait + an1 + an2), wait); // 直接送乘客去10楼
		for (i = 1; i <= 10; i++)              // 去i 楼载乘客入电梯
			if (a[i][0]>0 || a[i][1]>0)
			{
				char c;
				if (po == i) c = '2';
				else   c = (i < po) ? '0' : '1';
			
					int t = abs(i - po), t1 = a[i][1], t2 = a[i][0];
					string s2(t, c);
					a[i][1] = 0; a[i][0] = 0;
					dfs(i, an1 + t1, an2 + t2, s + s2 + '2', ans + (t + 1)*(wait + an1 + an2), wait - t1 - t2);
					a[i][1] = t1; a[i][0] = t2;
			}
	}
}
int main()
{
	int man = 1;
	for (int i = 1; i <= N; i++) cin >> per[i];
	per[N + 1].time = per[N].time + 100;
	Ele.pos = 1; Ele.ans[0] = 0;
	Ele.ans[1] = 0; Ele.dic = 0;
	wait = 0;
	
	time = per[1].time;

	while ( man<=N)
	{
		int k = man;
		while (time >= per[man].time)	a[per[man++].pos][per[man].des]++;
		int t = per[man].time;
		string s;
		max1 = 0xfffff; wait += man - k;
		dfs(Ele.pos, Ele.ans[0], Ele.ans[1], s, 0, wait);
		Eleva(t, s1, Ele.pos, Ele.ans[0], Ele.ans[1], wait);
		
	}
	cout << "总耗时： "<<sum << endl<< s4 << endl;
	return 0;
}