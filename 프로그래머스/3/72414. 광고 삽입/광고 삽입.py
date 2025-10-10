# 11:23
def to_sec(log):
    h,m,s = map(int, log.split(":"))
    return h*3600 + m*60 + s

def to_timelog(sec):
    h,m,s = sec//3600, sec%3600//60, sec%3600%60
    return "%02d:%02d:%02d" % (h,m,s)

def to_sec_range(s_e_log):
    start, end = s_e_log.split("-")
    return to_sec(start), to_sec(end)


def solution(play_time, adv_time, logs):
    answer = ''
    end_time = to_sec(play_time)
    running_time = to_sec(adv_time)
    
    # logs 30만, H1:M1:S1-H2:M2:S2 형식, 
    # 99:59:59까지 -> 100:00:00 미만 -> 100 * 60 * 60 == 360,000
    # 총 구간은 36만 초 미만
    
    # 핵심: 누적 재생시간이 가장 많이 나오는 곳 == 누적합
    
    sums = [0]*(end_time+2) # 0 ~ 100:00:00
    for log in logs:
        s,e = to_sec_range(log)
        sums[s] += 1
        sums[e] -= 1
    sums[-1] = 0
    
    play_sum = [0]*(end_time+2) # 누적 재생시간
    for i in range(end_time+1):
        sums[i] += sums[i-1]
        play_sum[i] = play_sum[i-1] + sums[i]
    play_sum[-1] = 0
    
    max_val = 0
    max_start_time = 0
    for ad_start in range(end_time+1):
        ad_end = ad_start + running_time
        if ad_end > end_time: # 광고가 재생시간 넘어가면 안됨
            break
        val = play_sum[ad_end-1] - play_sum[ad_start-1]
        if max_val < val:
            max_val = val
            max_start_time = ad_start
    
    # 광고 효율 제일 좋은것의 시작 시간, 그 중 더 빠른거
    print(max_start_time)
    answer = to_timelog(max_start_time)
    return answer