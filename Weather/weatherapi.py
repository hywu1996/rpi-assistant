import sys
import requests
import json

url = "http://api.openweathermap.org/data/2.5/weather?q="

city = sys.argv[1]
APPID = "d43e3cb9fc1531411e1661d648996d0c"

url = url + city + "&APPID=" + APPID
res = requests.get(url)

json_data = res.json()

temp = json_data["main"]["temp"]
temp = temp - 273.15
temp = int(round(temp))
conditions = json_data["weather"][0]["main"]

file  = open("temp_results.txt", "w")

file.write(str(temp))
file.write("\n")
file.write(conditions)