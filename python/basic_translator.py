#Build a basic translator that converts any vowel to 'g'

phrase = input("Enter a phrase :")
translation = " "
phrase.lower()
for letter in phrase:
    if letter in "aeiou":
        translation = translation + "g"
    else:
        translation = translation + letter

print("translation: "+translation)

