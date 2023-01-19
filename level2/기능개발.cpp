//https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    // 작업을 배포하는 날짜 계산
    for(int i =0; i<progresses.size(); ++i){
        int res = 100 - progresses[i];
        if(res%speeds[i]!=0) res += speeds[i];
        q.push(res/speeds[i]);
    }

    // queue의 front는 맨 처음 들어간 값을 의미함
    // 위의 결과로 q = {9, 3, 7} 로 들어감
    // 7이 front값이고 9가 back 값이 됨
    // queue pop을 하게 되면 front값이 pop 됨
    // queue는 먼저 들어간 값이 먼저 나오는 구조
    
    while(!q.empty()){
        int cnt = 1;
        // front 값을 work 변수에 저장하고 pop시킴
        int work = q.front();
        q.pop();
        // 위의 결과로 work=7 front=3이 됨
        // queue가 빈값이 아니고 work>front일 경우 진행
        while(!q.empty() && work>=q.front()){
            cnt++;
            q.pop();
        }
        answer.push_back(cnt++);
    }
    
    return answer;
}

int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };

    solution(progresses, speeds);

    return 0;
}