Weather App in Python
A simple Python program that fetches live weather information for any city using the OpenWeatherMap API.

Features
Enter a city name and get:
Temperature (°C)
Wind speed (m/s)
Weather condition (e.g., cloudy, sunny, rain)

Simple and easy-to-understand Python code
Requirements
Python 3.x installed
requests library (install using pip install requests)
OpenWeatherMap API key (free)

How to Run
Get your API key from OpenWeatherMap
Replace YOUR_REAL_API_KEY in the code with your API key.

Python Code
import requests
API_KEY = "YOUR_REAL_API_KEY"  # Replace with your OpenWeatherMap API key
city = input("Enter city name: ").strip()
url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={API_KEY}&units=metric"
response = requests.get(url)
data = response.json()
if response.status_code == 200:
    print(f"\nWeather in {city}:")
    print(f"Temperature: {data['main']['temp']}°C")
    print(f"Wind Speed: {data['wind']['speed']} m/s")
    print(f"Condition: {data['weather'][0]['description'].capitalize()}")
else:
    print("Error: Could not retrieve weather data. Check your city name or API key.")

Breakdown of Code (Simple Language)
Import requests library
import requests

Needed to make HTTP requests to the OpenWeatherMap API.
Set your API key
API_KEY = "YOUR_REAL_API_KEY"
Replace this with your own API key from OpenWeatherMap.
Get city input
city = input("Enter city name: ").strip()

Asks the user to type the city name.
strip() removes extra spaces.
Create the API URL
url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={API_KEY}&units=metric"

Combines the city name and API key into a URL to request weather data.
units=metric gives temperature in Celsius.
Send request to API
response = requests.get(url)
data = response.json()

Sends a request to OpenWeatherMap.
Converts the response into Python dictionary using .json().
Check if the response is valid
if response.status_code == 200:

200 means the request worked successfully.
If not, it prints an error message.

Print weather info
print(f"Temperature: {data['main']['temp']}°C")
print(f"Wind Speed: {data['wind']['speed']} m/s")
print(f"Condition: {data['weather'][0]['description'].capitalize()}")

Extracts temperature, wind speed, and condition from the API response.
capitalize() makes the weather description start with a capital letter.

Error Handling
else:
    print("Error: Could not retrieve weather data. Check your city name or API key.")
Prints a friendly message if city not found or API key is wrong.