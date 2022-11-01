import requests as re
from bs4 import  BeautifulSoup as bs
import pandas as pd


URL = "https://news.google.com/search?q=apple"
headers = {'User-Agent': "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.135 Safari/537.36 Edge/12.246"}
resp = re.get(url=URL, headers=headers)
soup = bs(resp.content)
soup2 = bs(resp.text, 'html.parser')

for title in soup2.find_all('title'):
    print(title.get_text())