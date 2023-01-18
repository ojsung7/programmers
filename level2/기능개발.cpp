//https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
        int res = 100 - progresses[i];
        if(res / speeds[i])
        cout << res / speeds[i] << endl;
    }

    return answer;
}

int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1,15,5 };

    solution(progresses, speeds);

    return 0;
}