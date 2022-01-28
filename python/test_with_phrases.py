phrase = input("Enter a phrase: ")

print(phrase.lower())

print(phrase.upper())

print("Length of the phrase is: "+ str(len(phrase))) #converting the value of length to string as string and int cannot be concatinated

print(phrase[5]) #prints the 6th character of the phrase

#index function tells us the location of the specific character in the phrase

print(phrase.index('f'))

phrase.replace("Giraffe","Elephant") 

print (phrase)

my_num = 5

#To print a number along with a string we need to first convert the number into a string

print(str(my_num)+" is my favourite number")


