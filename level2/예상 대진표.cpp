// https://school.programmers.co.kr/learn/courses/30/lessons/12985

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer;

	for (answer = 1; answer < n; ++answer) {
        // 어느 라운드에서 만나는지 확인할려면 무조건 이겨야함
        // 현재라운드에서 2를 나누면 다음 라운드의 배정 번호가 됨
        // 홀수인 경우 증감시켜서 2를 나누면 다음 라운드의 배정 번호가 됨
		if (a % 2 != 0) a++;
		if (b % 2 != 0) b++;

		a /= 2;
		b /= 2;		

		if (a == b) break;
	}
    
    return answer;
}