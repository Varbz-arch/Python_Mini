import requests
API_KEY = "329af3b07c5c71d5dbbb8d1cd231cdaf"  # Replace with your OpenWeatherMap API key
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
