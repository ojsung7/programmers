// https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 실패한 문제풀이
// 실패한 이유가 값을 비교하고 현재 값이 제일 큰값이면 vector에서 삭제해줘야함
int solution(vector<int> priorities, int location) {
	int answer = 0;
	int cnt = 0;


	for (int i = 0; i < priorities.size(); ++i) {
		// 맨 처음값을 now 변수에 저장
		int now = priorities[0];
		int check = 0;

		// 맨 앞에 값이랑 모든 우선순위 값을 비교하여 크면 check 값 증감
		for (auto priority : priorities) {
			if (priority > now) {
				check++;
			}
		}

		if (check == 0) {
			priorities[i] = 0;
		}
		// check 값이 0보다 크면 맨앞에 값 삭제 후 now 값을 맨 뒤로 이동
		else if (check > 0) {
			priorities.erase(priorities.begin() + 0);
			priorities.push_back(now);
			location--;
		}

	}
	if (location < 0) answer = location + priorities.size() + 1;
	else answer = location+1;

	return answer;
}

// 성공한 문제 풀이
// 구조체를 만들어서 위치값도 같이 저장함
struct PrintJob{
	int priority;
	int location;
};

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<PrintJob> printer;

	// queue에 저장하면서 index 값도 미리 지정
	for (int i = 0; i < priorities.size(); i++) {
		PrintJob job;
		job.location = i;
		job.priority = priorities[i];
		printer.push(job);
	}

	while (!printer.empty()) {
		//ㅍ
		PrintJob job = printer.front();
		printer.pop();

		if (job.priority < *max_element(priorities.begin(), priorities.end())) {
			printer.push(job);
		}
		else {
			answer++;
			// 원하는 location이면 종료
			if (job.location == location) break;
			// 프린트 완료
			priorities[job.location] = 0;
		}
	}

	return answer;
}


int main() {
	vector<int> priorities = { 1,1,9,1,1,1 };
	int location = 0;

	cout << solution(priorities, location);

	return 0;
}