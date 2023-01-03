// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<string>
#include <iostream>
#include <stack>
using namespace std;

// 스택을 사용하지 않고 풀이
bool solution(string s)
{
    bool answer = true;
    
    // 괄호 체크에 대한 변수
    int cnt = 0;
    
    for(int i = 0; s[i]!='\0'; ++i){
        // 괄호가 열리면 증감
        if(s[i] == '(') cnt++;
        // 괄호가 닫히면 감소
        if(s[i] == ')') cnt--;

        // 괄호가 열리지 않고 닫히면 0보다 작음
        // 이때는 break로 반복문을 빠져나옴
        if(cnt<0) break;
    }
    
    // 괄호가 열리고 닫히면 cnt 값이 0이 되므로
    // 0이 아닐 때는 false를 출력
    if(cnt!=0) answer = false;

    return answer;
}

// 스택을 사용한 풀이
bool solution(string s)
{
    bool answer = true;

    // 스택 변수 초기화
    stack<char> s_stack;

    for (int i = 0; s[i] != '\0'; ++i) {
        // 스택이 비어있으면 값을 스택에 push
        if (s_stack.empty()) s_stack.push(s[i]);
        // 스택에 값이 있을 경우 
        else {
            // 스택의 top이 '('이며 s의 값이 ')'일 경우 pop 시킴
            if (s_stack.top() == '(' && s[i] == ')') s_stack.pop();
            // 그렇지 않을 경우 스택에 값을 넣음
            else s_stack.push(s[i]);
        }
    }

    // 스택이 비었을 때 true를 반환
    if (s_stack.size() == 0) return true;
    // 그렇지 않으면 false를 반환
    else return false;
}