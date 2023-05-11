def f(seq):
    # print(seq)
    dp = [0]*len(seq)
    dp[0] = seq[0]
    for i in range(1,len(seq)):
        dp[i] = max(dp[i-1] + seq[i] , seq[i])
    
    return max(dp)

def solution(sequence):
    n=len(sequence)
    seq1,seq2 = sequence[:], sequence[:]
    for i in range(n):
        if i%2:
            seq1[i]*=-1
        else:
            seq2[i]*=-1
    
    return max(f(seq1),f(seq2))