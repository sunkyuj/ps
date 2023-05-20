class Number:
    def __init__(self,string_n):
        self.string_n = string_n

    def __lt__(self, other):
        return self.string_n+other.string_n < other.string_n+self.string_n

    def __le__(self, other):
        return self.string_n+other.string_n <=other.string_n+ self.string_n

    def __gt__(self, other):
        return self.string_n+other.string_n > other.string_n+self.string_n

    def __ge__(self, other):
        return self.string_n+other.string_n <=other.string_n+ self.string_n

    def __eq__(self, other):
        return self.string_n+other.string_n ==other.string_n+ self.string_n
    
def solution(numbers):
    answer = ''
    snums = list(map(str,numbers))
    snums = list(map(Number,snums))
    snums.sort(reverse=1)
    for snum in snums:
        answer += snum.string_n
#     for snum in snums:
#         d[snum[0]].append(Number(snum)) # mod, org
        
#     for i in range(9,-1,-1):
#         d[str(i)].sort(key=lambda x:(-x[0],len))
#         print(d[str(i)])
#         for mod,org in d[str(i)]:
#             answer += org
    return answer

"""

35 34 3 3331 32 31 30

67 6667 6 65 64 63


"""



