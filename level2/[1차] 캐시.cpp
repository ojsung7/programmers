// https://school.programmers.co.kr/learn/courses/30/lessons/17680

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    // 캐시로 사용할 벡터 초기화
    // 가장 덜 최근에 사용된 값은 캐시의 맨 마지막에 위치함
    vector<string> cache;
    int answer = 0;

    // 캐시 사이즈가 0일 경우 모두 miss 처리함
    if (cacheSize == 0)
        return cities.size() * 5;

    for (int i = 0; i < cities.size(); ++i)
    {
        // 대문자를 모두 소문자로 치환함
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        // 캐시에 이미 값이 존재할 경우, 즉 hit일 경우
        if (find(cache.begin(), cache.end(), cities[i]) != cache.end())
        {
            // 사용이 되었으므로 캐시에서 값을 삭제하고
            cache.erase(remove(cache.begin(), cache.end(), cities[i]), cache.end());
            // 캐시의 맨 앞쪽에 위치시킴
            cache.insert(cache.begin(), cities[i]);
            // hit 값을 증감
            answer += 1;
        }

        // 캐시에 값이 없을 경우, 즉 miss일 경우
        else
        {
            // 캐시가 꽉 찾을 경우 맨 뒤에 값을 삭제
            if (cache.size() == cacheSize)
            {
                cache.erase(cache.end() - 1);
            }
            // 캐시 맨 앞에 값을 위치 시킴
            cache.insert(cache.begin(), cities[i]);
            // miss 값을 증감
            answer += 5;
        }
    }

    return answer;
}