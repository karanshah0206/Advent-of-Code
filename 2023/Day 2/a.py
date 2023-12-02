result = 0
input_string = input()

while input_string != "exit":
    game = input_string.split(":")
    game_is_valid = True

    game_id = int(game[0].split()[1])
    draws = game[1].split(";")

    for draw in draws:
        limits = { "red": 12, "green": 13, "blue": 14 }

        values = draw.split(",")
        for value in values:
            temp = value.split()
            limits[temp[1]] -= int(temp[0])

        if limits["red"] < 0 or limits["blue"] < 0 or limits["green"] < 0:
            game_is_valid = False
            break

    if game_is_valid:
        result += game_id

    input_string = input()

print(result)
