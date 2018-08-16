print("Code Kitty v2.2 Booting")
from codekitty import *
print("Code Kitty v2.2 Ready!")
from time import sleep
beep()
while True:
    print("[CK] STOP")
    sleep(.5)
    while(touch.value==False):
        led("red")
    note("C4",8)
    note("E4",4)
    note("G4",2)
    while(touch.value==False):
        if(sensor.value<14000):
            print("[CK] STOP")
            stop()
            sleep(1)
            print("[CK] BACK")
            led("purple")
            back(.5,"slow")
            sleep(1)
            print("[CK] LEFT")
            led("blue")
            left(90)
            sleep(1)
        else:
            print("[CK] GO")
            go(.375,"slow")
            sleep(1)
            led("green")
    note("E5",8)
    note("A4",8)
    note("C5",4)
    note("G5",4)
    note("A4",2)







