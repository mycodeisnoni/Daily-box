import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

LEFT_TRIG = 22
LEFT_ECHO = 27

print("초음파 거리 측정기")

GPIO.setup(LEFT_TRIG, GPIO.OUT)
GPIO.setup(LEFT_ECHO, GPIO.IN)


GPIO.output(LEFT_TRIG, False)

print("초음파 출력 초기화")
time.sleep(2)

try:
    while True:
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

        print(" left Distance : %.1f cm" % LEFT_distance)
        time.sleep(0.4)


except KeyboardInterrupt:
    print("거리 측정 완료 ")
    GPIO.cleanup()
