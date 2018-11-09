import sys
import requests
import json

url = "http://api.openweathermap.org/data/2.5/weather?q="

city = sys.argv[1] #city name from shell argument
APPID = "d43e3cb9fc1531411e1661d648996d0c" #API key

url = url + city + "&APPID=" + APPID #API path
res = requests.get(url) # GET request

json_data = res.json() # JSON response

temp = json_data["main"]["temp"] #current temperature
temp = temp - 273.15 #convert to Celscius
temp = int(round(temp))
conditions = json_data["weather"][0]["main"] # get conditions

file  = open("temp_results.txt", "w") # write results to a temp file

file.write(str(temp)) # 1st line temp
file.write("\n")
file.write(conditions) # 2nd line conditions