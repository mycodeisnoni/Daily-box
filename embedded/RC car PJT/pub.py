from Raspi_PWM_Servo_Driver import PWM
from Raspi_MotorHAT import Raspi_MotorHAT, Raspi_DCMotor

import RPi.GPIO as GPIO
from gpiozero import Button
import time

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
GPIO.setup(COL,GPIO.IN)

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

time.sleep(2)

 
BELT_FLAG = 0
dir = 0
speed = 0

try:
    while True:
        client = mqtt.Client()
        client.connect('localhost', 1883)
        
        #### 안전벨트 감지 센서
        ## 벨트 토글 구현
        if GPIO.input(BELT_BTN) == False:
            if BELT_FLAG == 0:
                BELT_FLAG = 1
                GPIO.output(BELT_LED, True)
            else:
                BELT_FLAG = 0

        # 안켜진 경우 출발 x
        if BELT_FLAG == 0:
            print("좋은 말로 할 때, 안전벨트 하시죠?!^^!!")
            GPIO.output(LED_RED, True)
            GPIO.output(LED_GRE, False)
            GPIO.output(LED_YEL, False)
            GPIO.output(BELT_LED, False)
            time.sleep(1)
            client.publish('mycar/belt', 'false')
            client.publish('mycar/nobelt', "안전벨트 하시죠?!^^!!")
            client.publish('mycar/speedt', 'false')

        # 켜진 경우 출발 o
        if BELT_FLAG == 1:
            print("주행 시작~ 달려 숑숑~~")
            time.sleep(0.1)
            client.publish('mycar/belt', 'true')
            client.publish('mycar/speedt', 'true')

            ## 주행
            myMotor.setSpeed(speed)
            myMotor.run(Raspi_MotorHAT.BACKWARD)


            ### 1. 초음파센서 코드
            #전면 왼쪽
            GPIO.output(LEFT_TRIG, True)
            time.sleep(0.00001)  # 10uS의 펄스 발생을 위한 딜레이
            GPIO.output(LEFT_TRIG, False)

            while GPIO.input(LEFT_ECHO) == 0:
                LEFT_start = time.time()  # Echo핀 상승 시간값 저장

            while GPIO.input(LEFT_ECHO) == 1:
                LEFT_stop = time.time()  # Echo핀 하강 시간값 저장

            LEFT_check_time = LEFT_stop - LEFT_start
            LEFT_distance = LEFT_check_time * 34300 / 2
            if LEFT_distance > 30:
                LEFT_distance = 30

            print(" left Distance : %.1f cm" % LEFT_distance)
            #time.sleep(0.4)

            #전면 오른쪽
            GPIO.output(RIGHT_TRIG, True)
            time.sleep(0.00001)  # 10uS의 펄스 발생을 위한 딜레이
            GPIO.output(RIGHT_TRIG, False)

            while GPIO.input(RIGHT_ECHO) == 0:
                RIGHT_start = time.time()  # Echo핀 상승 시간값 저장

            while GPIO.input(RIGHT_ECHO) == 1:
                RIGHT_stop = time.time()  # Echo핀 하강 시간값 저장

            RIGHT_check_time = RIGHT_stop - RIGHT_start
            RIGHT_distance = RIGHT_check_time * 34300 / 2
            if RIGHT_distance > 30:
                RIGHT_distance = 30

            print(" right Distance : %.1f cm" % RIGHT_distance)
            time.sleep(0.1)

            # 후방
            GPIO.output(BACK_TRIG, True)
            time.sleep(0.00001)  # 10uS의 펄스 발생을 위한 딜레이
            GPIO.output(BACK_TRIG, False)

            while GPIO.input(BACK_ECHO) == 0:
                BACK_start = time.time()  # Echo핀 상승 시간값 저장

            while GPIO.input(BACK_ECHO) == 1:
                BACK_stop = time.time()  # Echo핀 하강 시간값 저장

            BACK_check_time = BACK_stop - BACK_start
            BACK_distance = BACK_check_time * 34300 / 2
            if BACK_distance > 30:
                BACK_distance = 30

            print(" back Distance : %.1f cm" % BACK_distance)
            time.sleep(0.1)


            ### 2. 충격감지센서 코드
            if GPIO.input(COL) == True:
                print("충돌 발생! 블랙박스 작동 요망! 정지하세용 ^.^")
                GPIO.output(LED_RED, True)
                #myMotor.setSpeed(0)
            else:
                print("이상 무! 정상 주행중~!")
                GPIO.output(LED_RED, False)
                time.sleep(0.1)

            ### 4. 바퀴 각도에 따른 LED 조정
            if LEFT_distance < RIGHT_distance:
                print("잠시후 우회전 예정입니다.")
                time.sleep(0.1)
                right()
            elif RIGHT_distance < LEFT_distance:
                print("잠시후 좌회전 예정입니다.")
                time.sleep(0.1)
                left()
            else:
                print("직진 중 입니다.")
                straight()
                time.sleep(1)




except KeyboardInterrupt:
    print("거리 측정 완료 ")
    myMotor.run(Raspi_MotorHAT.RELEASE)
    GPIO.cleanup()

client.loop_forever()

