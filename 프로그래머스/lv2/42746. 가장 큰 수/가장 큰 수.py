class Number:
    def __init__(self,string_n):
        self.string_n = string_n

    def __lt__(self, other):
        return self.string_n+other.string_n < other.string_n+self.string_n

    def __eq__(self, other):
        return self.string_n+other.string_n ==other.string_n+ self.string_n
    
def solution(numbers):
    answer = ''
    snums = list(map(str,numbers))
    snums = list(map(Number,snums))
    snums.sort(reverse=1)
    for snum in snums:
        answer += snum.string_n
    answer = answer.lstrip('0')
    return answer if answer else '0'
