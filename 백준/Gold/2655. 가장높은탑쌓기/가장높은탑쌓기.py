n = int(input())
arr = [(0,0,0,0)]
dp = [0] * (n + 1)

for i in range(1, n+1):
    a, h, w = map(int, input().split())
    # 인덱스 번호 출력을 위해 i값 같이 저장
    arr.append((i, a, h, w))

# 무게를 기준으로 정렬
arr.sort(key = lambda x:x[3])


for i in range(1, n+1):
    for j in range(0, i):
        # arr[i][1](현재 벽돌) 밑면의 길이가 arr[j][1](쌓여있는 벽돌)보다 크다면 통과  
        if arr[i][1] > arr[j][1]:
#             현재 높이와 지금까지 쌓은 높이 + 자기 자신의 높이중 높은 값으로 갱신
            dp[i] = max(dp[i], arr[i][2] + dp[j])

#  max_value 역추적해서 result 출력하기
max_value = max(dp)
index = n
result = []

while index != 0:
#     max_value 와 dp[index]가 같다면
    if max_value == dp[index]:
#         arr[index]의  인덱스 값 추가
        result.append(arr[index][0])
#        arr[index]값 추가 했으니 추가한 벽돌의 높이 값 빼기
        max_value = max_value - arr[index][2]
    index -= 1
    
# 가장 위부터 출력해야하기 때문에 reverse
result.reverse()
print(len(result))
[print(i) for i in result]