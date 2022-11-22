
# print("장애물 인식 Start")
#
# GPIO.setmode(GPIO.BCM)
# # 전면 왼쪽 초음파센서
# GPIO.setup(17, GPIO.OUT)    #trig
# GPIO.setup(18, GPIO.IN)     #echo
# # 전면 오른쪽 초음파센서
# GPIO.setup(22, GPIO.OUT)    #trig
# GPIO.setup(27, GPIO.IN)     #echo
#
# def dist(trig, echo):
#
#     global srt, end
#
#     GPIO.output(trig, False)
#     time.sleep(0.5)
#     GPIO.output(trig, True)
#     time.sleep(0.00001)
#     GPIO.output(trig, False)
#
#     while GPIO.input(echo) == 0:
#         srt = time.time()
#     while GPIO.input(echo) == 1:
#         end = time.time()
#
#     interval = end - srt
#     distance = interval * 17000
#     distance = round(distance, 2)
#     if distance > 50:
#         distance = 50
#
#
# while True :
#     left_dist = dist(22,27)
#     right_dist = dist(17,18)
#
#     print("물체는 왼쪽에서는 {} cm , 오른쪽에서는 {} cm 떨어져있습니다.".format(left_dist, right_dist))
#
#
# # except KeyboardInterrupt:
# #     GPIO.cleanup()
# #     print("장애물 인식 프로세스 End")


import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

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

except KeyboardInterrupt:
    print("거리 측정 완료 ")
    GPIO.cleanup()
