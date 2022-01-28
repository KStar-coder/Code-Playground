#Build a word guessing game

secret_word = "Apple"
guesses = 3
count = 0

guessed_word = " "

print("*****************HINT : Relate Steve Jobs and doctors *******************")

while guessed_word != secret_word and count< guesses :
    
     guessed_word = input("Enter the guessed word: ")
     count+= 1
if guessed_word == secret_word:
     print("HURRAH! YOU WON!")
else:
     print("Out of guesses, YOU LOOSE!")
    
