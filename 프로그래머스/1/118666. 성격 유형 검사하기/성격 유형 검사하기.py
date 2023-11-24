from collections import defaultdict
def solution(survey, choices):
    answer = ''
    """
    RT CF JM AN
    """
    d = defaultdict(int)
    n = len(survey)
    for i in range(n):
        l,r = survey[i][0], survey[i][1]
        score = choices[i] - 4
        if score>0:
            d[r]+=score
        else:
            d[l]+=abs(score)
    answer += ("R" if d["R"] >= d["T"] else "T")
    answer += ("C" if d["C"] >= d["F"] else "F")
    answer += ("J" if d["J"] >= d["M"] else "M")
    answer += ("A" if d["A"] >= d["N"] else "N")
    return answer