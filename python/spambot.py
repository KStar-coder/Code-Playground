import time
import pyautogui
time.sleep(10)

file = open ("beemovie.txt ",'r')
for word in file:
    pyautogui.typewrite(word)
    pyautogui.press("enter")