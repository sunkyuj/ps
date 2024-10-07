def lru(cache):
    items = list(cache.items())
    items.sort(key=lambda x: x[1])
    del cache[items[0][0]]
    
def solution(cacheSize, cities):
    answer = 0
    day = 0 
    cache = {}
    for city in cities:
        city = city.lower()
        day += 1
        if city in cache:
            answer+=1
        else:
            answer+=5
        cache[city] = day
        if len(cache) > cacheSize:
            lru(cache)
    return answer