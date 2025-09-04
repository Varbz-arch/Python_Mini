import time
import threading
import sys

stop_flag = False

def pomodoro(work_time=25, short_break=5, long_break=15, cycles=4):
    """
    Pomodoro Timer with stop option.
    Press 's' + Enter anytime to stop the timer.
    """
    global stop_flag
    stop_flag = False

    listener = threading.Thread(target=listen_stop)
    listener.daemon = True
    listener.start()

    for i in range(1, cycles + 1):
        if stop_flag: break
        print(f"\nPomodoro {i}: Work for {work_time} minutes!")
        countdown(work_time * 60)

        if stop_flag: break
        if i < cycles:
            print(f"\nTake a short {short_break}-minute break.")
            countdown(short_break * 60)
        else:
            print(f"\nGreat job! Take a long {long_break}-minute break.")
            countdown(long_break * 60)

    print("\nTimer stopped or finished.")


def countdown(seconds):
    global stop_flag
    while seconds and not stop_flag:
        mins, secs = divmod(seconds, 60)
        timer = f"{mins:02d}:{secs:02d}"
        print(timer, end="\r")
        time.sleep(1)
        seconds -= 1


def listen_stop():
    global stop_flag
    while True:
        cmd = input()
        if cmd.lower() == "s":
            stop_flag = True
            break


if __name__ == "__main__":
    print("Pomodoro Timer started. Press 's' + Enter anytime to stop.\n")
    pomodoro(work_time=1, short_break=1, long_break=2, cycles=2)  
