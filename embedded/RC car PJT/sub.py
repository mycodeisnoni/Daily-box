from Raspi_PWM_Servo_Driver import PWM
from Raspi_MotorHAT import Raspi_MotorHAT, Raspi_DCMotor

import RPi.GPIO as GPIO
from gpiozero import Button

import paho.mqtt.client as mqtt

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

mh = Raspi_MotorHAT(addr=0x6f)
myMotor = mh.getMotor(2)

pwm = PWM(0x6F)
pwm.setPWMFreq(60)
pwm.setPWM(0, 0, 375)


# 우
def right():
    GPIO.output(LED_RED, False)
    GPIO.output(LED_YEL, True)
    GPIO.output(LED_GRE, False)

    pwm.setPWMFreq(60)
    pwm.setPWM(0, 0, 425);


# 좌
def left():
    GPIO.output(LED_RED, False)
    GPIO.output(LED_YEL, False)
    GPIO.output(LED_GRE, True)

    pwm.setPWMFreq(60)
    pwm.setPWM(0, 0, 300);


# 직진
def straight():
    GPIO.output(LED_RED, False)
    GPIO.output(LED_YEL, True)
    GPIO.output(LED_GRE, True)
    pwm.setPWMFreq(60)  # 직
    pwm.setPWM(0, 0, 375);


### 1. 초음파센서 GPIO
LEFT_TRIG = 17
LEFT_ECHO = 18

RIGHT_TRIG = 22
RIGHT_ECHO = 27

BACK_TRIG = 26
BACK_ECHO = 21

print("초음파 거리 측정기")

GPIO.setup(LEFT_TRIG, GPIO.OUT)
GPIO.setup(LEFT_ECHO, GPIO.IN)
GPIO.setup(RIGHT_TRIG, GPIO.OUT)
GPIO.setup(RIGHT_ECHO, GPIO.IN)
GPIO.setup(BACK_TRIG, GPIO.OUT)
GPIO.setup(BACK_ECHO, GPIO.IN)
GPIO.output(LEFT_TRIG, False)
GPIO.output(RIGHT_TRIG, False)
GPIO.output(BACK_TRIG, False)
print("초음파 출력 초기화")

### 2. 충격감지센서 GPIO
COL = 14
GPIO.setup(COL, GPIO.IN)

### 3. 안전벨트
BELT_BTN = 24
BELT_LED = 23
GPIO.setup(BELT_BTN, GPIO.IN)
GPIO.setup(BELT_LED, GPIO.OUT)

### 4. LED 전광판
LED_RED = 10
LED_YEL = 9
LED_GRE = 11
GPIO.setup(LED_RED, GPIO.OUT)
GPIO.setup(LED_YEL, GPIO.OUT)
GPIO.setup(LED_GRE, GPIO.OUT)

GPIO.output(LED_RED, False)
GPIO.output(LED_GRE, False)
GPIO.output(LED_YEL, False)
GPIO.output(BELT_LED, False)



def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("connected OK")
    else:
        print("Bad connection Returned code=", rc)


def on_disconnect(client, userdata, flags, rc=0):
    print(str(rc))
    print('on_disconnect')


def on_subscribe(client, userdata, mid, granted_qos):
    print("start!")


def on_message(client, userdata, msg):
    msg_recevied = int(msg.payload.decode("utf-8"))
    print(msg_recevied)

    global dir
    global speed

    if msg_recevied == -1:  # 직진
        if dir != -1:
            dir = -1
            speed = 1
        else:
            speed += 1


    elif msg_recevied == 1:  # 후진
        if dir != 1:
            dir = 1
            speed = 1
        else:
            speed += 1


    elif msg_recevied == 0:  # 정지
        dir = 0
        speed = 0
    else:
        pwm.setPWMFreq(60)
        pwm.setPWM(0, 0, msg_recevied)

    if dir == 0:
        myMotor.setSpeed(0)
    else:
        myMotor.setSpeed(110)
        if dir == -1:
            myMotor.run(Raspi_MotorHAT.BACKWARD)
        else:
            myMotor.run(Raspi_MotorHAT.FORWARD)


dir = 0
speed = 0



client = mqtt.Client()
client.on_connect = on_connect
client.on_disconnect = on_disconnect
client.on_subscribe = on_subscribe
client.on_message = on_message
client.connect('localhost', 1883)
client.subscribe('mycar/step', 1)
client.loop_forever()



