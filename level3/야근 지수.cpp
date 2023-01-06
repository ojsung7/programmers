// https://school.programmers.co.kr/learn/courses/30/lessons/12927
// 해당 문제의 기본적인 이론은 정렬 후 n만큼 while문을 실행하고 최대값에서 -1을 수행한 다음 야근 지수를 구해야겠다고 판단함

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 성공한 문제풀이 법
long long solution(int n, vector<int> works)
{
    long long answer = 0;

    // 우선순위 큐 선언(최대값이 pop으로 항상 셋팅된다)
    priority_queue<int> q;

    // 큐에 넣는 작업
    for (auto tmp : works)
        q.push(tmp);

    while (n > 0 && !q.empty())
    {
        int tmp = q.top();
        q.pop();
        n--;

        // 최대값에서 -1을 계산
        if (tmp > 0)
            q.push(tmp - 1);
    }

    // 야근 지수를 구하는 부분
    while (!q.empty())
    {
        answer += (q.top() * q.top());
        q.pop();
    }

    return answer;
}

// 호율셩 실패 문제풀이
long long solution(int n, vector<int> works)
{
    long long answer = 0;

    while (n > 0)
    {
        // 내림차순으로 정렬
        sort(works.rbegin(), works.rend());
        // 1도 포함한 이유는 나중에 피로도 계산할 때 0을 계산하기 위해서이다.
        if (works[0] > 0)
            works[0] -= 1;
        n--;
    }

    for (int i = 0; i < works.size(); ++i)
    {
        answer += works[i] * works[i];
    }

    return answer;
}
// 해당 문제가 실패한 이유는 시간복잡도 차이 때문이다
// sort(NlogN), priority queue(log N) 이기 때문에 priority queue에서 효율성이 더 좋다


int main()
{
    vector<int> works = {1, 1};
    int n = 3;

    cout << solution(n, works);

    return 0;
}