// https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
   int answer = -1;
   
   // 스택 초기화
   stack<int> s_stack;

    for(int i = 0; i<s.size(); ++i) {
        // 스택이 비어있거나 스택 top과 현재 문자가 다르면 스택에 push 함
        // 스택 top과 현재 문자가 다르다는 것은 aa, bb와 같이 반복되지 않는다는 의미
        if (s_stack.empty() ||  s_stack.top() != s[i]) s_stack.push(s[i]);
        else if (s_stack.top() == s[i]) s_stack.pop();
    }

    // 스택 사이즈가 0일 경우 answer를 1로 셋팅
    if (s_stack.size() == 0) answer = 1;
    // 스택 사이즈가 0이 아닐 경우 answer를 0로 셋팅
    else if (s_stack.size() > 0) answer = 0;

    return answer;
}