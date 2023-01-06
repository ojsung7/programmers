// https://school.programmers.co.kr/learn/courses/30/lessons/12980

#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 1;

	while (n >= 2)
	{
		// 순간이동은 현재 위치 *2만큼 갈 수 있음
		// 즉 홀수가 되면 한칸 점프를 사용해야 함
		if (n % 2 == 0)
			n /= 2;
		else if (n % 2 != 0)
		{
			n = (n - 1) / 2;
			ans++;
		}
	}

	return ans;
}