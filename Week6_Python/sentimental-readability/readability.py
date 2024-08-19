text = input("Text: ")

letters = sum(1 for letters in text if letters.isalpha())
words = len(text.split())
sentences = sum(1 for letters in text if letters in '.?!')

grade = 0.0588 * ((letters / words) * 100) - 0.296 * ((sentences / words) * 100) - 15.8
grade = round(grade)

print(grade)

if grade > 1 and grade < 16:
    print(f"Grade {grade}")
elif grade > 16:
    print("Grade 16+")
else:
    print("Before Grade 1")

