// https://school.programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;

	sort(routes.begin(), routes.end());

    // 차량이 들어오고 나가는 값을 저장
	int out = routes[0][1];
	for (auto a : routes) {
        // 선행차량이 나간 값보다 후행차량이 들어온값이 크면 카메라를 설치하고 out 값을 후행 차량 나가는 값으로 변경
		if (out < a[0]) {
			answer++;
			out = a[1];
		}
		
        // 선행차량이 나간 값이 후행차량이 나간값보다 크면 카메라 설치는 필요없고 out 값을 후행 차량 나가는 값으로 변경
		if (out >= a[1]) out = a[1];
	}

	return answer;
}