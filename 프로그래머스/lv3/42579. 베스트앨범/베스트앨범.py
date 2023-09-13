from collections import defaultdict

def solution(genres, plays):
    answer = []
    
    gen_play = defaultdict(int)
    gen_idx_play = defaultdict(list)
    
    for i in range(len(genres)):
        genre = genres[i]
        play = plays[i]
        gen_play[genre]+=play
        gen_idx_play[genre].append((i,play))
    
    gen_keys=sorted(gen_play.items(),key=lambda x: -x[1])
    print(gen_keys)
    for gen,play in gen_keys:
        li = gen_idx_play[gen]
        li.sort(key=lambda x: (-x[1],x[0]))
        print(li)
        for idx,play in li[:min(2,len(li))]:
            answer.append(idx)
    
    return answer