height = 0
while height < 1 or height > 8:
    try:
        height = int(input("Height: "))
    except:
        print("Erro")

for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i + "  " + "#" * i)

