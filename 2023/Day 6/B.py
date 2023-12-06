time = int("".join(input().split(":")[1].split()))
dist = int("".join(input().split(":")[1].split()))
count = 0

for charging_time in range(time + 1):
    if (charging_time * (time - charging_time)) > dist:
        count += 1

print(count)
