def include(r):
    dots = 0
    r2 = r**2
    for x in range(r+1):
        x2 = x**2
        y2 = r2-x2
        y = y2**0.5
        dots+= int(y) +1
    return dots

def exclude(r):
    dots = 0
    r2 = r**2
    for x in range(r+1):
        x2 = x**2
        y2 = r2-x2
        y = y2**0.5
        if y==int(y):
            y-=1
        dots += int(y) +1
    return dots
    
def solution(r1, r2):
    answer = 0
    print(include(r2))
    print(exclude(r1))
    print(r2-r1+1)
    q = include(r2) - exclude(r1) - (r2-r1+1)
    
    return q*4