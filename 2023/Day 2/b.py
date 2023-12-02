result = 0
input_string = input()

while input_string != "exit":
    largest = { "red": 0, "green": 0, "blue": 0 }

    for draw in input_string.split(":")[1].split(";"):
        values = draw.split(",")
        for value in values:
            temp = value.split()
            if largest[temp[1]] < int(temp[0]):
                largest[temp[1]] = int(temp[0])

    result += largest["blue"] * largest["green"] * largest["red"]

    input_string = input()

print(result)
