INIT = 540

def ok(minute, n, t, m, crews):
    crews.sort()
    
    bus_time = [ INIT + t*i for i in range(n)]
    buses = [[] for _ in range(n)]
    
    ci = 0
    for bi in range(n): 
        limit = bus_time[bi]
    
        # limit 전에 있는 애들 최대 m만큼 채움
        while len(buses[bi]) < m and ci < len(crews): # 버스 꽉차면 탈출 or 크루 다타면 끝
            if crews[ci] > limit: # 이번 크루는 출발 이후임
                break
            buses[bi].append(crews[ci])
            ci+=1

    if ci == len(crews): # 다 탔음
        return 1
    if crews[ci] > minute: # 처음 못탄놈이 나보다 늦게옴
        return 1
    return 0

def solution(n, t, m, timetable):
    answer = ''
    # 셔틀은 09:00 부터 역에 도착함, n번 운행하고, 간격은 t
    # n: 셔틀 운행 횟수 
    # t: 셔틀 운행 간격 
    # m: 한 셔틀에 탈 수 있는 최대 크루 수
    # timetable: 다른 크루들 도착하는 시각 (같은 시각이라면 제일 후순위로 감)
    global crews
    
    crews = []
    for tt in timetable:
        h,mi = map(int, tt.split(":"))
        crews.append((h*60+mi))
    
    # 최초 9시 출발 == 540
    
    # 540 이후부터 n번, t 간격으로 m명 실어감

    for time in range(24*60-1, -1, -1):
        if ok(time, n, t, m, crews + [time]):
            h,mi = str(time//60), str(time%60)
            if len(h) == 1:
                h = "0"+h
            if len(mi) == 1:
                mi = "0"+mi
            return h+":"+mi 

    # 마지막 열차 무사히 타기위해 콘이 가장 늦게 기어나오는 시간

    return answer
