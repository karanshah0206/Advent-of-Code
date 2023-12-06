time_list = list(map(int, input().split(":")[1].split()))
dist_list = list(map(int, input().split(":")[1].split()))
res = 1

for index, time in enumerate(time_list):
    count = 0
    for charging_time in range(time + 1):
        if (charging_time * (time - charging_time)) > dist_list[index]:
            count += 1
    res *= count

print(res)
