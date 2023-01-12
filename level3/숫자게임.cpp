// https://school.programmers.co.kr/learn/courses/30/lessons/12987

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

    // 미리 sort하여 정렬한다.
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

    // A의 index를 선언하고 해당 B가 이겼을 경우 A의 index를 옮긴다.
	int A_idx = 0;
	for (int i = 0; i < B.size(); ++i) {
		if (B[i] > A[A_idx]) {
			answer++;
			A_idx++;
		}
	}

	return answer;
}

int main() {
	vector<int> A = { 5,1,7,3 };
	vector<int> B = { 2,2,6,8 };

	cout << solution(A, B);

	return 0;
}