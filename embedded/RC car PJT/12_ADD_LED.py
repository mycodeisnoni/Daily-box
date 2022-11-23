import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)


### 1. 초음파센서 GPIO
LEFT_TRIG = 17
LEFT_ECHO = 18

RIGHT_TRIG = 22
RIGHT_ECHO = 27

print("초음파 거리 측정기")

GPIO.setup(LEFT_TRIG, GPIO.OUT)
GPIO.setup(LEFT_ECHO, GPIO.IN)
GPIO.setup(RIGHT_TRIG, GPIO.OUT)
GPIO.setup(RIGHT_ECHO, GPIO.IN)

GPIO.output(LEFT_TRIG, False)
GPIO.output(RIGHT_TRIG, False)
print("초음파 출력 초기화")

### 2. 충격감지센서 GPIO
COL = 14
GPIO.setup(COL,GPIO.IN)


### 4. LED 전광판
LED_RED = 10
LED_YEL = 9
LED_GRE = 11
GPIO.setup(LED_RED, GPIO.OUT)
GPIO.setup(LED_YEL, GPIO.OUT)
GPIO.setup(LED_GRE, GPIO.OUT)


time.sleep(2)


try:
    while True:

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
        if LEFT_distance > 50:
            LEFT_distance = 50

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
        if RIGHT_distance > 50:
            RIGHT_distance = 50

        print(" right Distance : %.1f cm" % RIGHT_distance)
        time.sleep(0.4)


        ### 2. 충격감지센서 코드
        if GPIO.input(COL) == False:
            print("충돌 발생! 블랙박스 작동 요망! 정지하세용 ^.^")
            time.sleep(1)
        else:
            print("이상 무! 정상 주행중~!")
            time.sleep(1)

        ### 3. 안전벨트 감지 센서


        ### 4. 바퀴 각도에 따른 LED 조정
        if LEFT_distance < RIGHT_distance:
            GPIO.output(LED_YEL,True)
            print("잠시후 우회전 예정입니다.")
            time.sleep(0.5)
            print("지금 우회전!")
            GPIO.output(LED_YEL,False)

        if RIGHT_distance < LEFT_distance:
            GPIO.output(LED_GRE,True)
            print("잠시후 좌회전 예정입니다.")
            time.sleep(0.5)
            print("지금 좌회전!")
            GPIO.output(LED_GRE, False)



except KeyboardInterrupt:
    print("거리 측정 완료 ")
    GPIO.cleanup()
