Pomodoro Timer in Python 
A terminal-based Pomodoro timer implemented in Python. It helps you manage your work and breaks using the Pomodoro technique. You can also stop the timer anytime by pressing s + Enter.
Features
Work timer (default 25 minutes)
Short break (default 5 minutes)
Long break after a set number of cycles (default 15 minutes)
Supports multiple cycles (default 4)
Stop the timer anytime with s + Enter
Terminal-based, lightweight, easy to run

Usage
# Import and call pomodoro
pomodoro(work_time=25, short_break=5, long_break=15, cycles=4)

work_time: Minutes for each focus session
short_break: Minutes for short break between sessions
long_break: Minutes for long break after all cycles
cycles: Number of Pomodoro cycles
Stop timer anytime by typing:
s
and pressing Enter.

Code Breakdown
import time
import threading
import sys

time: For countdown timer using sleep().
threading: To listen for stop input while timer runs.
sys: Optional, for advanced terminal operations.
stop_flag = False

Global variable to control when the timer should stop.

Pomodoro Function
def pomodoro(work_time=25, short_break=5, long_break=15, cycles=4):
    global stop_flag
    stop_flag = False
    
    listener = threading.Thread(target=listen_stop)
    listener.daemon = True
    listener.start()


Starts a separate thread that listens for user input to stop the timer.

daemon=True ensures the listener thread closes when the main program ends.

    for i in range(1, cycles + 1):
        if stop_flag: break
        print(f"\n🍅 Pomodoro {i}: Work for {work_time} minutes!")
        countdown(work_time * 60)


Runs the Pomodoro work session.
Converts minutes to seconds for countdown.
Checks if user stopped the timer.

        if stop_flag: break
        if i < cycles:
            print(f"\n⏳ Take a short {short_break}-minute break.")
            countdown(short_break * 60)
        else:
            print(f"\n🎉 Great job! Take a long {long_break}-minute break.")
            countdown(long_break * 60)


Handles short breaks between cycles.
Handles long break after final cycle.

Countdown Function
def countdown(seconds):
    global stop_flag
    while seconds and not stop_flag:
        mins, secs = divmod(seconds, 60)
        timer = f"{mins:02d}:{secs:02d}"
        print(timer, end="\r")
        time.sleep(1)
        seconds -= 1

Counts down seconds.
divmod(seconds, 60) converts total seconds to minutes:seconds.
end="\r" updates timer in-place in terminal.
Stops immediately if stop_flag becomes True.

Stop Listener Function
def listen_stop():
    global stop_flag
    while True:
        cmd = input()
        if cmd.lower() == "s":
            stop_flag = True
            break

Runs in parallel to listen for s input.
Sets stop_flag=True to stop the timer.

Main Section
if __name__ == "__main__":
    print("Pomodoro Timer started. Press 's' + Enter anytime to stop.\n")
    pomodoro(work_time=1, short_break=1, long_break=2, cycles=2)


Starts the program when run directly.
Short times used for testing; replace with standard 25, 5, 15 minutes for real use.

Output Example
Pomodoro Timer started. Press 's' + Enter anytime to stop.

Pomodoro 1: Work for 1 minutes!
00:59
00:58
...
 Take a short 1-minute break.
00:59
...
 Great job! Take a long 2-minute break.


Press s anytime to stop:
Timer stopped or finished.
