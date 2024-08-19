coin = [25, 10, 5, 1]

value = 0;
while value <= 0:
    try:
        value = float(input("Change: "))*100
    except:
        print("Erro")

total = 0;
index = 0;

while value > 0:
    if (value - coin[index]) >= 0:
        value -= coin[index]
        total += 1
    else:
        index += 1

print(total)

