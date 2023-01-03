// https://school.programmers.co.kr/learn/courses/30/lessons/76502

#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int end_check = 0, answer = 0;
    // 괄호가 열렸는지 체크
	bool flag = false;

	// 스택 초기화
	stack<char> stack;

	// s의 길이만큼 반복문 실행
	while (s.length() != end_check) {
		flag = false;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
				stack.push(s[i]);
                // 괄호가 열렸음을 확인
				flag = true;
			}
            // 괄호가 열리고 그 이후에 닫혔는지 확인
			else {
				if (!stack.empty() && stack.top() == '[' && s[i] == ']') stack.pop();
				if (!stack.empty() && stack.top() == '(' && s[i] == ')') stack.pop();
				if (!stack.empty() && stack.top() == '{' && s[i] == '}') stack.pop();
			}
		}

		// 괄호가 한번이라도 열렸고 stack이 비었을 때 증감
        // 스택이 비었다는 것은 괄호가 올바르다는 의미
		if (stack.size() == 0 && flag) answer++;

		// 맨 앞의 문자를 맨 뒤로 옮김
		char rotate = s[0];
		s.erase(0, 1);
		s.push_back(rotate);

		// while문 종료를 위한 증감
		end_check++;

		// 스택을 비움
		while (!stack.empty()) stack.pop();
	}
    return answer;
}