// https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    // sort 함수를 이용해서 오름차순으로 정렬
    sort(people.begin(), people.end());
	
	int answer = 0;
	int i = 0;

	while(i < people.size()) {
        // 맨 마지막 값을 저장
		int tmp = people.back();
        // 맨 마지막 값을 삭제함
		people.pop_back();

        // 정렬이 되어 있으므로
        // 제일 작은 값과 제일 큰 값을 더한 값이 limit 보다 크거나 작은지 판단
        // 만약 충족 한다면 제일 작은 값과 제일 큰값이 제한에 만족하는 것이고 그 다음으로 작은 값과 큰값으로 다시 비교함
		if (people[i] + tmp <= limit) {
			i++;
			answer++;
		}
		else {
			answer++;
		}
	}
    
    return answer;
}