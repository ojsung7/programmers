def solution(sequence, k):
    answer = []
    return answer

print(solution([2, 2, 2, 2, 2], 6))

# 시간 초과로 인한 실패 소스
# def solution(sequence, k):
#     answer = []
#     result = []
#     index = 0
#     try:
#         a = sequence.index(k)
#         answer = [a,a]
#         return answer
#     except: pass
    
#     for i in range(0, len(sequence)):
#         # sum = sequence[i]
#         tmp = []
#         tmp.append(sequence[i])
#         for j in sequence[i+1:len(sequence)]:
#             tmp.append(j)
#             if sum(tmp) == k:
#                 tmp.append(i) # index 넣어주기
#                 result.append(tmp)
#                 break

#     result.sort(key=len)

#     tmp = result[0]
#     tmp_len = len(tmp)
#     answer = [tmp[-1], tmp[-1]+(tmp_len-2)]

#     return answer