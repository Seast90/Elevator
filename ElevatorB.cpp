#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#define N 5
using namespace std;
int sum = 0, a[15][2] = { 0 }, max1, time = 0, wait = 0; // ʱ���ܺ� ��ͬ¥��ȴ�����
string s1, s4;
class node
{
public:
	int time, pos, des; // ʱ�䣬λ�ã�Ŀ�ĵ�
	friend istream &operator>> (istream &is, node &qwe);// ����>>�����
}per[100];
istream &operator>> (istream &is, node &qwe)
{
	is >> qwe.time >> qwe.pos >> qwe.des;
	if (!is)qwe = node();
	return is;
}
struct qwe
{
	int pos, ans[2], dic; //����λ�� ���� ����0����ͣ 1�������� 2 ��������
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
			printf("%d ʱ��ͣ����%d¥: ������  %d�ˣ������� %d�ˡ�\n", i, pos, s1, t1);
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
void dfs(int po, int an1, int an2, string s,int ans,int wait) //�����ֱ��������λ�� ������ȥ1¥���� ȥ10¥���� ������������ 
{                                                             // �ܺ�ʱ ������ȴ�����
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
		if (an1 > 0) dfs(1, 0, an2 + a[1][0], s + s2+ '2', ans + (po - 1)*(wait + an1 + an2), wait);  // ֱ���ͳ˿�ȥ1¥
		if (an2 > 0) dfs(10, an1 + a[10][1], 0, s + s3 + '2', ans + (10 - po) * (wait + an1 + an2), wait); // ֱ���ͳ˿�ȥ10¥
		for (i = 1; i <= 10; i++)              // ȥi ¥�س˿������
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
	cout << "�ܺ�ʱ�� "<<sum << endl<< s4 << endl;
	return 0;
}