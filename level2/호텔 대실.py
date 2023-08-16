# https://school.programmers.co.kr/learn/courses/30/lessons/155651
# 해결 못 함 (2023-08-16)

def solution(book_time):
    sorted = []
    for i in book_time:
        tmp = []
        for j in i:
            h = int(j.split(':')[0])*60
            m = int(j.split(':')[1])
            tmp.append(h+m)
        sorted.append(tmp)
    sorted.sort(key=lambda x:x[0])

    rooms = []
    for room in sorted:
        check = False

        for check_room in rooms:
                if room[0] >= check_room[1]+10:
                    check = True
                    break
        
        if check == False: rooms.append(room)

    print(rooms)

    return 0

solution([["08:00", "08:30"], ["08:00", "13:00"], ["12:30", "13:30"]])