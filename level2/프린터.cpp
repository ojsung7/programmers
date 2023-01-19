// https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//실패한 문제풀이
int solution(vector<int> priorities, int location) {
	int answer = location+1;


	for (int i = 0; i < priorities.size(); ++i) {
		// 맨 처음값을 now 변수에 저장
		int now = priorities[0];
		int check = 0;

		// 맨 앞에 값이랑 모든 우선순위 값을 비교하여 크면 check 값 증감
		for (auto priority : priorities) {
			if (priority > now) check++;
		}

		// check 값이 0보다 크면 맨앞에 값 삭제 후 now 값을 맨 뒤로 이동
		if (check > 0) {
			priorities.erase(priorities.begin() + 0);
			priorities.push_back(now);
			// location 값이 0보다 크면 감소 시킴
			// 그렇지 않으면 총 size 값에서 -1을 하고 저장
			// index를 체크하기 위함
			if (location > 0) location--;
			else location = priorities.size() - 1;
		}
	}

	answer = location + 1;
	return answer;
}

int solution(vector<int> priorities, int location) {
	int answer = 0;
	return answer;
}

int main() {
	vector<int> priorities = { 2,1,3,2 };
	int location = 2;

	solution(priorities, location);

	return 0;
}