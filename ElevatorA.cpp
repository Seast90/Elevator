//#include <iostream>
//#include <cstdio>
//#define N 5
//using namespace std;
//int sum = 0, a[15][2] = { 0 }; // ʱ���ܺ� ��ͬ¥��ȴ�����
//class node
//{
//public:
//	int time, pos, des; // ʱ�䣬λ�ã�Ŀ�ĵ�
//	friend istream &operator>> (istream &is, node &a);// ����>>�����
//}per[100];
//istream &operator>> (istream &is, node &a)
//{
//	is >> a.time >> a.pos >> a.des;
//	if (!is) a = node();
//	return is;
//}
//struct a
//{
//	int pos, ans[2], dic; //����λ�� ���� ����0����ͣ 1�������� 2 ��������
//}Ele;
//void Elevator(int time,  int man,int wait) //��ʱ�� ��ǰ�ڼ�λ�˿� �ȴ����� Ϊ��������
//{
//	int k = man;
//	while (time >= per[man].time)	a[per[man++].pos][per[man].des]++;
//	if (k == man)
//	{
//		sum += wait;
//		if (!Ele.dic)  Elevator(time++, man, wait);
//		else 
//		{
//			if (Ele.dic == 1 && Ele.pos != 1 || Ele.dic == 2 && Ele.pos != 10)
//			{
//				if (Ele.dic == 1) Ele.pos--;
//				else Ele.pos++;			
//			}
//			else
//			{
//				int t;
//				if (Ele.pos == 10) t = 1;
//				else t = 0;
//				wait -= Ele.ans[t];
//				sum -= Ele.ans[t];
//				Ele.ans[t] = 0;
//			}
//			Elevator(time++, man, wait);
//		}
//	}
//	else // �����������  ̰��
//	{
//		wait += man - k;
//
//	}
//}
//int main()
//{
//	for (int i = 1; i <= N; i++) cin >> per[i];
//	Ele.pos = 1; Ele.ans[0] = 0;
//	Ele.ans[1] = 0; Ele.dic = 0;
//	Elevator(0, 1, 0);
//	return 0;
//}