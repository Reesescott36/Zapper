import serial.tools.list_ports
import serial
import time
#from RelaySerial import RelaySerial
import librosa
audio_file = librosa.load('crab_rave.wav')
y, sr = audio_file
tempo, beat_frames = librosa.beat.beat_track(y=y, sr=sr)
print('Estimated tempo: {:.2f} beats per minute'.format(tempo))

tempoInt = int(tempo)
tempoOut = str(tempoInt)
print(tempoOut)
i = 0

def sendInfo(state:str,): #o, open c close, s status
    print("sending: " + state)
    ardConnect.write(bytes(state, 'utf8'))
    time.sleep(.2)
    print(ardConnect.readline())



ports = list(serial.tools.list_ports.comports())
print(ports)

for p in ports:
    print(p.device)
    ardConnect = serial.Serial(port = p.device, baudrate = 115200, timeout=.25)
    print("Making ESP Port")




if(ports):
    while True:
        test = input("test: ")
        if(test == "1"):
            sendInfo("1")
        elif(test == "0"):
            sendInfo("0")
        elif(test == "C"):
            sendInfo(tempoOut)
        else:
            print("Enter a test character")