// https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>

using namespace std;

// 최대 컴퓨터 개수는 200개
int check[200];

void dfs(int current_computer, int n, vector<vector<int>> computers)
{
    // 한번이라도 방문했으면 1로 세팅
    check[current_computer] = 1;

    for (int i = 0; i < n; i++)
    {
        // 아직 방문하지 않았고 연결된 선이 있다면 재귀함수 실행
        if (check[i] == 0 && computers[current_computer][i] == 1)
            dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        // 방문한 적이 없는 경우에 실행
        if (check[i] == 0)
        {
            dfs(i, n, computers);

            answer++;
        }
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    solution(n, computers);

    return 0;
}