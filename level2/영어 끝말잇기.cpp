// https://school.programmers.co.kr/learn/courses/30/lessons/12981

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    // 라운드 값 초기화
    int round = 1;
    // 플레이어 값 초기화
    // 2인 이유는 첫 번째 플레이어가 탈락할 경우는 없기 때문에 2부터 시작
    int player = 2;
    
    vector<int> answer = {0, 0};

    for(int i = 1; i<words.size(); i++){
        int check = 0;
        
        // 현재 단어를 이전에 사용했는지 체크
        for(int j = 0; j<i; j++){
            if(words[i] == words[j]) check++;
        }
        
        // 끝말잇기가 맞는지에 대한 체크
        if(words[i-1][words[i-1].size() -1] != words[i][0]) check++;
        
        // 체크값이 하나라도 있으면 규칙에 위배되므로
        // 플레이어, 라운드 값을 answer에 넣고 break함
        if(check>0){
            answer.clear();
            answer.push_back(player);
            answer.push_back(round);
            break;
        }
        
        // 현재 플레이어가 총 플레이어의 값이 되면 1로 바꿈
        if(player==n) player = 1;
        // 그렇지 않으면 플레이어 증감
        else player++;
        
        // 맨 마지막 사람이면 라운드를
        if((i+1)%n==0) round++;
    }
    return answer;
}